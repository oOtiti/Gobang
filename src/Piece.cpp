#include "Piece.h"

Piece :: Piece (sf::Color _c , int _x , int _y, int _id, bool _h, sf::CircleShape _s) 
    : color(_c) , x(_x) ,y(_y) , id(_id) ,highlight(_h), shape(_s) {
        this->shape.setFillColor(_c);
        this->shape.setPosition(sf::Vector2f((float)_x,(float)_y));
    };

void Piece :: set_key () {
    if(this->highlight) return;
    this -> highlight =1;
}

void Piece :: unset_key () {
    if(!(this->highlight)) return;
    this -> highlight=0;
}

const int& Piece :: get_x () const {
    return this->x;
}

const int& Piece :: get_y () const {
    return this->y;
}

const sf :: Color& Piece :: get_color () const {
    return this->color;
}

const sf :: CircleShape& Piece :: get_shape () const {
    return  this->shape;
}
