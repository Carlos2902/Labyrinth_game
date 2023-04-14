    #include <iostream>
#include "MapCell.hpp"
#include "Player.hpp"
#include "GameMap.hpp"
#include "Enemy.hpp"

using namespace std;

int main()
{
    //el objeto MAP viene de la clase 'GameMap'
    GameMap Map;
    Player Hero;

    //inicializar a enemy:
    Enemy AntiHero;

    //Después de inicializar nuestro mapa y nuestro hérore...
    //inicializamos nuestro intro!
    Map.DrawIntro();
    Map.Draw();

    
    

    //mientras Mapa es GameOver sea == falso, se repetirá el loop del juego
    while(Map.isGameOver == false)
    {

        //Aquí se encuentra el loop del juego:
        //Al principio se espera un input, lo que provoca que
        //el juego se vea pausado y raro, por lo que después
        //del intro, dibujaré el mapa↑ (abajo de Map.DrawIntro)
        cout << "Introduce el comando de movimiento 'w' 'a' 's' 'd': " << endl;
        Hero.CallInput();
        
   //*****Introducir la función que hará que el enemigo se mueva automáticamente:****
        if (Map.floor==0)
        {
            AntiHero.x = 4;
            AntiHero.y = 3;
        }
        else
        {
            AntiHero.x = 2;
            AntiHero.y = 8;
        }

        Map.SetEnemyCell(AntiHero.x, AntiHero.y);

        //función para determinar cuando el heroe choque 
        //con el enemy, se acabe el juego:

        if (Hero.x == AntiHero.x && Hero.y == AntiHero.y)
        {
            Map.isGameOver = true;
            cout << "GAME OVER PERDISTE" << endl;
        }




        //actualizamos la información del heroe dentro del mapa:

        //si la posición de setear al jugador es correcta, dibujamos el mapa..
        if (Map.SetPlayerCell(Hero.x, Hero.y))
        {
            Map.Draw();
        }
        else
        //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
        //sino, lo dibujamos pero reiniciará al jugador en su última posición a salvo
        {
            //esto evitará que pase por paredes
            Hero.ResetToSafePosition();
            Map.Draw();
        }
        

        //Actualizado de infromación heroe a Mapa
        Map.SetPlayerCell(Hero.x, Hero.y);

        //Aquí dibujamos el mapa
        Map.Draw();
    }

    
    

    return 0;
};

