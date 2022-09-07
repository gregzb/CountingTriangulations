# include "Point.hpp"

constexpr float CIRCLE_RADIUS = 5.0f;

void Point::draw(sf::RenderWindow &window) const {
    sf::CircleShape circle(CIRCLE_RADIUS);
    circle.setFillColor(sf::Color(64, 180, 64));
    circle.setPosition(x() - CIRCLE_RADIUS, y() - CIRCLE_RADIUS);
    window.draw(circle);
}