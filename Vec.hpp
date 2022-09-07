# pragma once

# include <cmath>

class Vec {
    float m_x, m_y;

    public:
    Vec(float x_, float y_) : m_x(x_), m_y(y_) {

    }

    inline float cross(const Vec &other) const {
        return m_x * other.m_y - m_y * other.m_x;
    }

    inline float dot(const Vec &other) const {
        return m_x * other.m_x + m_y * other.m_y;
    }

    inline Vec operator+(const Vec &other) const {
        return {m_x + other.m_x, m_y + other.m_y};
    }

    inline Vec operator-(const Vec &other) const {
        return {m_x - other.m_x, m_y - other.m_y};
    }

    inline Vec operator*(float other) const {
        return {m_x * other, m_y * other};
    }

    inline Vec operator/(float other) const {
        return {m_x / other, m_y / other};
    }

    inline Vec operator-() const {
        return {-m_x, -m_y};
    }

    inline float magnitude_sqr() const {
        return dot(*this);
    }

    inline float magnitude() const {
        return std::sqrt(magnitude_sqr());
    }

    inline Vec normalized() const {
        float mag = magnitude();
        return {m_x / mag, m_y / mag};
    }

    inline float x() const {
        return m_x;
    }

    inline float y() const {
        return m_y;
    }
};