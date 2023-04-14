#include "GameMap.hpp"
#include <iostream>
//librería para cargar archivos ↓
#include <fstream>
using namespace std;

GameMap::GameMap()
{
 //con el objetivo de setear/inicializar la posición de PlayerCell(APUNTADOR)...
 //y no se crashee el programa con  datos de memoria basura.
    PlayerCell = NULL;
    LoadMapFromFile();
    isGameOver = false;




}

void GameMap::Draw()
{
    for (int i=0; i<15; i = i +1 )
    {
        for (int p=0; p<10; p = p +1 )
            {
                //dibujaremos las celulas de MAPCELL
                cout <<cells [i][p].id;
            }
            // cada vez que dibuje una linea, invocaremos un endl
            //para saltar a la siguiente
            cout << endl;
    }
} 

void GameMap::SetEnemyCell(int EnemyX, int EnemyY)
{

    EnemyCell = &cells[EnemyY][EnemyX];
    EnemyCell->id='8';

}



bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{ 

//si la celda no está bloqueada...
 
 //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA: 
    //si en las celulas Player Y-Player X el estado de bloqueo 
    //es igual a falso...
    //entonces...  el jugador se puede mover
    if (cells[PlayerY][PlayerX].IsBlocked()==false)

    {
            if(cells[PlayerY][PlayerX].id=='$')
            {
                DrawVictory();
                isGameOver = true;
                return true;
            }
            else
            {
                    //Para que el jugador no se dibuje varias veces, se pondrá:
                    //"Si mi apuntador es diferente de NULL, es decir, sino está vacio..."
                    if (PlayerCell != NULL)
                    {  
                        //entonces
                        //Si ya había una posición, la iniciaremos de nuevo en 0
                        PlayerCell->id = ' ';
                        
                    }

                        //Player cell será igual a la dirección de memoria de 'cells'
                        //Estamos consiguiendo de nuestro [arreglo de celdas] 
                        //la dirección de una de ellas
                        //la agarraremos y la guardaremos en nuestro apuntador:
                        PlayerCell = &cells[PlayerY][PlayerX];
                        PlayerCell->id = '3';

            }

                   
        
            

//retorna un TRUE!
    return true;

    } 
    else 

    {
        //PEERO SI LA CELDA ESTÁ BLOQUEADA, RETORNA UN FALSE!
        return false;

        //si todo sale mal, retornaremos falso,
        //quiere decir que el movimiento que realizó el jugador, 
        //no se pudo hacer.
        //y por lo tanto debemos reiniciar la posición inicial del jugador
        //dentro de nuestro código.

    }
    

    //Player cell será igual a la dirección de memoria de 'cells'
             //Estamos consiguiendo de nuestro [arreglo de celdas] 
             //la dirección de una de ellas
                //la agarraremos y la guardaremos en nuestro apuntador:
    PlayerCell = &cells[PlayerY][PlayerX];
    PlayerCell->id = '3';

    


    


   cout << "Las coordenadas del jugador están en: " << PlayerX << "," << PlayerY;
}

void GameMap::DrawIntro()
{
string line;
ifstream Myfile ("Intro.txt");

    if (Myfile.is_open())
    {
       
        //mientras..tenga lineas, extraerlas de mi archivo y seleccionar un renglón
        while(getline(Myfile, line))
        {
            
            cout << line << endl;

        }
        //quiero pausar un rato el programa
            cin >> line;
            
        }
        else
        {
            cout << "FATAL ERROR: INTRO COULD NOT BE LOADED!" << endl;
        }
}


void GameMap::DrawVictory()
{
string line;
ifstream Myfile ("Victory.txt");

    if (Myfile.is_open())
    {
       
        //mientras..tenga lineas, extraerlas de mi archivo y seleccionar un renglón
        while(getline(Myfile, line))
        {
            
            cout << line << endl;

        }
        //quiero pausar un rato el programa
            cin >> line;
            
        }
        else
        {
            cout << "FATAL ERROR: VICTORY COULD NOT BE LOADED! :()" << endl;
        }
}



void GameMap::LoadMapFromFile()

{   /*
    ofstream FileCreated("Map.txt");
    if (FileCreated.is_open())
    {

    }else
    {     
       cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED!" << endl;
    }
    */
    string line;
    //me indicará en qué línea estoy  
    int row = 0;
    ifstream Myfile ("Map.txt");

    if (Myfile.is_open())
    {
       
 //mientras..tenga lineas, extraerlas de mi archivo y seleccionar un renglón
        while(getline(Myfile, line))
        {
                //p=columna
            for (int p=0; p< line.length(); p=p+1)
            {
                if(line[p]=='0')

                
                //cells                     [row]                                  [p]
                //Dentro de las celdas, ubicar la fila en la que se encuentra y [columna]
                cells[row][p].id = '0';

                else{
                    cells[row][p].id = line[p];
                }
            }
            //cada vuelta de nuestro while, nuestra fila aumentará
            row++;
        }
         
    }
    else{
        cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED!" << endl;
    }
}