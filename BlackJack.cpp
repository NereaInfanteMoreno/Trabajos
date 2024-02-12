// blackjack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <windows.graphics.h>
#include <conio.h>
#include <graphics.h>

#pragma comment(lib, "winmm.lib")
using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void inicio_juego()
{
    char dd = 0;
    system("cls");
    gotoxy(15, 1);
    cout << " *----------------------------- Comienza el juego del BLACKJACK ------------------------------*\n";
    gotoxy(19, 3);
    cout << "COMIENZA  EL JUUEGO \n";
    gotoxy(19, 5);
    cout << "Para conmenzar el juego presiona una tecla" << endl;
    gotoxy(65, 5);
    dd = _getch();
    system("cls");
}
void panel_de_juego()
{
    system("color b4");
    system("cls");
    gotoxy(55, 0);
    cout << " BLACKJACK \n";
    gotoxy(10, 1);
    for (int x = 1; x <= 100; x++) {
        cout << "-";
    }
    gotoxy(10, 2);
    for (int x = 2; x <= 22; x++)
    {
        gotoxy(10, x);
        cout << "                                                  |                                                  " << endl;
    }
    gotoxy(10, 23);
    for (int x = 1; x <= 100; x++) {
        cout << "-";
    }
    gotoxy(25, 3);
    cout << "Jugador" << endl;
    gotoxy(25, 4);
    cout << "-------";
    gotoxy(75, 3);
    cout << "Crupier" << endl;
    gotoxy(75, 4);
    cout << "-------";

}


int jugadores()
{
    system("cls");
    int juga;
    gotoxy(15, 1);
    cout << " *----------------------------- Comienza el juego del BLACKJACK ------------------------------*\n";
    gotoxy(25, 3);
    cout << " *---------------   Numero de juadador  Maximo 4 -------------*\n";
    gotoxy(20, 5);
    cout << "                         1 -- > Jugador         \n";
    gotoxy(20, 6);
    cout << "                         2 -- > Jugador       (*)  \n";
    gotoxy(20, 7);
    cout << "                         3 -- > Jugador       (*)  \n";
    gotoxy(20, 8);
    cout << "                         4 -- > Jugador       (*)  \n";
    gotoxy(20, 11);
    cout << "                        (*) opcion no habilitada  \n";
    gotoxy(20, 15);
    cout << "                           Elige Opcion     :: ";
    cin >> juga;

    return 1;

}

int pedir_indice()
{
    int tim = 0 + rand() % (52 - 1);
    return (tim);
}

int valor_carta(string elemento, int puntuacion)
{
    char letra;
    int punto;
    letra = elemento[0];
    switch (letra)
    {
    case 'J':
        punto = 10;
        break;
    case 'Q':
        punto = 10;
        break;
    case 'K':
        punto = 10;
        break;
    case '1':
        if (puntuacion > 10)
        {
            punto = 1;
        }
        else
        {
            punto = 11;
        }

        break;

    default:
        punto = stoi(elemento);
        break;
    }

    return punto;
}


