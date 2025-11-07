#include "Button.h"
#include <iostream>

Button :: Button(float _x,float _y, float _w, float _h,std :: string _s,sf ::Color _col,std :: string _f) 
    :  color(_col),font(_f),text(sf::Text(this->font)){
        this->shape.setPosition(sf :: Vector2f({_x,_y}));
        this->shape.setSize (sf :: Vector2f({_w,_h}));
        this->text.setFont(font);
        this->shape.setFillColor(color);
        this->text.setString(_s);
        this->text.setPosition(sf :: Vector2f{_x,_y});
        this->text.setFillColor(sf :: Color :: Black);
        this->onbutton=0;
        this->clickbutton=0;
    };

void Button :: update () {
    if(clickbutton)
    {
        this->shape.setFillColor(sf :: Color :: Red);
    }
    else if(onbutton)
    {
        this->shape.setFillColor(sf :: Color :: Blue);
    }
    else
    {
        this->shape.setFillColor(sf :: Color ::White);
    }
    onbutton=0;
    clickbutton=0;
}

void Button :: set_font (const std :: string& fonts) {
    sf :: Font f;
    if (!font.openFromFile(fonts)){
        std ::cout<<"ERROR!YOUR FONT FALSE!"<<std:: endl;
        return ;
    }
    this->text.setFont(f);
}

void Button :: set_text (const std :: string& texts) {
    this->text.setString(texts);
}

const std :: string Button :: show_text () const {
    return this->text.getString();
}

const sf::RectangleShape& Button :: get_shape () const {
    return this->shape;
}

const sf::Text& Button :: get_text () const {
    return this->text;
}