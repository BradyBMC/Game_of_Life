#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "cell.hpp"

class graph {
    private:
        pair<int,int> dimension;
        cell **g;
    public:
        graph(int,int);
        void play();
        cell** cpy();
        bool detect(int,int);
        bool bordercheck(int,int);
        ~graph();
};

#endif