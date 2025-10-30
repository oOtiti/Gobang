#include "Music.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")

Music :: Music(std :: string _name ,std ::string _Path ,int _Music_num, bool _status, int _set0, bool _loop,
std :: vector <std ::string> _Path_arr , int _tot ,int _cur)
    :name(_name), Path(_Path) , Music_num(_Music_num) , status(_status), set0(_set0), loop(_loop) ,Path_arr(_Path_arr), tot(_tot), cur(_cur){ };

void Music :: turn_on ( const std :: string& path ,const int& to) {
    std::string openCmd = "open \"" + path + "\" alias " + this->name;
    std::string playCmd = "play " + this->name;
    MCIERROR err=mciSendStringA(openCmd.c_str(),NULL, 0 ,NULL);
    if(err) {std ::cout<<"open path error!"<<std :: endl;return;}
    this->cur=to;
    this->status=true;
    mciSendStringA(playCmd.c_str(),NULL ,0,NULL);
}

void Music :: turn_off () {
    std::string pauseCmd = "pause " + this->name;
    mciSendStringA(pauseCmd.c_str(),NULL ,0,NULL);
}

void Music :: last () {
    int need=((*this).cur-1+(*this).tot)%(*this).tot;
    this->turn_on(this->Path_arr[need],need);
}

void Music :: next () {
    int need=((*this).cur+1)%(*this).tot;
    this->turn_on(this->Path_arr[need],need);
}

void Music :: change_to (const int& to) {
    if(to<0||to>this->tot){std :: cout<< "ERROR : NO MUSIC!"<<std ::endl;}
    this->turn_on(this->Path_arr[to],to);
}

void Music :: change_set0 (const int& num) {
    if(num>tot||num<0) {std ::cout<< "ERROR : NO MUSIC!"<< std ::endl;return;}
    (*this).set0 =num;
}

void Music :: push_music (const std :: string& path) {
    (*this).Path_arr.push_back(path);
    (*this).tot++;
    std :: cout<<"OK, has update a music !"<<std :: endl;
}

void Music :: pop_music () {
    if((*this).Path_arr.empty()) {std :: cout << "ERROR : NO MUSIC!"<<std :: endl;return;}
    (*this).Path_arr.pop_back();
    (*this).tot--;
}
void Music :: show () const {
    if((*this).Path_arr.empty()){std :: cout << "NO MUSCI!"<<std :: endl; }
    else
    {
            std :: cout<<"---------------------MUSIC TABLE---------------------" << std :: endl;
        for(int i=0; i<=(*this).tot; i++)
            std :: cout << i+1<< ". is "<< (*this).Path_arr[i]<<std :: endl;
    }
    std :: cout<< "music now is"<<((*this).status?"open":"close")<< std ::endl;
    std :: cout<< "set0 is"<<(*this).set0 <<std ::endl;
    if((*this).status) std :: cout<<"Now is playing" << (*this).name<<std ::endl;
} 