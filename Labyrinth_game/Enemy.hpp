#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy
{

    public:
    Enemy();


    //Debe tener coordenadas x,y:
    int x,y;


    //Creación de la función para que el enmigo se mueva:
    void MoveHorizontal();
    void MoveVertical();

    

};


#endif