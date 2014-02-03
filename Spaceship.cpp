#include "Spaceship.hpp"

const float Spaceship::acceleration = 1.0f;
const float Spaceship::max_speed = 2.0f;
const float Spaceship::rotation_speed = 0.3f;

Spaceship::Spaceship() {
    shape.setPointCount( 3 );
    shape.setPoint(0, sf::Vector2f(10.0f, 0.0f));
    shape.setPoint(1, sf::Vector2f(-10.0f, 7.5f));
    shape.setPoint(2, sf::Vector2f(-10.0f, -7.5f));

    shape.setFillColor(sf::Color(0, 0, 0, 0));
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setPosition(0.0f, 0.0f);

    h_move = 0;
    v_move = 0;

    reset();
}

Spaceship::~Spaceship() {
}

void Spaceship::reset() {
    setPosition(APP_WIDTH / 2, APP_HEIGHT / 2);
    setRotation(0.0f);
    speed.x = 0.0f;
    speed.y = 0.0f;
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape, states);
}

void Spaceship::update(float frametime) {
    if (h_move != 0) {
        rotate(h_move * rotation_speed * frametime);
    }

    if (v_move != 0) {
        float rotation = getRotation();
        float x_speed = cos(rotation * DEG2RAD);
        float y_speed = sin(rotation * DEG2RAD);

        speed.x += v_move * acceleration * frametime * x_speed / 1000;
        speed.y += v_move * acceleration * frametime * y_speed / 1000;
        if ((speed.x * speed.x) > (max_speed * max_speed))
            speed.x = speed.x > 0 ? max_speed : -max_speed;
        if ((speed.y * speed.y) > (max_speed * max_speed))
            speed.y = speed.y > 0 ? max_speed : -max_speed;
    }
    move(speed);

    sf::Vector2f position = getPosition();

    if (position.x < -10.0f)
        position.x = APP_WIDTH;
    else if (position.x > APP_WIDTH)
        position.x = 0.0f;

    if (position.y < -10.0f)
        position.y = APP_HEIGHT;
    else if (position.y > APP_HEIGHT)
        position.y = 0.0f;
    setPosition(position);
}

void Spaceship::onEvent(const sf::Event& event) {
    h_move = 0;
    v_move = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        v_move = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        h_move = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        v_move = -1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        h_move = -1;
}
