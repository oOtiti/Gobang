#ifndef __Photo__H
#define __Photo__H
// #pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Photo{
private:
    int Photo_num;        //照片编号
    std :: string Path;     //照片路径
    int set0;                   //默认图片
    int tot;                     //总照片数
    std :: vector<std :: string> Path_arr; //照片数组
    sf ::Texture cur;
               
public:
    Photo(int _Photo_num=0, std :: string _Path=" ",int _set0=0, int _tot=0, std :: vector<std :: string >_Path_arr=std :: vector<std :: string>()); ;
    void open_photo(); //打开背景
    void close_photo(); //关闭背景
    void last();               //上一个背景
    void next();              //下一个背景
    void push_photo(const std :: string&);  //添加图片
    void pop_photo();   //删除最后一张照片
    void chage_to( const int&);     //切换到背景
    const std :: string& get_path (const int&) const;
};
#endif