#include <iostream>
#include "Gamer.h"
#include "Music.h"
#include "Photo.h"
#include "Piece.h"
#include "Button.h"
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
Button Gamer1(800,0,500,100,"Gamer1 name :",sf::Color::White,"./arial.ttf"),Gamer2(800,225,500,100,"Gamer2 name :",sf::Color::White,"./arial.ttf");
Button Rank1(800,100,500,50,"0",sf::Color::White,"./arial.ttf"),Rank2(800,175,500,50,"0",sf::Color::White,"./arial.ttf");
int main(void) {
    cout << "Welcome to Gobang Game!" << endl;
    cout <<"Now,The Board is 1300*800 60Hz!"<< endl;
    //实例化窗口，刷新率60hz
    RenderWindow window(VideoMode({1300, 800}), "My window");
    window.setFramerateLimit(60); 
    
    Texture photo("./T1.jpg");

    RectangleShape Board({800.f, 800.f});
    Board.setPosition({0,0});
    Board.setTexture(&photo);
    
    //侧栏
    RectangleShape SecBoard({500.f,800.f});
    SecBoard.setPosition({800.f,0.f});
    SecBoard.setFillColor(Color::White);


    //棋盘的框架按照800*800制作
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


    music.push_music("./test0.mp3");
    music.show();
    string music_path=music.get_Path(0);
    cout<<music_path<<endl;
    music.turn_on(music_path,0);

    //窗口的展示
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }
        if (Mouse::isButtonPressed(Mouse::Button::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            int x = mousePos.x;
            int y = mousePos.y;
            // cout<<x<<' '<<y<<endl;
        }
        window.clear(Color::Black);
        window.draw(Board);
        window.draw(SecBoard);
        window.draw(ys);
        window.draw(xs);
        function<void()> Gamers=[&]()->void
        {
            window.draw(Gamer1.get_shape());
            window.draw(Gamer1.get_text());
            window.draw(Rank1.get_shape());
            window.draw(Rank1.get_text());
            window.draw(Gamer2.get_shape());
            window.draw(Gamer2.get_text());
            window.draw(Rank2.get_shape());
            window.draw(Rank2.get_text());
        };
        Gamers();



        window.display();
    }
    music.turn_off();
    return 0;
}