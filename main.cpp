#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "Point.hpp"
#include "Polygon.hpp"
#include "CountTriangulations.hpp"
#include "Utils.hpp"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const char * WINDOW_TITLE = "Counting Triangulations";

const int VERTEX_SIZE = 10;

int main(int argc, char **argv)
{
    Polygon polygon;
    polygon.setClosed(true);
    if (argc > 1) {
        std::ifstream ifs(argv[1]);
        std::vector<float> coords;
        float coord;
        while (ifs >> coord) {
            coords.push_back(coord);
        }
        for (int i = 0; i < coords.size(); i += 2) {
            polygon.addPoint({coords[i], coords[i+1]});
        }
    }

    loadFont();
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    int64_t numTriangulations = countTriangulations(polygon);

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                unloadFont();
                return 0;
                break;
            case sf::Event::MouseButtonPressed:
                {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        polygon.addPoint({(float)mousePos.x, (float)mousePos.y});
                        numTriangulations = countTriangulations(polygon);
                    }
                }
                break;
            case sf::Event::KeyPressed:
                {
                    if (event.key.code == sf::Keyboard::R) {
                        polygon = Polygon();
                        polygon.setClosed(true);
                        numTriangulations = 0;
                    }
                }
                break;
            default:
                break;
            }
        }
        window.clear(sf::Color(255, 255, 255));

        polygon.draw(window);

        drawText(window, std::to_string(numTriangulations) + " triangulations", 10, 10, 30, sf::Color::Black);
        drawText(window, "Left Click to place a point", 10, WINDOW_HEIGHT - 70 - 10, 30, sf::Color::Black);
        drawText(window, "Press R to reset", 10, WINDOW_HEIGHT - 30 - 10, 30, sf::Color::Black);

        window.display();
    }

    return 0;
}