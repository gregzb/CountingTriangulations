# include "Polygon.hpp"
# include <algorithm>
# include <limits>
# include "Utils.hpp"

#include <iostream>

void Polygon::draw(sf::RenderWindow &window) const {
    if (m_points.empty()) return;
    for (size_t i = 0; i < m_points.size(); i++) {
        const auto& point = m_points[i];
        point.draw(window);

        drawText(window, std::to_string(i), point.x(), point.y(), 18, sf::Color::Black);
    }
    size_t upto = m_closed ? (m_points.size() + 1) : (m_points.size());
    sf::VertexArray lines(sf::LineStrip, upto);
    for (size_t i = 0; i < upto; i++) {
        lines[i].position.x = m_points[i%m_points.size()].x();
        lines[i].position.y = m_points[i%m_points.size()].y();
        lines[i].color = sf::Color(40, 40, 40);
    }
    window.draw(lines);
}

bool Polygon::containsPoint(Vec p) const {
    float min_x = std::min_element(m_points.begin(), m_points.end(), [](const auto &a, const auto &b){
        return a.x() < b.x();
    })->x();
    min_x = std::nextafter(min_x, -std::numeric_limits<float>::min());

    Vec a = {min_x, p.y()};
    Vec b = p;

    int cnt_intersections = 0;
    for (size_t i = 0; i < m_points.size(); i++) {
        size_t ni = (i+1)%m_points.size();
        cnt_intersections += intersects(a, b, m_points[i], m_points[ni]);
    }
    return cnt_intersections % 2 == 1;
}