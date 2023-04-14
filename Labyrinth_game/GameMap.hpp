#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP
#include <iostream>
using namespace std;

//para incluir un arreglo bidimensional de celdas de mapa:
#include "MapCell.hpp"

class GameMap
{
        public:
        GameMap();
        //apuntador↓ apuntará a la celda en la que está el jugador
        MapCell* PlayerCell;

        MapCell* EnemyCell;

        //forma de declarar arreglos;
        //poner los arreglos después del nombre
        MapCell cells [15][10] ;

        //FUNCIÓN PARA REALIZAR EL ****INTRO**** DEL JUEGO:
        void DrawIntro();

        //haremos una función que dibuje nuestro mapa:
        void Draw();

        void DrawVictory();

        //crearemos otra función: obtendrá las coordenadas del player y actualiza el mapa
        bool SetPlayerCell(int PlayerX, int PlayerY);

        //función para el enemigo:
        void SetEnemyCell(int EnemyX, int EnemyY);
        
        //debemos crear un loop del juego, para ello creamos un booleano:
        bool isGameOver;
        int floor = 0;

        protected:
        //crearemos una función del cargado del archivo, es protegida porque solo la usará 'mapa'
        
        void LoadMapFromFile();
        //crearemos un apuntador:
        //apuntará a la celda en la que se encuentra el jugador
        // MapCell* PlayerCell;

};


#endif