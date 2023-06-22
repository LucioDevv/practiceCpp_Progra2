#include <vector>
#include <iostream>
#include <string>
using namespace std;
const int NUM_SQUARES = 9;
const char EMPTY = ' ';
const int ROWS = 3;
const int COLUMNS = 3;
const char NO_ONE = 'N';
const char TIE = 'T';
const char X = 'x';
const char O = 'o';


void instructions();
char playerSymbol();
char OponentSymbol(char Symbol);
char winner(const vector<char>& board);
char AskYesNo(string question);
void displayboard(const vector<char>& board);
int askNumber(string question, int high, int low = 1);
bool IsLegal(const vector<char>& board, int LastMove);


int main()
{
    int move = 0;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();
    char Player = playerSymbol();
    char Computer = Player == X ? O : X;
    //char Computer = Player == X ? O : X;
    char Turn = X;


    while (winner(board) == NO_ONE)
    {
        if (Turn == Player)
        {
            cout << "Turno del jugador" << endl;
            do {
                move = askNumber("\nElige un numero ", 8);
            } while (IsLegal(board, move) == false);
            board[move] = Player;
            Turn = Computer;

        }
        else
        {
            cout << "Turno de la maquina" << endl;
            do {
                move = askNumber("\nElige un numero ", 8);
            } while (IsLegal(board, move) == false);
            board[move] = Computer;
            Turn = Player;

        }

        displayboard(board);
    }



}


void instructions()
{
    char boardoptions[ROWS][COLUMNS] = { {'0', '1', '2'},
                                         {'3', '4', '5'},
                                         {'6', '7', '8'} };

    cout << "------------------------ TicTacToe ------------------------" << endl;
    cout << "Buena suerte, la vas a necesitar." << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << boardoptions[i][j];
        }
        cout << endl;
    }
}

char playerSymbol()
{
    char GoFirst = AskYesNo("Quisieras empezar primero?");
    if (GoFirst == 'y')
    {
        return X;
    }
    else
    {
        return O;
    }
}
char OponentSymbol(char Symbol)
{
    if (Symbol == X)
    {
        return O;
    }
    else if (Symbol == O)
    {
        return X;
    }
}

char AskYesNo(string question)
{
    char answer;

    do {
        cout << "\n" << question << "(y/n)";
        cin >> answer;
    } while (answer != 'y' && answer != 'n');

    return answer;

}
//Return the piece winner a tie or noBody
char winner(const vector<char>& board)
{
    //This are the posibilities to win
    const int WINNING_POS[8][3] = { {0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6}, 
                                    {1, 4, 7}, 
                                    {2, 5, 8}, 
                                    {2, 4, 6}, 
                                    {0, 4, 8} };
    const int TOTAL_ROWS = 8;


    for (int row = 0; row < TOTAL_ROWS; row++)
    {
        if ((board[WINNING_POS[row][0]] != EMPTY) &&
            (board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) &&
            (board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]]))
        {
            return board[WINNING_POS[row][0]];
        }
    }

    if (count(board.begin(), board.end(), EMPTY) == 0) {
        return TIE;
    }

    return NO_ONE;
}
void displayboard(const vector<char>& board)
{
    cout << board[0] << board[1] << board[2] << endl;
    cout << board[3] <<  board[4] << board[5] << endl;
    cout << board[6] << board[7] <<  board[8] << endl;
}

int askNumber(string question, int high, int low)
{
    string input;
    bool isValid = false;
    //int number = 0;

    //do {
    cout << question << "entre " << low << " y " << high << endl;
    do {
        getline(cin, input);

        for (char c : input)
        {
            if (isdigit(c))
            {
                isValid = true;
                break;
            }
            cout << "Test, outside the if\n";
        }
        if (!isValid)
        {
            cout << "\nEntrada invalida, por favor elige solo numeros.\n";
        }
        else if (isValid)
        {
            if (stoi(input) < low || stoi(input) > high)
            {
                cout << "Numero muy bajo o muy alto, introduzca otro numero" << endl;
                isValid = false;
            }
        }

    } while (!isValid || input.empty());
    //number > high || number < low);

    return stoi(input);
}

bool IsLegal(const vector<char>& board, int LastMove)
{
    if (board[LastMove] != ' ')
    {
        cout << "Ya hay un simbolo en este espacio, intente otra vez." << endl;
        return false;
    }
    else
    {
        return true;
    }

}
