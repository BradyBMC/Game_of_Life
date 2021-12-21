#include "graph.hpp"

graph :: graph(int x,int y) {
    dimension.first = x, dimension.second = y;
    cell map[x][y];
    g = new cell* [x];
    for(int i = 0;i < x;++i) {
        g[i] = new cell[y];
    }
}

void graph :: play() {
    
}

graph :: ~graph() {
    delete []g;
}