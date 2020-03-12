#include <SFML/Graphics.hpp>
#include <iostream> 
#include <vector>
using namespace sf;


int main()
{
    RenderWindow window(sf::VideoMode(640, 480), "My window");

    Texture herotexture;
    herotexture.loadFromFile("hero.png");

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(0, 192, 96, 96));

    Clock clock;

    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time / 900; //скорость игры

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { herosprite.move(-0.1 * time, 0); herosprite.setTextureRect(IntRect(0, 96, 96, 96)); } //-0,1 это скорость, умножаем её на наше время и получаем пройденное расстояние
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) { herosprite.move(0.1 * time, 0); herosprite.setTextureRect(IntRect(0, 192, 96, 96)); } // см коммент выше
        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) { herosprite.move(0, -0.1 * time); herosprite.setTextureRect(IntRect(0, 288, 96, 96)); }// см выше
        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { herosprite.move(0, 0.1 * time); herosprite.setTextureRect(IntRect(0, 0, 96, 96)); }// см выше
        window.clear(sf::Color::White);
        
        
        window.draw(herosprite);          
        window.display();
    }

    return 0;
}
