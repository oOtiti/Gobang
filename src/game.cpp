#include <iostream>
#include "Gamer.h"
#include "Music.h"
#include "Photo.h"
#include "Piece.h"
#include <vector>
#include "Button.h"
#include <functional>
#include "Chessboard.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
using namespace sf;
using namespace std;
int opt,popt,mopt,win;
Music music;
Photo photo;
Chessboard chessboard;
Button Gamer1(800,0,500,100,"Gamer1 name :",sf::Color::White,"./arial.ttf"),Gamer2(800,225,500,100,"Gamer2 name :",sf::Color::White,"./arial.ttf");
Button Rank1(800,100,500,50,"Rank:0",sf::Color::White,"./arial.ttf"),Rank2(800,175,500,50,"Rank:0",sf::Color::White,"./arial.ttf");
Button winboard(200,200,400,400,"WIN",sf::Color::White,"./arial.ttf");
void menu_print()
{
    cout << "Welcome to Gobang Game!" << endl;
    cout << "What do you want to do?" << endl;
    cout << "-----------------------" << endl;
    cout << "---------1.Game--------" << endl;
    cout << "---------2.Phtot-------" << endl;
    cout << "---------3.Music-------" << endl;
    cout << "-----------------------" << endl;
}
void Photo_print()
{
    cout << "-----------------------" << endl;
    cout << "---------1.open--------" << endl;
    cout << "---------2.close-------" << endl;
    cout << "---------3.last--------" << endl;
    cout << "---------4.next--------" << endl;
    cout << "---------5.show--------" << endl;
    cout << "---------6.change_to---" << endl;
    cout << "---------7.push--------" << endl;
    cout << "---------8.pop---------" << endl;
    cout << "---------9.change_set0-" << endl;
    cout << "---------10.quit-------" << endl;
    cout << "-----------------------" << endl;
}
void Music_print()
{
    cout << "-----------------------" << endl;
    cout << "---------1.open--------" << endl;
    cout << "---------2.close-------" << endl;
    cout << "---------3.last--------" << endl;
    cout << "---------4.next--------" << endl;
    cout << "---------5.show--------" << endl;
    cout << "---------6.change_to---" << endl;
    cout << "---------7.push--------" << endl;
    cout << "---------8.pop---------" << endl;
    cout << "---------9.change_set0-" << endl;
    cout << "---------10.quit-------" << endl;
    cout << "-----------------------" << endl;
}
void Error_output()
{
    cout << "NO Selection! Try again!" << endl;
}
void Psetting (const int& popt)
{
    switch (popt){
        case 1:{
            photo.open_photo();
            break;
        }
        case 2:{
            photo.close_photo();
            break;
        }
        case 3:{
            photo.last();
            break;
        }
        case 4:{
            photo.next();
            break;
        }
        case 5:{
            photo.show();
            break;
        }
        case 6:{
            cout<<"input your photo id!"<<endl;
            int o;cin>>o;
            photo.change_to(o-1);
            break;
        }
        case 7:{
            cout<<"input your photo path!"<<endl;
            string o;cin>>o;
            photo.push_photo(o);
            break;
        }    
        case 8:{
            photo.pop_photo();
            break;
        }       
        case 9:{
            cout<<"input your photo id!"<<endl;
            int o;cin>>o;
            photo.change_set0(o-1);
            break;
        }       
        case 10:{
            return;
            break;
        }       
        default:{
            Error_output();
            break;
        }    
    }
}
void Msetting (const int& mopt)
{
    switch (mopt){
        case 1:{
            cout<<"input your photo id!"<<endl;
            int o;cin>>o;
            music.turn_on(o-1);
            break;
        }
        case 2:{
            music.turn_off();
            break;
        }
        case 3:{
           music.last();
            break;
        }
        case 4:{
            music.next();
            break;
        }
        case 5:{
            music.show();
            break;
        }
        case 6:{
            cout<<"input your photo id!"<<endl;
            int o;cin>>o;
            music.change_to(o-1);
            break;
        }
        case 7:{
            cout<<"input your photo path!"<<endl;
            string o;cin>>o;
            music.push_music(o);
            break;
        }    
        case 8:{
            music.pop_music();
            break;
        }       
        case 9:{
            cout<<"input your photo id!"<<endl;
            int o;cin>>o;
            music.change_set0(o-1);
            break;
        }              
        case 10:{
            return;
            break;
        }
        default:{
            Error_output();
            break;
        }    
    }
}
int main(void) {
    do
    {
        menu_print();
        cin>>opt;
        switch (opt){
            case 1:{
                goto Game_start;
                break;
            }
            case 2:{
                do
                {
                    Photo_print();
                    cin>>popt;
                    Psetting(popt);
                }while(popt!=10);
                break;
            }
            case 3:{
                do
                {
                    Music_print();
                    cin>>mopt;
                    Msetting(mopt);
                }while (mopt!=10);
                break;
            }
            default:{
                Error_output();
                break;
            }
        }
    } while(opt!=1);

    Game_start:;
    chessboard.init(50,50);
    //实例化窗口，刷新率60hz
    RenderWindow window(VideoMode({1300, 800}), "My window");
    window.setFramerateLimit(60); 
    
    //棋盘
    RectangleShape Board({800.f, 800.f});
    Board.setPosition({0,0});
    Board.setTexture(&photo.get_Texture());
    Board.setFillColor(Color::Blue);
    
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


    function<void()> Gamers_draw=[&]()->void
    {
        window.draw(Gamer1.get_shape());
        window.draw(Gamer1.get_text());
        window.draw(Rank1.get_shape());
        window.draw(Rank1.get_text());
        window.draw(Gamer2.get_shape());
        window.draw(Gamer2.get_text());
        window.draw(Rank2.get_shape());
        window.draw(Rank2.get_text());
        if(win)
        {
            window.draw(winboard.get_shape());
            window.draw(winboard.get_text());
        }
    };
    function<pair<int,int>(Vector2f)> make_min=[&](Vector2f pos)->pair<int,int>
    {
        int x=0,y=0;
        int posx=(int)pos.x;
        int posy=(int)pos.y;
        int mid=posx/50; x=mid;
        if(posx-mid*50>=25) x++;
        mid=posy/50; y=mid;
        if(posy-mid*50>=25) y++;
        return make_pair(x,y);
    };
    function<void()> Piece_draw=[&]()->void
    {
        vector<Piece> tmp=chessboard.get_Pieces();
        for(auto i : tmp) window.draw(i.get_shape());
    };
    //窗口的展示
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if(Gamer1.handleEvent(event,window))
                Gamer1.update();
            if(Gamer2.handleEvent(event,window))
                Gamer2.update();
            if(event->is<Event::MouseMoved>())
            {
                if(event->getIf<Event::MouseButtonReleased>()->button==Mouse::Button::Left)
                {
                    Vector2f mousepos= window.mapPixelToCoords(Mouse::getPosition(window));
                    if(Board.getGlobalBounds().contains(mousepos))
                    {
                        auto pp=make_min(mousepos);
                        cout<<pp.first<<' '<<pp.second<<endl;
                        Color color =sf::Color::Black;
                        if(chessboard.get_step()&1) color=sf::Color::White;
                        Piece mid (color,pp.first*50,pp.second*50,chessboard.get_step(),0);
                        if(chessboard.check_xy(mid)&&!chessboard.had_piece(mid))
                        {   cout<<100000<<endl;chessboard.inplace(mid),chessboard.add_step();}
                        if(chessboard.check_win(mid))
                            win=true;
                    }
                }
  
            }
            if (event->is<Event::Closed>())
                window.close();
        }
        Gamer1.update();
        Gamer2.update();
        window.clear(Color::Black);
        window.draw(Board);
        window.draw(SecBoard);
        window.draw(ys);
        window.draw(xs);
        Gamers_draw();
        Piece_draw();
        window.display();
    }
    music.turn_off();
    return 0;
}