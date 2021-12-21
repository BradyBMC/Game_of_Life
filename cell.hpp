#ifndef CELL_HPP
#define CELL_HPP
#include <iostream>

using namespace std;

class cell {
    private:
        bool alive;
        pair<int,int> coord;
    public:
        cell(); //wo this line had no default constructor error?
        cell(int,int,bool);
        bool isAlive();
        void kill();
        void born();
};

#endif