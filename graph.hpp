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
        ~graph();

};

#endif