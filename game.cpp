#include<bits/stdc++.h>
using namespace std;
#define ll std:: long long

class Music{
    string Path;           //����·��
    int Music_num;    //���ֱ��
    bool status;         //����״̬
public:
    Music (string _Path, int _Music_num, bool _status): Path(_Path), Music_num(_Music_num), status(_status){};

     void turn_on(){//������

    }
    void turn_off(){//�ر�����

    }
    void last(){//�л���һ��

    }
    void next(){//�л���һ��

    }
    void change_to(){//�л���index�������

    }
};
class Photo{
    int Photo_num;      //��Ƭ���
    string Path;            //��Ƭ·��
    bool status;            //��Ƭ״̬
public:
    Photo(int _Photo_num, string _Path, bool _status) :Photo_num(_Photo_num), Path(_Path), status(_status) {};
    void open_photo(){//�򿪱���

    }
    void close_photo(){//�رձ���

    }
    void last(){//��һ������

    }
    void next(){//��һ������

    }
    void chage_to(){//�л�������

    }

};
class Chessboard {
    int width,height;   //���
    bool status;         //����״̬  
public:
    Chessboard(int _width, int _height ,bool _status) :width(_width), height(_height), status(_status) {};
    void init(int width,int height){//��ʼ��

    }
    void ban(){//����

    }
    void unban(){//����

    }
};

class Piece{
    std ::  string  color;             //��ɫ
    int x,y,id;               //λ�ã�����
    bool highlight;     //�Ƿ�Ϊ�߹�
public :
    Piece(string _c,int _x, int _y,int _id, bool _h) : color(_c),x(_x),y(_y),id(_id),highlight(_h) {};
    void inplace(){//����

    }
    bool check_xy(){//�Ƿ�Խ��

    }
    bool check_win(){//�Ƿ���ʤ��

    }
    bool set_key(){//����Ϊ�߹�

    }
    bool unset_key(){//ȡ���߹�

    }

};

class Gamer{
    std :: string name,ID;  //���������ID
    int rank,done_num;    //��λ���Ѿ��¹�����
    string belongto;         //��Ӫ
public:
    Gamer(string _name, string _ID, int _rank, int _done_num, string _belongto) : name(_name), ID(_ID) ,rank(_rank), done_num(_done_num), belongto(_belongto) {};
    void login(){//��¼

    }
    void logout(){//�˳�

    }
    void change(){//�ı���Ӫ

    }
};

int main()
{
    
    return 0;
}