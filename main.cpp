#include "Game.hpp"

int main(int, char const**) {
    srand(time(NULL));

    Game game;
    game.run();
    return EXIT_SUCCESS;
}
