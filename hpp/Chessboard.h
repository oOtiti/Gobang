#ifndef __Chessboard__H
#define __Chessboard__H
class Chessboard {
private:
    int width,height;   //宽高
    bool status;          //棋盘状态  
public:
    Chessboard(int _width=100, int _height=100 ,bool _status=0);
    void init(int width,int height) ;//初始化
    void ban();                              //封盘
    void unban();                          //开盘
};
#endif