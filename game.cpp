#include<bits/stdc++.h>
using namespace std;
#define ll std:: long long

class Music{
    string Path;           //音乐路径
    int Music_num;    //音乐编号
    bool status;         //音乐状态
public:
    Music (string _Path, int _Music_num, bool _status): Path(_Path), Music_num(_Music_num), status(_status){};

     void turn_on(){//打开音乐

    }
    void turn_off(){//关闭音乐

    }
    void last(){//切换上一首

    }
    void next(){//切换下一首

    }
    void change_to(){//切换到index编号音乐

    }
};
class Photo{
    int Photo_num;      //照片编号
    string Path;            //照片路径
    bool status;            //照片状态
public:
    Photo(int _Photo_num, string _Path, bool _status) :Photo_num(_Photo_num), Path(_Path), status(_status) {};
    void open_photo(){//打开背景

    }
    void close_photo(){//关闭背景

    }
    void last(){//上一个背景

    }
    void next(){//下一个背景

    }
    void chage_to(){//切换到背景

    }

};
class Chessboard   : Photo{
    int width,height;   //宽高
    int Photo_num;    //图片编号
    string Path;          //图片地址
    bool status;         //棋盘状态  
public:
    Chessboard(int _width, int _height, int _Photo_num, string  _Path ,bool _status) :width(_width), height(_height), Photo_num(_Photo_num), Path(_Path), status(_status) {};
    void init(int width,int height){//初始化

    }
    void ban(){//封盘

    }
    void unban(){//开盘

    }

};

class Piece{
    std ::  string  color;             //颜色
    int x,y,id;               //位置，步序
    bool highlight;     //是否为高光
public :
    Piece(string _c,int _x, int _y,int _id, bool _h) : color(_c),x(_x),y(_y),id(_id),highlight(_h) {};
        
};

class Gamer{
    std :: string name,ID;  //姓名，玩家ID
    int rank,done_num;    //段位，已经下过步数
public:
    Gamer(string _name, string _ID, int _rank, int _done_num) : name(_name), ID(_ID) ,rank(_rank), done_num(_done_num) {};
};

int main()
{
    
    return 0;
}