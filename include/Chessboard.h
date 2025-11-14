#ifndef __Chessboard__H
#define __Chessboard__H
// #pragma once
#include <vector>
#include "Piece.h"


class Chessboard {
private:
    int width,height;                               //宽高
    bool status;                                    //棋盘状态  
    int step;                                       //下过步数
    std :: vector <Piece> pieces;                   //放的棋子
    std :: vector<std :: vector<int>> board;        //棋盘
  
public:
    Chessboard(int _width=100, int _height=100 ,int _step=0, bool _status=0, std :: vector<std :: vector<int>> _board=std :: vector<std :: vector<int>>(10,std ::vector<int>()), std :: vector<Piece> _pieces=std ::vector<Piece>());
    void ban();                                                     //封盘
    void unban();                                                   //开盘
    void inplace(const Piece&);                                     //放棋子  
    const int& get_step() const;                                    //获取
    void init(const int&,const int&);                               //初始化
    const bool had_piece(const Piece&) const;                       //有棋子            
    const bool check_xy (const Piece&) const;                       //判越界
    const bool check_win(const Piece&) const;                       //判胜利
    const std :: vector<Piece>& get_Pieces () const;                //获取棋子
    
};
#endif