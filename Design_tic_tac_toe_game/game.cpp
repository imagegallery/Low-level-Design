#include "bits/stdc++.h"
#include "player.cpp"
#include "board.cpp"

using namespace std;

class Game{
    deque<Player*> players;
    Board *gameboard;
    public:
    Game(){
        initializeGame();
    }
    ~Game(){
        delete gameboard;
    }
    void initializeGame();
    string startGame();
    bool isThereWinner(int row, int col, char piecetype);
};

void Game:: initializeGame(){
    //creating 2 players
    Player *player1 = new Player("Player 1", 'X');
    Player *player2 = new Player("Player 2", 'O');

    players.push_back(player1);
    players.push_back(player2);

    //initialize board
    gameboard = new Board(3);
}

string Game::startGame(){
    bool noWinner = true;
    //cout << "NOTE: Enter Row and columns entries considering index start from 0." << endl;
    while(noWinner){

        //take out the first player from list and put the player to the back of the list
        Player *currentPlayer = players.front();
        players.pop_front();

        //printing the board
        gameboard->printBoard();
        
        //get the free cells from the game board
        list<pair<int, int>> freeSpaces = gameboard->getFreeCells();
        if(freeSpaces.empty()){
            noWinner = false;
            continue;
        }

        //get the row and col from user
        int row, col;
        cout << "Player: " << currentPlayer->getName() << " Enter row, column: (please enter numbers between 0 and 2.) ";
        cin >> row >> col;
        
        bool success = gameboard->addPiece(row, col, currentPlayer->getPlayingPiece());
        if(!success){
            cout << "This is occupied position!! Please try again."<<endl;
            players.push_front(currentPlayer);
            continue;
        }

        //put the player back in list
        players.push_back(currentPlayer);
        
        //check if anyone is winning aleady
        bool winner = isThereWinner(row, col, currentPlayer->getPlayingPiece());
        if(winner)
            return currentPlayer->getName();

    }
    return "tie";

}

bool Game:: isThereWinner(int row, int col, char piecetype){
    bool rowMatch = true;
    bool colMatch = true;
    bool diagMatch = true;
    bool antiDiagMatch = true;
    int size = gameboard->size;
    //need to check in row
    for(int i = 0; i < size; i++){
        if(gameboard->grid[row][i] == '-' || gameboard->grid[row][i] != piecetype)
            rowMatch = false;
    }

    //need to check in cols
    for(int i = 0; i < size; i++){
        if(gameboard->grid[i][col] == '-' || gameboard->grid[i][col] != piecetype)
            colMatch = false;
    }

    //need to check for diagonal
    for(int i = 0; i <size; i++){
        if(gameboard->grid[i][i] == '-' || gameboard->grid[i][i] != piecetype)
            diagMatch = false;
    }

    //need to check for antidiagonal
    for(int i = 0, j = size-1; i < size; i++, j--){
        if(gameboard->grid[i][j] == '-' || gameboard->grid[i][j] != piecetype)
            antiDiagMatch = false;
    }
    return rowMatch || colMatch || diagMatch || antiDiagMatch;

}
