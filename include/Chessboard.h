#ifndef __Chessboard__H
#define __Chessboard__H
// #pragma once
#include <vector>
#include "Piece.h"


class Chessboard {
private:
    int width,height;   //宽高
    bool status;          //棋盘状态  
    int step;                //下过步数
    std :: vector <Piece> pieces;                   //放的棋子
    std :: vector<std :: vector<int>> board; //棋盘
  
public:
    Chessboard(int _width=100, int _height=100 ,int _step=0, bool _status=0, std :: vector<std :: vector<int>> _board=std :: vector<std :: vector<int>>(10,std ::vector<int>()), std :: vector<Piece> _pieces=std ::vector<Piece>());
    void ban();                              //封盘
    void unban();                          //开盘
    void init(const int& width,const int& height) ;              //初始化
    void inplace(const Piece& piece) ;                       //放置棋子         
    bool check_xy (const Piece& piece) const;         //判越界
    bool check_win(const Piece& piece) const;        //判胜利
    
};
#endif