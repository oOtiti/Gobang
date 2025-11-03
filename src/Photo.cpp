#include "Photo.h"

Photo :: Photo(int _Photo_num,std :: string _Path ,bool _status , int _set0, int _tot, std :: vector<std :: string> _Path_arr)
    : Photo_num(_Photo_num) , Path(_Path) , status(_status) ,set0(_set0) ,tot(_tot) ,Path_arr(_Path_arr) {};

void Photo :: open_photo () {

}

void Photo :: close_photo () {

}

void Photo :: last () {

}

void Photo :: next () {

}

void Photo :: push_photo (std :: string& path) {
    this->tot++;
    this->Path_arr.push_back(path);
} 

void Photo :: pop_photo () {
    this->tot--;
    this->Path_arr.pop_back();
} 

void Photo :: chage_to (const std :: string& path , const int& to) {

}
