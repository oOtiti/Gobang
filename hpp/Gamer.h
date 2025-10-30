#ifndef __Gamer__H
#define __Gamer__H
// #pragma once
#include <string>
class Gamer{
    std :: string name,ID;  //姓名，玩家ID
    int rank,done_num;    //段位，已经下过步数
    std :: string belongto;         //阵营
public:
    Gamer(std :: string _name="Tim", std :: string _ID=0, int _rank=0, int _done_num=0, std :: string _belongto="W") ;
    void login();//登录
    void logout();//退出
    void change();//改变阵营
};
#endif