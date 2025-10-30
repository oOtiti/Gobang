#ifndef __Music__H
#define __Music__H
// #pragma once
#include <string>
#include <map> 
#include <vector>
class Music{
private:
    std :: string name;                                 //音乐别名
    std :: string Path;                                   //音乐路径
    int Music_num;                                     //音乐编号
    bool status;                                           //音乐状态
    int set0;                                                 //默认音乐
    bool loop;                                             //循环
    std :: vector<std ::string> Path_arr;      //存路径
    int tot;                                                  //总歌曲数
public:
    Music (std :: string _name="RAP" ,std :: string _Path=" ", int _Music_num=0, bool _status=0, int _set0=0,bool _loop=false,
    std ::vector<std :: string> _Path_arr ,int _tot);
    void put_music(const std :: string& path); //添加音乐
    void show();                    //展示现在的音乐
    void turn_on();               //打开音乐
    void turn_off();              //关闭音乐
    void last();                     //切换上一首
    void next();                   //切换下一首
    void change_to();         //切换到index编号音乐
    void make_loop();        //循环
};
#endif