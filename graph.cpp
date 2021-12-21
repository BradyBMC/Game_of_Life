#include "graph.hpp"

graph :: graph(int x,int y) {
    dimension.first = x, dimension.second = y;
    g = new cell* [x];
    for(int i = 0;i < x;++i) {
        g[i] = new cell[y];
    }
}

void graph :: play() {
    cell **cp = cpy();
    for(int x = 0;x < dimension.first;++x) {
        for(int y = 0;y < dimension.second;++y) {
            if(detect(x,y)) {
                g[x][y].born();
            } else {
                g[x][y].kill();
            }
        }
    }
    delete []g;
    g = cp;
}

bool graph :: bordercheck(int row, int col) {
    return (row < dimension.first and row >= 0) and (col < dimension.second and col >=0);
}

bool graph :: detect(int x,int y) {
    int count = 0;
    for(int row = -1;row < 2;++row) {
        for(int col = -1;col < 2;++col) {
            if(row == col == 0) continue;
            if(bordercheck(row+x,col+y)) {
                count += g[row+x][row+y].isAlive() ? 1 : 0;
            }
        }
    }
    //Return true or false if cell is alive after counting neighbors
    return count == 2 or count == 3;
}

cell** graph :: cpy() {
    cell **cp = new cell* [dimension.first];
    for(int i = 0;i < dimension.first;++i) {
        cp[i] = new cell[dimension.second];
    }
    for(int x = 0;x < dimension.first;++x) {
        for(int y = 0;y < dimension.second;++y) {
            copy(&g[x][y],&g[x][y] + dimension.first * dimension.second,&cp[x][y]);
        }
    }
    return cp;
}

graph :: ~graph() {
    delete []g;
}