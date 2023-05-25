#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int askNumber(string question, int high, int low = 1);
//GUESS MY NUMBER
void guessMyNumber();

void MatrixBox();
void vectorsPart1();
void vectorReserve();
void iterators();
void iterInventory();
void guessTheWord();
void badSwap(int x, int y);
void goodSwap(int& x, int& y);

void display(const vector<string>& vec);


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

void MatrixBox() {

    const int ROWS = 11;
    const int COLUMNS = 11;


    for (int i = 0; i < ROWS; i++) {



        for (int j = 0; j < COLUMNS; j++) {

            if (j == 0 || j == COLUMNS - 1)
            {
                cout << " 1 ";
            }
            else if (i == 0 || i == ROWS - 1)
            {
                cout << " 1 ";
            }
            else {
                if (j == i)
                {
                    cout << " 1 ";
                }
                else if (j == COLUMNS - 1 - i)
                {
                    cout << " 1 ";
                }
                else {
                    cout << " * ";
                }
            }



        }
        cout << endl;
    }
}

void badSwap(int x, int y)
{
    int aux = x;
    x = y;
    y = aux;
}

void goodSwap(int& x, int& y)
{
    int aux = x;
    x = y;
    y = aux;
}

void guessTheWord()
{
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    vector<string> words;
    words.push_back("COMPUTADORA");
    words.push_back("JUEGO");
    words.push_back("CODIGO");
    words.push_back("REFRIGERADOR");

    srand(time(NULL));
    int randomNumber = rand();
    int wordsRandomIndex = (randomNumber % words.size());
    string wordSelected = words[wordsRandomIndex];

    //cout << wordSelected << endl;

    random_shuffle(wordSelected.begin(), wordSelected.end());
    cout << wordSelected << endl;

    string correctWord;

    do
    {
        cin >> correctWord;
        transform(correctWord.begin(), correctWord.end(), correctWord.begin(), ::toupper);
        //cout << correctWord << endl;

        if (correctWord == words[wordsRandomIndex])
        {
            attempts++;
            cout << "\nAdivinaste la palabra!!!\n";
            break;
        }
        else
        {
            attempts++;
            cout << "Fallaste humano inepto, te quedan " << MAX_ATTEMPTS - attempts << endl;
        }

    } while (attempts != MAX_ATTEMPTS);

    if (attempts == MAX_ATTEMPTS)
    {
        cout << "\nPerdiste, date de baja, la palabra era:  \n";
        cout << words[wordsRandomIndex];
    }
    else
    {
        cout << "\nMUY BIEN!! lo hiciste en: " << attempts << " intentos.";
    }

}

void iterInventory()
{
    vector<string> inventory;
    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");
    inventory.push_back("Rifle");

    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;

    cout << "\nTus Items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Intercambiar
    cout << "\n Intercambiaste tu " << inventory[2] << " por un arco";
    myIterator = inventory.begin() + 2;
    *myIterator = "Arco";
    cout << "\nTus Items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }


    //SIZE
    cout << "\n El nombre del item " << *myIterator << "tiene ";
    cout << (*myIterator).size() << " letras";

    cout << "\n El nombre del item " << *myIterator << "tiene ";
    cout << (myIterator)->size() << " letras";

    //INSERT
    cout << "\n\nRecuperaste la bomba robada ";
    inventory.insert(inventory.begin() + 2, "bomba");
    cout << "\nTus Items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //DELETE
    cout << "\nTu " << inventory[1] << " fue destruido en batalla.";
    inventory.erase(inventory.begin() + 1);
    cout << "\nTus Items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }
}

void iterators()
{
    const int NUM_SCORES = 4;
    int score;

    vector<int>::const_iterator iter;

    vector<int> scores;

    for (int i = 0; i < NUM_SCORES; i++)
    {
        cout << "Score " << i + 1 << endl;
        cin >> score;
        scores.push_back(score);
    }

    cout << "Puntajes" << endl;
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

    /*Find*/
    cout << "Buscar puntajes: Ingresa el puntaje que quieres buscar" << endl;
    cin >> score;

    iter = find(scores.begin(), scores.end(), score);

    if (iter != scores.end())
    {
        cout << "\nTu puntaje se encuentra en el vector\n";
    }
    else
    {
        cout << "\nNo encontramos el puntaje que buscas\n";
    }

    /*Random Shuffle*/

    srand(time(NULL));
    random_shuffle(scores.begin(), scores.end());
    cout << "\nScores Mezclados\n";
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Shuffle String 
    string word = "perro";
    random_shuffle(word.begin(), word.end());
    cout << word << endl;

    /*Sort*/
    cout << "\nCambiar orden \n";
    sort(scores.begin(), scores.end());
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

    cout << "\nCambiar orden  greater\n";
    sort(scores.begin(), scores.end(), greater<int>());
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }
}

void vectorReserve()
{
    vector<int> scores(10, 0);
    cout << "Vector size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;

    scores.reserve(11);

    cout << "Vector size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;
}

void vectorsPart1()
{
    //vector<string> myStuff = { "espada", "martillo", "bomba" };
    //vector<string> inventory(10);
    //vector<string> inventory(10, " Vacio ");
    //vector<string> inventory(myStuff);

    vector<string> inventory;

    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");

    cout << "Tienes " << inventory.size() << " items en tu inventario" << endl;

    //Iteration FOR
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << "\nCambiaste tu " << inventory[0] << " por una Bomba.";
    inventory[0] = "Bomba";

    cout << "\n";

    //Iteration DO-WHILE
    int i = 0;
    do {
        cout << inventory[i] << endl;
        i++;
    } while (i < inventory.size());

    cout << inventory[0] << " tiene " << inventory[0].size() << " letras en él. ";

    cout << " Perdiste un item en la última batalla" << endl;

    //Delete item from vector
    inventory.pop_back();
    //Iteration FOR
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << "Un enemigo ha robado todas tus armas" << endl;
    //inventory.clear();

    if (inventory.empty())
    {
        cout << "No tienes nada" << endl;
    }
    else
    {
        for (unsigned int i = 0; i < inventory.size(); i++)
        {
            cout << inventory[i] << endl;
        }
    }
}

int askNumber(string question, int high, int low)
{
    int number = 0;

    do {
        cout << question << "entre " << low << " y " << high << endl;
        cin >> number;
    } while (number > high || number < low);

    return number;
}

void guessMyNumber()
{
    srand(static_cast<unsigned int>(time(0)));
    //srand(time(NULL));
    int randomNumber = rand();
    int secretNumber = (randomNumber % 100) + 1;
    int guess;
    int tries = 0;
    int veryClose;


    cout << "GUESS MY NUMBER" << endl;
    cout << "Adivina el número en el menor número de intentos posible." << endl;

    //Depurar
    cout << secretNumber;
    do
    {

        guess = askNumber("\nIngresa un número ", 300);

        tries++;

        veryClose = secretNumber - guess;


        if (veryClose <= 5 && veryClose >= -5 && veryClose != 0)
        {
            cout << "Muy cerca!!\n";
        }

        if (guess > secretNumber) {
            cout << "Muy Alto\n\n";
        }
        else if (guess < secretNumber) {
            cout << "Muy Bajo\n\n";
        }
        else {
            cout << "Excelente lo hiciste en -- " << tries << "-- intentos";

        }
    } while (guess != secretNumber);
}
