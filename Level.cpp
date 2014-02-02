#include "Level.hpp"

Level::Level() {
}

Level::~Level() {
}

void Level::onEvent(const sf::Event& event) {
    ship.onEvent(event);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Bullet bullet(ship.getPosition(), ship.getRotation());
        bullets.push_back(bullet);
    }
}

void Level::update(float frametime) {
    ship.update(frametime);
    std::vector<Bullet>::iterator start = bullets.begin();
    while (start != bullets.end()) {
        if (start->isAlive()) {
            start->update(frametime);
            ++start;
        } else
            start = bullets.erase(start);
    }
}

void Level::show(sf::RenderTarget& target) {
    target.draw(ship);

    for(std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        target.draw(*it);
    }
}

void Level::start() {
}
