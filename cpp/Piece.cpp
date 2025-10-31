#include "Piece.h"

Piece :: Piece (std ::string _c , int _x , int _y, int _id, bool _h) : color(_c) , x(_x) ,y(_y) , id(_id) ,highlight(_h) {};

void Piece :: set_key () {
    if(this->highlight) return;
    this -> highlight =1;
}

void Piece :: unset_key () {
    if(!(this->highlight)) return;
    this -> highlight=0;
}

int Piece :: get_x () const {
    
    return (*this).x;
}

int Piece :: get_y () const {
    return (*this).y;
}

std ::string Piece:: get_color () const {
    return (*this).color;
}
