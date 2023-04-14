#include "Enemy.hpp"

#include <iostream>
using namespace std;

//Se define el constructor de Enemy:

Enemy::Enemy(){
    //inicializar las coordenadas x,y:
    x=1;
    y=1;


}

void Enemy::MoveHorizontal()
{
    //función rand, devuelve un numero aleatorio entre 0 y 1. 
    int number = rand();

    if (number>0.5)
    {
        x=x+1;
    }
    else
    {
        x = x-1;
    }
}


void Enemy::MoveVertical()
{
    //función rand, devuelve un numero aleatorio entre 0 y 1. 
    int number = rand();

    if (number>0.5)
    {
        y=y+1;
    }
    else
    {
        y = y-1;
    }
}