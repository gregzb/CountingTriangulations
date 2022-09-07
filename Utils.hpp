# pragma once
# include <algorithm>
# include <iostream>
# include <vector>
# include "Vec.hpp"

# include <optional>
# include <SFML/Graphics.hpp>

constexpr float EPSILON = 0.000001f;

bool intersects(const Vec &a, const Vec &b, const Vec &c, const Vec &d);
std::string padTo(std::string str, const size_t num, const char paddingChar = ' ');

template <class T>
void printGrid(const std::vector<std::vector<T>> &diagonals) {
    std::cout << padTo("", 2) << " ";
    for (size_t j = 0; j < diagonals[0].size(); j++) {
        std::cout << padTo(std::to_string(j), 2) << " ";
    }
    std::cout << "\n";
    for (size_t i = 0; i < diagonals.size(); i++) {
        std::cout << padTo(std::to_string(i), 2) << " ";
        for (size_t j = 0; j < diagonals[0].size(); j++) {
            std::cout << padTo(std::to_string(diagonals[i][j]), 2) << " ";
        }
        std::cout << "\n";
    }
}

void loadFont();
void unloadFont();
void drawText(sf::RenderWindow &window, const std::string &text, float x, float y, unsigned int size, const sf::Color &color);