#ifndef _Button__H
#define _Button__H
// #pragma once
#include <string>
#include <SFMl/Graphics.hpp>
#include <SFMl/Window.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>

class Button {
private :
    sf :: RectangleShape shape; //载体
    sf :: Color color; //颜色
    sf :: Font font;   //字体
    sf :: Text text;   //文字
    bool onbutton;     //状态
    bool clickbutton;   

public:
    Button(float _x, float _y, float _w, float _h,std ::string, sf::Color _col,std ::string  _f);
    void update ();
    void set_font (const std :: string&);
    void set_text (const std :: string&);
    const std:: string show_text () const;
    const sf::RectangleShape& get_shape () const;
    const sf::Text& get_text () const;
    bool isMouseOver(const sf::RenderWindow& window);
    bool handleEvent(const std::optional<sf::Event>& event, const sf::RenderWindow& window);
};
#endif