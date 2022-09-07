# pragma once

# include <SFML/Graphics.hpp>
# include <vector>
# include "Point.hpp"

class Polygon {
    std::vector<Point> m_points;
    bool m_closed;

    public:
    Polygon() : m_closed(false) {

    }

    Polygon(const std::vector<Point> &points_) : m_points(points_), m_closed(false) {

    }

    Polygon(const std::vector<Point> &points_, bool closed_) : m_points(points_), m_closed(closed_) {

    }

    inline const std::vector<Point> &getPoints() const {
        return m_points;
    }

    inline void addPoint(const Point &p) {
        m_points.push_back(p);
    }

    inline bool closed() const {
        return m_closed;
    }

    inline size_t size() const {
        return m_points.size();
    }

    void setClosed(bool closed_) {
        m_closed = closed_;
    }

    void draw(sf::RenderWindow &window) const;
    bool containsPoint(Vec p) const;
};