#include "Asteroid.hpp"

const float Asteroid::speed[3] = {0.03f, 0.05f, 0.07f};
const float Asteroid::radius[3] = {40.0f, 20.0f, 10.0f};

Asteroid::Asteroid(int level):
    is_alive(true),
    level(level) {
    int angle = rand() % 360;
    sf::Vector2f v(cos(angle * DEG2RAD), sin(angle * DEG2RAD));
    direction = v;

    int x = rand() % APP_WIDTH;
    int y = rand() % APP_HEIGHT;
    sf::Vector2f position(x, y);
    setPosition(position);
    shape.setPointCount(8);
    shape.setRadius(radius[level]);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setOrigin(radius[level], radius[level]);
}

Asteroid::~Asteroid() {
}

bool Asteroid::isAlive() {
    return is_alive;
}

void Asteroid::update(float frametime) {
    if (!is_alive) return;

    sf::Vector2f distance = direction * speed[level] * frametime;
    move(distance);

    sf::Vector2f position = getPosition();

    if (position.x < -radius[level])
        position.x = APP_WIDTH;
    else if (position.x > APP_WIDTH)
        position.x = 0.0f;

    if (position.y < -radius[level])
        position.y = APP_HEIGHT;
    else if (position.y > APP_HEIGHT)
        position.y = 0.0f;
    setPosition(position);
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape, states);
}
