# include "Utils.hpp"
# include <string>

bool intersects(const Vec &a, const Vec &b, const Vec &c, const Vec &d) {
    Vec line(b.x()-a.x(), b.y()-a.y());
    Vec s1(c.x()-a.x(), c.y()-a.y());
    Vec s2(d.x()-a.x(), d.y()-a.y());

    float cc = line.cross(s1);
    float cd = line.cross(s2);
    if (cc > cd) std::swap(cc, cd);
    if (!(cc < EPSILON && cd > -EPSILON)) return false;

    const bool withinA = line.dot(s1.normalized()) + line.dot(s2.normalized()) > 0;

    Vec lineBackwards(a.x()-b.x(), a.y()-b.y());
    Vec s3(c.x()-b.x(), c.y()-b.y());
    Vec s4(d.x()-b.x(), d.y()-b.y());

    const bool withinB = lineBackwards.dot(s3.normalized()) + lineBackwards.dot(s4.normalized()) > 0;

    return withinA && withinB;
}

std::string padTo(std::string str, const size_t num, const char paddingChar) {
    if(num > str.size())
        str.insert(0, num - str.size(), paddingChar);
    return str;
}

sf::Font drawFont;
void loadFont() {
    if (!drawFont.loadFromFile("resources/arial.ttf"))
    {
        std::cout << "failed to load fnt" << std::endl;
        exit(1);
    }
}

void unloadFont() {
    drawFont.~Font();
}

void drawText(sf::RenderWindow &window, const std::string &text, float x, float y, unsigned int size, const sf::Color &color) {
    sf::Text sfText;
    sfText.setFont(drawFont);
    sfText.setString(text);
    sfText.setFillColor(color);
    sfText.setCharacterSize(size);
    sfText.setPosition(x, y);
    window.draw(sfText);
}