int main()
{
    // crear variables
    boolean flag = true;
    boolean flag1 = true;
    string carta1, carta2;
    int otra_carta;
    int indice_jugador = 1, indice_crupier = 1;
    int puntuacion = 0, puntos1 = 0, puntos2 = 0;
    int jugador = 0, indice;
    int posicion_baraja;
    string retorno;
    int puntos_crupier = 0;
    int puntos_jugador = 0;

    string cartas_jugador[10];
    string cartas_crupier[10];
    string baraja[52] = { "1C","2C","3C","4C","5C","6C","7C","8C","9C","10C","JC","QC","KC",
                         "1T","2T","3T","4T","5T","6T","7T","8T","9T","10T","JT","QT","KT",
                         "1R","2R","3R","4R","5R","6R","7R","8R","9R","10R","JR","QR","KR",
                         "1D","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD" };

    /***********************************************************Comienza el juego****************************************************/
    system("color bd");
    inicio_juego();
    srand(time(0));
    system("title : El juego del Blacjack ");
    jugador = jugadores();

    // primera jugada se sacan dos cartas para jugador y  dos para el crupier una de ellas tapada
    // primera carta del jugador 1
    do
    {
        indice = pedir_indice();
    } while (baraja[indice] == "00");

    cartas_jugador[0] = baraja[indice];
    baraja[indice] = "00";
    carta1 = cartas_jugador[0];
    puntos1 = valor_carta(carta1, puntos_jugador);

    // segunda carta del jugador 1
    do
    {
        indice = pedir_indice();
    } while (baraja[indice] == "00");

    cartas_jugador[1] = baraja[indice];
    baraja[indice] = "00";
    carta2 = cartas_jugador[1];
    puntos2 = valor_carta(carta2, puntos_jugador);

    puntos_jugador = puntos1 + puntos2;

    // primera carta del crupier
    do
    {
        indice = pedir_indice();
    } while (baraja[indice] == "00");

    cartas_crupier[0] = baraja[indice];
    baraja[indice] = "00";
    carta1 = cartas_crupier[0];
    puntos1 = valor_carta(carta1, puntos_crupier);

    // segunda carta del crupier
    do
    {
        indice = pedir_indice();
    } while (baraja[indice] == "00");

    cartas_crupier[1] = baraja[indice];
    baraja[indice] = "00";
    carta2 = cartas_crupier[1];
    puntos2 = valor_carta(carta2, puntos_crupier);
    puntos_crupier = puntos1 + puntos2;

    system("cls");
    panel_de_juego();

    for (int x = 0; x <= indice_jugador; x++)
    {
        gotoxy(15, (8 + x));
        cout << "carta " << cartas_jugador[x] << endl;
    }
    gotoxy(25, 5);
    cout << "Puntos  " << puntos_jugador << endl;

    for (int x = 0; x < indice_crupier; x++)
    {
        gotoxy(70, (8 + x));
        cout << "carta " << cartas_crupier[x] << endl;
        gotoxy(75, 5);
        cout << "Puntos  " << endl;
    }

    //******************************************************************************
    while (flag)  //**** aqui comienza el juego el jugador 1
    {
        if (puntos_jugador == 21)
        {
            gotoxy(25, 19);
            cout << "B L A C K J A C K" << endl;
            otra_carta = 2;
        }

        if (puntos_jugador > 21)
        {
            gotoxy(25, 19);
            cout << "   TE HAS PASADO  " << endl;
            gotoxy(65, 19);
            cout << "La BANCA  ha ganado                      " << endl;
            otra_carta = 2;
            flag1 = false;
        }

        if (puntos_jugador < 21)
        {
            gotoxy(12, 25);
            cout << "Pedir carta --> 1     Plantarme  --> 2" << endl;
            gotoxy(52, 25);
            cin >> otra_carta;
        }

        switch (otra_carta)
        {
        case 1:
            do
            {
                indice = pedir_indice();
            } while (baraja[indice] == "00");

            indice_jugador++;
            cartas_jugador[indice_jugador] = baraja[indice];
            baraja[indice] = "00";
            carta1 = cartas_jugador[indice_jugador];
            puntos1 = valor_carta(carta1, puntos_jugador);
            puntos_jugador = puntos_jugador + puntos1;

            for (int x = 0; x <= indice_jugador; x++)
            {
                gotoxy(15, (8 + x));
                cout << "carta " << cartas_jugador[x] << endl;
            }
            gotoxy(25, 5);
            cout << "Puntos  " << puntos_jugador << endl;

            break;

        case 2:
            flag = false;
            break;

        default:

            break;
        }

    }

    for (int x = 0; x <= indice_crupier; x++)
    {
        gotoxy(70, (8 + x));
        cout << "carta " << cartas_crupier[x] << endl;
        gotoxy(75, 5);
        cout << "Puntos  " << puntos_crupier << endl;
    }
    gotoxy(12, 25);
    cout << "                                              " << endl;


    while (flag1 == true)   //**** aqui comienza el juego el crupier
    {

        if (puntos_crupier == 21)
        {
            gotoxy(65, 19);
            cout << "B L A C K J A C K              " << endl;

            if (puntos_crupier == puntos_jugador)
            {
                gotoxy(49, 20);
                cout << "P A R T I D A    N U L A   " << endl;
            }
            otra_carta = 2;
            flag1 = false;
        }

        if (puntos_crupier > 21)
        {
            gotoxy(65, 19);
            cout << "La BANCA  ha perdido                      " << endl;
            otra_carta = 2;
            flag1 = false;
        }

        if (puntos_crupier < 21)
        {
            if (puntos_crupier > puntos_jugador)
            {
                gotoxy(65, 19);
                cout << "La BANCA  ha ganado                     " << endl;
                otra_carta = 2;
                flag1 = false;
            }
            else
            {
                gotoxy(60, 25);
                cout << "Pedir carta --> 1   Plantarme  --> 2" << endl;
                gotoxy(100, 25);
                cin >> otra_carta;

                if (otra_carta == 2 && puntos_crupier < puntos_jugador)
                {
                    gotoxy(65, 19);
                    cout << " Tienes que pedir otra carta ";
                    gotoxy(60, 25);
                    cout << "Pedir carta --> 1   Plantarme  --> 2" << endl;
                    gotoxy(100, 25);
                    cin >> otra_carta;
                    gotoxy(65, 19);
                    cout << "                              ";
                }
                if (otra_carta == 2 && puntos_crupier == puntos_jugador)
                {
                    gotoxy(49, 20);
                    cout << "P A R T I D A    N U L A   " << endl;
                    flag1 = false;
                }
            }
        }


        switch (otra_carta)
        {
        case 1:
            do
            {
                indice = pedir_indice();
            } while (baraja[indice] == "00");

            indice_crupier++;
            cartas_crupier[indice_crupier] = baraja[indice];
            baraja[indice] = "00";
            carta1 = cartas_crupier[indice_crupier];
            puntos1 = valor_carta(carta1, puntos_crupier);
            puntos_crupier = puntos_crupier + puntos1;

            for (int x = 0; x <= indice_crupier; x++)
            {
                gotoxy(70, (8 + x));
                cout << "carta " << cartas_crupier[x] << endl;
                gotoxy(75, 5);
                cout << "Puntos  " << puntos_crupier << endl;
            }
            gotoxy(12, 25);
            cout << "                                          " << endl;

            break;
        case 2:

            flag1 = false;
            break;
        default:

            flag1 = false;
            break;
        }

    }

    gotoxy(45, 13);
    cout << "     G A M E       O V E R       " << endl;
    PlaySound(TEXT("level-passed.wav"), NULL, SND_ASYNC);
    Sleep(1000);
    gotoxy(45, 26);
    _getch();
    system("cls");
    return 0;
}
