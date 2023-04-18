#include <iostream>

using namespace std;


int main()
{
    srand(time(0));
    int RPS = rand() % 3 + 1;
    int RPSHumano;


    cout << "Piedra, papel, o tijera?" << endl << "1) Piedra" << endl << "2) Papel" << endl << "3) Tijera" << endl;
    cout << "Valor de la computadora: " << RPS << endl;

    cin >> RPSHumano;

    if (RPSHumano == 1 || RPSHumano == 2 || RPSHumano == 3) {
        if (RPS == 1 && RPSHumano == 2) {
            cout << "Ganaste!";

        }
        else if (RPS == 1 && RPSHumano == 3) {
            cout << "Perdiste..";
        }
        else if (RPS == 2 && RPSHumano == 1) {
            cout << "Perdiste..";
        }
        else if (RPS == 2 && RPSHumano == 3) {
            cout << "Ganaste!";
        }
        else if (RPS == 3 && RPSHumano == 1) {
            cout << "Ganaste!";
        }
        else if (RPS == 3 && RPSHumano == 2) {
            cout << "Perdiste..";
        }
        else {
            cout << "Empataste.";
        }
    }
    else
    {
        cout << "Inserte un valor valido la proxima vez.";
    }
    
}
