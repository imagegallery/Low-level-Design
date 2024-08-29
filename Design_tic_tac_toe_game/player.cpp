#include "bits/stdc++.h"

using namespace std;

class Player{
    string name;
    char piece; //has a relationship
    public:
    
    Player(string n, char symbol){
        this->name = n;
        this->piece = symbol;
    }
    string getName(){
        return this->name;
    }
    void setName(string n){
        this->name = n;
    }
    char getPlayingPiece(){
        return this->piece;
    }
    void setPlayingPiece(char piece){
        this->piece = piece;
    }
};