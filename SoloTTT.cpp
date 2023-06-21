#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <clocale>

using namespace std;

char winner(const vector<char>& board);
const int NUM_SQUARES = 9;
const char EMPTY = ' ';
const int ROWS = 3;
const int COLUMNS = 3;
const char NO_ONE = 'N';
const char TIE = 'T';

int main()
{
    int playerTurn = 0;
    bool winAchieved = false;
    int playerInput;
   




    char board[ROWS][COLUMNS] = { {' ', ' ', ' '},
                                  {' ', ' ', ' '},
                                  {' ', ' ', ' '} };

    char exampleBoard[ROWS][COLUMNS] = { {'0', '1', '2'},
                                         {'3', '4', '5'},
                                         {'6', '7', '8'} };

    cout << endl << "You are X!" << endl;

    while (winner(board) == NO_ONE); {

        if (playerTurn == 0) {
            cout << "---TIC TAC TOE---" << endl;
            for (int i = 0; i < ROWS; i++) {

                for (int j = 0; j < COLUMNS; j++) {
                    cout << board[i][j] << "   ";
                }
                cout << endl;

            }

            cout << endl << "Where would you like to place your X? (0 - 8)" << endl;
            for (int i = 0; i < ROWS; i++) {

                for (int j = 0; j < COLUMNS; j++) {
                    cout << exampleBoard[i][j] << "   ";
                }
                cout << endl;

            }
            cin >> playerInput;

            if (playerInput >= 0 && playerInput <= 2) {
                if (board[0][playerInput] == ' ') {
                    board[0][playerInput] = 'X';
                    playerTurn = 1;
                }
                else {
                    cout << "Ya hay un simbolo alli, intente otro." << endl;
                    playerTurn = 0;
                }
            }
            else if (playerInput >= 3 && playerInput <= 5) {
                playerInput = playerInput - 3;
                if (board[1][playerInput] == ' ') {
                    board[1][playerInput] = 'X';
                    playerTurn = 1;
                }
                else {
                    cout << "Ya hay un simbolo alli, intente otro." << endl;
                    playerTurn = 0;
                }
            }
            else if (playerInput >= 6 && playerInput <= 8) {
                playerInput = playerInput - 6;
                if (board[2][playerInput] == ' ') {
                    board[2][playerInput] = 'X';
                    playerTurn = 1;
                }
                else {
                    cout << "Ya hay un simbolo alli, intente otro." << endl;
                    playerTurn = 0;
                }
            }
            else {
                cout << "Inserte un valor valido." << endl;
                playerTurn = 0;
            }
        }
        else {
            cout << "---TIC TAC TOE---" << endl;
            for (int i = 0; i < ROWS; i++) {

                for (int j = 0; j < COLUMNS; j++) {
                    cout << board[i][j] << "   ";
                }
                cout << endl;

            }

            cout << endl << "Where would you like to place your O? (0 - 8)" << endl;
            for (int i = 0; i < ROWS; i++) {

                for (int j = 0; j < COLUMNS; j++) {
                    cout << exampleBoard[i][j] << "   ";
                }
                cout << endl;

            }
            cin >> playerInput;

            if (playerInput >= 0 && playerInput <= 2) {
                if (board[0][playerInput] == ' ') {
                    board[0][playerInput] = 'O';
                    playerTurn = 0;
                }
                else {
                    cout << "Ya hay un simbolo alli, intente otro." << endl;
                    playerTurn = 1;
                }
            }
            else if (playerInput >= 3 && playerInput <= 5) {
                playerInput = playerInput - 3;
                if (board[1][playerInput] == ' ') {
                    board[1][playerInput] = 'O';
                    playerTurn = 0;
                }
                else {
                    cout << "Ya hay un simbolo alli, intente otro." << endl;
                    playerTurn = 1;
                }
            }
            else if (playerInput >= 6 && playerInput <= 8) {
                playerInput = playerInput - 6;
                if (board[2][playerInput] == ' ') {
                    board[2][playerInput] = 'O';
                    playerTurn = 0;
                }
                else {
                    cout << "Ya hay un simbolo alli, intente otro." << endl;
                    playerTurn = 1;
                }
            }
            else {
                cout << "Inserte un valor valido." << endl;
                playerTurn = 1;
            }
        }

    } 

}

//Return the piece winner a tie or noBody
char winner(const vector<char>& board)
{
    //This are the posibilities to win
    const int WINNING_POS[8][3] = { {0, 1, 2}, //Horizontal
                                    {3, 4, 5}, //Horizontal
                                    {6, 7, 8}, //Horizontal
                                    {0, 3, 6}, //Vertical
                                    {1, 4, 7}, //Vertical
                                    {2, 5, 8}, //Vertical
                                    {2, 4, 6}, //Horizontal
                                    {0, 4, 8} }; //Horizontal
    const int TOTAL_ROWS = 8;

    //Return the winner
    for (int row = 0; row < TOTAL_ROWS; row++)
    {
        if ((board[WINNING_POS[row][0]] != EMPTY) &&
            (board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) &&
            (board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]]))
        {
            return board[WINNING_POS[row][0]];
        }
    }

    //Return a Tie
    if (count(board.begin(), board.end(), EMPTY) == 0) {
        return TIE;
    }

    //Return that no one is the winner yet
    return NO_ONE;
}
