#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

#include "Bullet.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include <SFML/Graphics.hpp>

class Level {
    public:
        Level();
        ~Level();
        void onEvent(const sf::Event& event);
        void update(float frametime);
        void show(sf::RenderTarget& target);
        void start();

    private:
        Spaceship ship;
        std::vector<Bullet> bullets;
        std::vector<Asteroid> asteroids;
};

#endif
