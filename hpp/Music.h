#ifndef __Music__H
#define __Music__H
#pragma once
#include <string>
class Music{
private:
    std :: string Path;             //音乐路径
    int Music_num;              //音乐编号
    bool status;                   //音乐状态
    int set0;                         //默认音乐
public:
    Music (std :: string _Path=" ", int _Music_num=0, bool _status=0);
    void turn_on();               //打开音乐
    void turn_off();              //关闭音乐
    void last();                     //切换上一首
    void next();                   //切换下一首
    void change_to();         //切换到index编号音乐
};
#endif