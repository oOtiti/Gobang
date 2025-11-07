#include <iostream>
#include "Gamer.h"
#include "Music.h"
#include "Photo.h"
#include "Piece.h"
#include <vector>
#include <functional>
#include "Chessboard.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
using namespace sf;
using namespace std;
Music music;
Photo photo;
Chessboard chessboard;
int main(void) {
    std::cout << "Welcome to Gobang Game!" << std::endl;
    std::cout <<"Now,The Board is 1000*800"<< std::endl;
    sf::RenderWindow window(sf::VideoMode({1000, 800}), "My window");
    window.setFramerateLimit(60); 

    
    Texture photo("./T1.jpg");

    sf::RectangleShape Board({800.f, 800.f});
    Board.setPosition({0,0});
    Board.setTexture(&photo);

    sf::RectangleShape Gamerboard({200.f,400.f});
    Gamerboard.setPosition({800.f,0.f});
    Gamerboard.setFillColor(Color::White);


    sf::VertexArray ys(sf::PrimitiveType::Lines,4*8);
    sf::VertexArray xs(sf::PrimitiveType::Lines,4*8);
    std:: function<void()> setlines=[&]()->void
    {
        float x1=0.0,y1=0.0;
        float x2=800.0,y2=0.0;
        for(int i=0;i<=4*8-1;i+=2)
        {
            ys[i].position=sf:: Vector2f(x1,y1);
            ys[i+1].position=sf:: Vector2f(x2,y2);
            y1+=50,y2+=50;
        }
        x1=0.0,y1=0.0;
        x2=0.0,y2=800.0;
        for(int i=0;i<=4*8-1;i+=2)
        {
            xs[i].position=sf:: Vector2f(x1,y1);
            xs[i+1].position=sf:: Vector2f(x2,y2);
            x1+=50,x2+=50;
        }
    };
    setlines();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            int x = mousePos.x;
            int y = mousePos.y;
            cout<<x<<' '<<y<<endl;
        }
        window.clear(Color::Black);
        window.draw(Board);
        window.draw(Gamerboard);
        window.draw(ys);
        window.draw(xs);

        window.display();
    }


    return 0;
}