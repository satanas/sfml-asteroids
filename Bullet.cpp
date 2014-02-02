#include "Bullet.hpp"

const float Bullet::lifetime = 4000.0f;
const float Bullet::speed = 1.0f;

Bullet::Bullet(sf::Vector2f position, float angle):
    is_alive(true),
    remaining_life(lifetime),
    direction(cos(angle * DEG2RAD), sin(angle * DEG2RAD)) {
    setPosition(position);
}

Bullet::~Bullet() {
}

bool Bullet::isAlive() {
    return is_alive;
}

void Bullet::update(float frametime) {
    if (!is_alive) return;

    remaining_life -= frametime;
    if (remaining_life <= 0) is_alive = false;
    //printf("life: %f\n", remaining_life);
    //fflush(stdout);

    sf::Vector2f distance = direction * speed * frametime;
    move(distance);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    //states.transform *= getTransform();
    sf::Vertex point(getPosition(), sf::Color::White);
    target.draw(&point, 1, sf::Points, states);
}
