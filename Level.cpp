#include "Level.hpp"

Level::Level() {
}

Level::~Level() {
}

void Level::onEvent(const sf::Event& event) {
    ship.onEvent(event);
    if (event.type == sf::Event::KeyPressed) {
    }
}

void Level::update(float frametime) {
    ship.update(frametime);
}

void Level::show(sf::RenderTarget& target) {
    target.draw(ship);
}

void Level::start() {
}
