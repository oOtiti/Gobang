#include "Gamer.h"
#include <iostream>

Gamer:: Gamer (int _tot, std :: vector<int> _rank, std :: vector<int> _step, std :: vector<std :: string> _name ,std :: vector<std :: string> _color,
std :: map<std :: string, int> _table)
    : tot(_tot), rank (_rank) , step(_step), name(_name) ,color(_color) ,table(_table) {};

const int& Gamer :: get_tot () const {
    return this ->tot;
}
void Gamer :: login () {
    this -> tot++;
    std :: string tmp;
    std :: cout<<"input your name :"<<std :: endl;
    std :: cin>>tmp;
    this->name.push_back(tmp);
    this->rank.push_back(0);
    this->step.push_back(0);
    std :: cout<<"input your color:"<<std :: endl;
    std :: cin>>tmp;
    while(this->check(tmp))
    {
        std :: cout<<"Color already esixt! try again!"<< std :: endl;
        std :: cin>>tmp;
    }
    this->table[tmp]=this->get_tot();
    this ->color.push_back(tmp);
    std :: cout<<"-----------------Welcome to Gobang!-----------------"<< std :: endl;
}

void Gamer :: logout () {
    std :: cout << "-----------------QUIT Gobang!-----------------" <<std ::endl;
}

void Gamer :: change (const int& id) {
    std :: string tmp;
    std :: cout<<"input your color:"<<std :: endl;
    std :: cin>>tmp;
    while(this->check(tmp))
    {
        std :: cout<<"Color already esixt! try again!"<< std :: endl;
        std :: cin>>tmp;
    }
    this->table.erase(color[id]);
    this->table[tmp]=id;
    this->color[id]=tmp;
}

const bool Gamer :: check(const std :: string& cur) const{
    if(this->table.count(cur))
        return true;
    return false;
}