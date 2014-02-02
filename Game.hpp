#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        ~Game();
        int run();
        void quit();

    private:
        void createWindow();
        sf::RenderWindow window;
        bool running;
        int lives;
};

#endif
