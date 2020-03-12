#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Charge
{
    sf::Vector2i pos;
    int value;
    sf::CircleShape circle;
};

static vector<Charge> charges;
static vector<sf::VertexArray> lines;


float Len(const sf::Vector2i& v)
{
    return float(sqrt(v.x * v.x + v.y * v.y));
}

sf::Vector2f Norm(const sf::Vector2i& v)
{
    return { v.x / Len(v), v.y / Len(v) };
}

void PutCharge(sf::Vector2i localPosition, int value)
{
    sf::CircleShape circle(5);
    circle.setPosition(localPosition.x, localPosition.y);
    sf::Color color = (value == 1) ? sf::Color::Red : sf::Color::Blue;
    circle.setFillColor(color);
    charges.push_back({ localPosition, value, circle });
}

sf::Vector2f CalculateTension(sf::Vector2i point)
{
    sf::Vector2f res(0, 0);
    for (Charge charge : charges)
    {
        sf::Vector2i r(point.x - charge.pos.x, point.y - charge.pos.y);
        res += Norm(r) * (charge.value / (Len(r) * Len(r)));
    }
    while ((abs(res.x) < 10) && (abs(res.y) < 10))
    {
        res = res * 2.f;
    }
    return res;
}

bool CheckDisplayBounds(sf::Vector2i point)
{
    return (point.x <= 800) && (point.y <= 600) && (point.x >= 0) && (point.y >= 0);
}

void DrawLine(sf::Vector2i point)
{
    vector<sf::Vector2i> linePoints;
    linePoints.push_back(point);
    sf::Vector2i nextPoint = point;
    sf::Vector2f tensionVector;
    while (1)
    {
        tensionVector = CalculateTension(nextPoint);
        nextPoint = { int(nextPoint.x + tensionVector.x), int(nextPoint.y + tensionVector.y) };
        if (CheckDisplayBounds(nextPoint))
            linePoints.push_back(nextPoint);
        else
            break;
    }
    sf::VertexArray line = sf::VertexArray(sf::LinesStrip, linePoints.size());
    for (size_t i = 0, count = line.getVertexCount(); i < count; ++i) {
        line[i].position.x = linePoints[i].x;
        line[i].position.y = linePoints[i].y;
        line[i].color = sf::Color::Black;
    }
    lines.push_back(line);

}

void SetCharges(sf::Event event, sf::Vector2i localPosition)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
          
            PutCharge(localPosition, 1);

    }
}

void DrawLinesMode(sf::Event event, sf::Vector2i localPosition)
{
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            DrawLine(localPosition);
        }
}

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Tension Lines");



    int flag = 0; // 0 - set charges, 1 - draw lines

    while (window.isOpen()) {

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                flag = 1;
            }

            window.clear(sf::Color::White);

            if (!flag)
                SetCharges(event, localPosition);
            else
                DrawLinesMode(event, localPosition);

            for (const auto& i : charges)
            {
                window.draw(i.circle);
            }

        

            for (const auto& line : lines)
            {
                window.draw(line);
            }
            window.display();
        }
    }
    return 0;
}