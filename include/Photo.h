#ifndef __Photo__H
#define __Photo__H
// #pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Photo{
private:
    int set0;                               //默认图片
    int tot;                                //总照片数
    int Photo_num;                          //照片编号
    bool status;                            //照片状态
    sf ::Texture cur;                       //纹理绑定
    std :: string Path;                     //照片路径
    std :: vector<std :: string> Path_arr;  //照片数组
               
public:
    Photo(int _Photo_num=0, std :: string _Path="./T1.jpg",int _set0=0, int _tot=0, std :: vector<std :: string >_Path_arr=std :: vector<std :: string>(), bool _status=false);

    void last();                                        //上一个背景
    void next();                                        //下一个背景
    void pop_photo();                                   //删除尾照片
    void open_photo();                                  //打开背景
    void close_photo();                                 //关闭背景
    void show () const;                                 //展示照片
    void change_to(const int&);                         //切换背景
    void change_set0(const int&);                       //改变默认
    void push_photo(const std :: string&);              //添加图片
    const sf :: Texture& get_Texture() const;           //获得纹理
    const std :: string& get_path(const int&) const;    //获得路径
};
#endif