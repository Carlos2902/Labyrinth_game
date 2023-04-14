#ifndef PLAYER_HPP
#define PLAYER_HPP 

class Player
{

    public:
    Player();

    //creación de la función:
    void CallInput();
    //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
    //creación de otra función:
    void ResetToSafePosition();
    int x, y;

    //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
    //Representarán las últimas coordenadas en las que estuvo el jugsador.
    int lastX, lastY;

    protected:
        


};

#endif