#include "Player.hpp"

#include <iostream>
using namespace std;
//se definen las funciones y el constructor del encabezado

Player::Player(){
    //coordenadas de player
    x=1;
    y=1;
}
void Player::CallInput()
{
    char  UserInput = ' ';

    cin>> UserInput;

    switch(UserInput)
    {
        case 'w':
        {
            //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
            lastY = y;
            //se cambiarán las coordenadas del player dependiendo de la tecla que presione
            y = y-1;
            break;
        }

        case 's':
        {
            //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
            lastY = y;
            y = y+1;
            break;
        }

        case 'a':
        {
            //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
            lastX = x;
            x = x-1;
            break;
        }

        case 'd':
        {
            //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
            lastX = x;
            x = x+1;
            break;
        }
        default:{
              cout << "Haz seleccionado otra opción" <<endl;
            
            break;
        }
        
    }

    cout << "Mi jugador está en las coordenadas: " << x << "," << y << endl;


    
}

void Player::ResetToSafePosition()
{
    x = lastX;
    y = lastY;
}