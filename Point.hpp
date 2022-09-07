# pragma once

# include <SFML/Graphics.hpp>

# include "Vec.hpp"

class Point : public Vec {
    using Vec::Vec;
    public:
    // float m_x, m_y;

    // public:
    // Point(float x_, float y_) : m_x(x_), m_y(y_) {

    // }

    // inline float x() const {
    //     return m_x;
    // }

    // inline float y() const {
    //     return m_y;
    // }

    void draw(sf::RenderWindow &window) const;
};