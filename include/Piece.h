#ifndef __Piece__H
#define __Piece__H
// #pragma once
#include <string>
class Piece{
private:
    std ::  string  color;            //颜色
    int x,y,id;                           //位置，步序
    bool highlight;                 //是否为高光
    
public :
    Piece(std :: string _c="W",int _x=0, int _y=0,int _id=0, bool _h=0);
    void set_key();                 //设置为高光
    void unset_key();             //取消高光
    int get_x() const;              //x
    int get_y() const;              //y
    std :: string get_color() const;//颜色
};
#endif