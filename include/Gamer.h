#ifndef __Gamer__H
#define __Gamer__H
// #pragma once
#include <string>
#include <vector>
#include <map>

class Gamer{
private:
    int tot;                                                     //总在线玩家
    std :: vector<int> rank;                           //分数
    std :: vector<int> step;                           //步数
    std :: vector<std :: string> name;           //玩家名字列表
    std :: vector<std :: string> color;            //玩家对应颜色
    std :: map<std :: string, int>table;          //对应颜色表

public:
    Gamer(int _tot, std :: vector<int> _rank=std ::vector<int>(), std :: vector<int> _step=std :: vector<int>(),  std :: vector<std :: string> _name=std ::vector<std :: string >() ,std :: vector<std :: string> _color=std ::vector<std ::string >(),
    std :: map<std :: string, int> _table=std :: map<std :: string, int>());
    void login();                     //登录
    void logout();                  //退出
    const int& get_tot() const;          //总数
    void change(const int&);//改变颜色
    const bool check(const std :: string&) const;          //检查是否有颜色
};
#endif