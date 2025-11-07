#include "Photo.h"
#include <iostream>

Photo :: Photo(int _Photo_num,std :: string _Path  , int _set0, int _tot, std :: vector<std :: string> _Path_arr)
    : Photo_num(_Photo_num) , Path(_Path) ,set0(_set0) ,tot(_tot) ,Path_arr(_Path_arr) {};

void Photo :: open_photo () {
    if(!this->cur.loadFromFile(this->Path))
    {
        std :: cout<<"ERROR,Phtot MISTAKE!"<< std ::endl;
        return ;
    }
}

void Photo :: close_photo () {
    this->Photo_num=this->set0;
    this->Path=this->Path_arr[this->set0];
    this->open_photo();
}

const std :: string& Photo :: get_path (const int& to) const {
    if(to<0 ||to>=this->Path_arr.size())
    {
        std ::cout <<"ERROR PHTOT MISTAKE!"<< std :: endl;
        return this->Path;
    }
    return this->Path_arr[to];

}

void Photo :: last () {
    if(this->Photo_num==0)
    {
        std ::cout <<"ERROR PHTOT MISTAKE!"<< std :: endl;
        return ;
    }
    this->Path=this->Path_arr[this->Photo_num-1];
    Photo_num--;
    this->open_photo();
}

void Photo :: next () {
    if(this->Photo_num+1==this->Path_arr.size())
    {
        std ::cout <<"ERROR PHTOT MISTAKE!"<< std :: endl;
        return ;
    }
    this->Path=this->Path_arr[this->Photo_num+1];
    Photo_num++;
    this->open_photo();
}

void Photo :: push_photo (const std :: string& path) {
    this->tot++;
    this->Path_arr.push_back(path);
} 

void Photo :: pop_photo () {
    this->tot--;
    this->Path_arr.pop_back();
} 

void Photo :: chage_to (const int& to) {
    if(to<0 ||to>=this->Path_arr.size())
    {
        std ::cout <<"ERROR PHTOT MISTAKE!"<< std :: endl;
        return ;
    }
    this->Path=this->Path_arr[to];
    this->Photo_num=to;
    this->open_photo();
}
