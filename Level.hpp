#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

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
};

#endif
