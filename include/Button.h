#ifndef _Button__H
#define _Button__H
// #pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>

class Button {
private :
    bool onbutton;              //悬停
    sf :: Font font;            //字体
    sf :: Text text;            //文字
    bool clickbutton;           //点击  
    sf :: Color color;          //颜色 
    sf :: RectangleShape shape; //载体

public:
    Button(float _x, float _y, float _w, float _h,std ::string, sf::Color _col,std ::string  _f);
    void update ();                                                                 //更新状态
    const sf::Text& get_text () const;                                              //获取文本
    void set_font (const std :: string&);                                           //设置字体
    void set_text (const std :: string&);                                           //设置文本
    const std:: string show_text () const;                                          //展示文本
    bool isMouseOver(const sf::RenderWindow&);                                      //鼠标移动
    const sf::RectangleShape& get_shape () const;                                   //获取外形
    bool handleEvent(const std::optional<sf::Event>&, const sf::RenderWindow&);     //判断状态
};
#endif