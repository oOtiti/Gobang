#include "Chessboard.h"
#include <iostream>


Chessboard :: Chessboard(int _width, int _height, int _step,bool _status, std ::vector<std :: vector<int>> _board, std ::vector<Piece> _pieces) 
    : width(_width) , height(_height) ,step(_step), status(_status) ,board(_board), pieces(_pieces) {};

void Chessboard :: init (const int& w,const int& h) {
    std :: cout << "new game w ,h " << w <<' '<<h<<std :: endl;
    this -> height=h;
    this -> width =w;
    this -> step=0;
    this -> pieces.clear();
    this -> board=std :: vector<std :: vector<int>> (h,std :: vector<int> (w,0)); 
}

void  Chessboard :: ban () {
    this->status=0;
}

void Chessboard :: unban () {
    this->status=1;
}

bool Chessboard :: check_xy (const Piece& piece) const{
    int x=piece.get_x();
    int y=piece.get_y();

    if(x<0 || x>this->height || y<0 || y>this->width) return false;
    return true;
}

bool Chessboard :: check_win (const Piece& piece) const {
    int x=piece.get_x();
    int y=piece.get_y();
    std :: string color=piece.get_color();
   
    //y 
    int cnt=1;
    for(int i=y+1;i<this->width;i++)
    {
        if(!board[x][i] || this->pieces[board[x][i]].get_color() !=color) {break;}
        cnt++;
    }
    for(int i=y-1;i>=0;i--)
    {
        if(!board[x][i] || this->pieces[board[x][i]].get_color() !=color) {break;}
        cnt++;
    }
    if(cnt>=5) return true;

    //x
    cnt=1;
    for(int i=x+1;i<this->height;i++)
    {
        if(!board[i][y] || this->pieces[board[i][y]].get_color() !=color) {break;}
        cnt++;
    }
    for(int i=x-1;i>=0;i--)
    {
        if(!board[i][y] || this->pieces[board[i][y]].get_color() !=color) {break;}
        cnt++;
    }
    if(cnt>=5) return true;

    //left up
    cnt=1;
    int nx=x-1,ny=y-1;
    while(nx>=0&&ny>=0&&!board[nx][ny])
    {
        if(this->pieces[board[nx][ny]].get_color()!=color) break;
        cnt++;
        nx--;ny--;
    }
    nx=x+1,ny=y+1;
    while(nx<this->height&& ny<this->width&&!board[nx][ny])
    {
        if(this->pieces[board[nx][ny]].get_color()!=color) break;
        cnt++;
        nx++;ny++;
    }
    if(cnt>=5) return true;

    //right up
    cnt=1;
    nx=x-1,ny=y+1;
    while(nx>=0&&ny<this->width&&!board[nx][ny])
    {
        if(this->pieces[board[nx][ny]].get_color()!=color) break;
        cnt++;
        nx--;ny++;
    }
    nx=x+1,ny=y-1;
    while(nx<this->height&&ny>=0&&!board[nx][ny])
    {
        if(this->pieces[board[nx][ny]].get_color()!=color) break;
        cnt++;
        nx++;ny--;
    }
    if(cnt>=5) return true;

    return false;
}

void Chessboard :: inplace (const Piece& piece) {
    int x=piece.get_x();
    int y=piece.get_y();

    if(this ->check_xy(piece))
    {
        this ->step++;
        this ->board[x][y] =step;
        this ->pieces.push_back(piece);
    }
    else 
        std :: cout<< "OUT OF BOARD!"<<std ::endl;
}
