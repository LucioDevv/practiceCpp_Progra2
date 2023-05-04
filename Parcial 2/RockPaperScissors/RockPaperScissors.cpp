#include <iostream>

using namespace std;
int PJug = 0;
int PCom = 0;

int main()
{
    srand(time(0));
    int RPS = (rand() % 3) + 1;
    int RPSHumano;

    do {
        RPS = (rand() % 3) + 1;

        cout << endl << "Piedra, papel, o tijera?" << endl << "1) Piedra" << endl << "2) Papel" << endl << "3) Tijera" << endl;
        cout << "Puntuacion: Jugador " << PJug << " - " << PCom << " Computadora" << endl;
        cout << "Valor de la computadora: " << RPS << endl;

        cin >> RPSHumano;

        if (RPSHumano == 1 || RPSHumano == 2 || RPSHumano == 3) {
            if (RPS == 1 && RPSHumano == 2) {
                system("cls");
                cout << "Ganaste!";
                PJug++;
            }
            else if (RPS == 1 && RPSHumano == 3) {
                system("cls");
                cout << "Perdiste..";
                PCom++;
            }
            else if (RPS == 2 && RPSHumano == 1) {
                system("cls");
                cout << "Perdiste..";
                PCom++;
            }
            else if (RPS == 2 && RPSHumano == 3) {
                system("cls");
                cout << "Ganaste!";
                PJug++;
            }
            else if (RPS == 3 && RPSHumano == 1) {
                system("cls");
                cout << "Ganaste!";
                PJug++;
            }
            else if (RPS == 3 && RPSHumano == 2) {
                system("cls");
                cout << "Perdiste..";
                PCom++;
            }
            else {
                system("cls");
                cout << "Empataste.";
            }
        }
        else
        {
            system("cls");
            cout << "Inserte un valor valido la proxima vez.";
        }
    } while (PJug != 2 && PCom != 2);

    if (PJug == 2)
    {
        cout << endl << "Ganaste el juego!";
        system("break");
    }
    else {
        cout << endl << "Perdiste el juego...";
        system("break");
    }


}
