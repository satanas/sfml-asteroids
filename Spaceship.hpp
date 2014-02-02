#ifndef _SPACESHIP_HPP_
#define _SPACESHIP_HPP_

#include <math.h>
#include <SFML/Graphics.hpp>

const float acceleration = 0.5f;
const float max_speed = 2.0f;
const float rotation_speed = 0.3f;
const float deg2rad = (3.14159f / 180.0f);

class Spaceship: public sf::Drawable, public sf::Transformable {
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
