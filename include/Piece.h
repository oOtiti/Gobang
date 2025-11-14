#ifndef __Piece__H
#define __Piece__H
// #pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>

class Piece{
private:
    int x,y,id;                            //位置，步序
    bool highlight;                        //是否为高光(未实现)
    sf :: Color color;                     //颜色
    sf :: CircleShape shape;               //圆点
    
public :
    Piece(sf::Color _c=sf::Color::White,int _x=0, int _y=0,int _id=0, bool _h=0, sf::CircleShape _s= sf::CircleShape(10.f));
    void set_key();                         //设置为高光
    void unset_key();                       //取消高光
    const int& get_x() const;               //x
    const int& get_y() const;               //y
    const sf::Color& get_color() const;        //颜色
    const sf :: CircleShape& get_shape() const;
};
#endif