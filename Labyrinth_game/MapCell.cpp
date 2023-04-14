#include "MapCell.hpp"
#include <iostream>
using namespace std;

//inicializando el constructor
MapCell::MapCell()
{
    id = 0;
}

//**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
bool MapCell::IsBlocked()
{
    //Si id es igual a 1 (es el símbolo que representa nuestra pared)
    if (id=='1')
    {
        return true;
    }
    else
    {
        return false;
    }
    
}