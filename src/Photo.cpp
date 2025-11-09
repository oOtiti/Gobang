#include "Photo.h"
#include <iostream>

Photo :: Photo(int _Photo_num,std :: string _Path  , int _set0, int _tot, std :: vector<std :: string> _Path_arr ,bool _status)
    : Photo_num(_Photo_num) , Path(_Path) ,set0(_set0) ,tot(_tot) ,Path_arr(_Path_arr) ,status(_status) {};

void Photo :: open_photo () {
    if(!this->cur.loadFromFile(this->Path))
    {
        std :: cout<<"ERROR,Phtot MISTAKE!"<< std ::endl;
        return;
    }
    this->status=1;
}

void Photo :: close_photo () {
    this->Photo_num=this->set0;
    this->Path=this->Path_arr[this->set0];
    this->open_photo();
    this->status=0;
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

void Photo :: change_set0 (const int& to) {
    if(to<0 || to>=this->Path_arr.size()) {std :: cout<<"ERROR PHTOT MISTAKE!"<<std :: endl;return;}
    this->set0=to;
}

void Photo :: push_photo (const std :: string& path) {
    this->tot++;
    this->Path_arr.push_back(path);
} 

void Photo :: pop_photo () {
    this->tot--;
    this->Path_arr.pop_back();
} 

void Photo :: change_to (const int& to) {
    if(to<0 ||to>=this->Path_arr.size())
    {
        std ::cout <<"ERROR PHTOT MISTAKE!"<< std :: endl;
        return ;
    }
    this->Path=this->Path_arr[to];
    this->Photo_num=to;
    this->open_photo();
}

void Photo :: show () const {
    if(this->Path_arr.empty()) {std :: cout << "NO PHOTO!"<<std :: endl; }
    else
    {
        std :: cout<<"---------------------PHOTO TABLE---------------------" << std :: endl;
        for(int i=0; i<(*this).tot; i++)
            std :: cout << i+1<< ". is "<< (*this).Path_arr[i]<<std :: endl;
    }
    std :: cout<< "Photo now is"<<((*this).status?"open":"close")<< std ::endl;
    std :: cout<< "set0 is"<<(*this).set0 <<std ::endl;
    if((*this).status) std :: cout<<"Now is playing" << (*this).Photo_num<<std ::endl;
}

const sf :: Texture& Photo :: get_Texture () const {
    return this->cur;
}