#include "bits/stdc++.h"
using namespace std;

class Board{
    
    public:
    int size;
    vector<vector<char> > grid; //has a relationship
    Board(int sz) {
        this->size = sz;
        //grid.resize(size, vector<char>(size, '-'));
        for(int i = 0; i < size; i++){
            vector<char> temp(size);
            for(int j = 0; j < size; j ++)
                temp[j] = '-';
            this->grid.push_back(temp);
        }
    }
    void printBoard();
    list<pair<int, int>> getFreeCells();
    bool addPiece(int r, int c, char pp);
};

void Board::printBoard(){
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            cout << grid[i][j] << "   ";
        cout << endl;
    }
}
list<pair<int, int>> Board:: getFreeCells(){
    list<pair<int, int>> l;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(grid[i][j] == '-'){
                l.push_back({i, j});
            }
        }
    }
    return l;
}
bool Board::addPiece(int r, int c, char pp){
    if(grid[r][c] != '-')
        return false;
    grid[r][c] = pp;
    return true;
}