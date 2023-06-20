#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <clocale>

using namespace std;

int main()
{
    const int ROWS = 3;
    const int COLUMNS = 3;
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

    do {

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

    } while (winAchieved == false);

}
