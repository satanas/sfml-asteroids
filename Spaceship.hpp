#ifndef _SPACESHIP_HPP_
#define _SPACESHIP_HPP_

#include <math.h>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Spaceship: public sf::Drawable, public sf::Transformable {
    static const float acceleration;
    static const float max_speed;
    static const float rotation_speed;

    public:
        Spaceship();
        ~Spaceship();

        void reset();
        void update(float frametime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void onEvent(const sf::Event& event);

    private:
        sf::Vector2f speed;
        sf::ConvexShape shape;
        int h_move, v_move;
};
#endif
