#ifndef __Piece__H
#define __Piece__H
#include <string>
class Piece{
private:
    std ::  string  color;              //颜色
    int x,y,id;                           //位置，步序
    bool highlight;                  //是否为高光
public :
    Piece(std :: string _c="W",int _x=0, int _y=0,int _id=0, bool _h=0);
    void inplace();                     //放置
    bool check_xy() const;        //是否越界
    bool check_win()const;       //是否导致胜局
    bool& set_key();                 //设置为高光
    bool& unset_key();             //取消高光
};
#endif