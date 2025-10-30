#include "Music.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

Music :: Music(std :: string _name ,std ::string _Path ,int _Music_num, bool _status, int _set0, bool _loop,
std :: vector <std ::string> _Path_arr , int _tot)
    :name(_name), Path(_Path) , Music_num(_Music_num) , status(_status), set0(_set0), loop(_loop) ,Path_arr(_Path_arr), tot(_tot){ };

void Music :: turn_off () {

}

void Music :: turn_on () {

}

void Music :: last () {

}

void Music :: next () {

}

void Music :: change_to () {

}

void put_music(const std :: string& path){
    
}