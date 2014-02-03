#include "Bullet.hpp"

const float Bullet::lifetime = 1000.0f;
const float Bullet::speed = 0.9f;

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

    sf::Vector2f distance = direction * speed * frametime;
    move(distance);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Vertex line[] = {
        sf::Vertex(getPosition()),
        sf::Vertex(getPosition() + (direction * 5.0f))
    };
    target.draw(line, 2, sf::Lines, states);
}

void Bullet::kill() {
    is_alive = false;
}
