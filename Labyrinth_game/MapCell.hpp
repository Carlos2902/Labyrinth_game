#ifndef MAPCELL_HPP
#define MAPCELL_HPP

    class MapCell
    {
        public:
        MapCell();
        //GUARDARÁ el número de qué tipo de cuadro es nuestra celda, en los que:
        //0-> representará un espacio vacio
        //1-> representará una pared
        //H-> será el jugador

        //contendrá un numero que será el ID que representa:
        //se hizo el cambio de "int(entero)" a "char(caracter)"
        char id ;
        //se le asignó un valor de '0' por lo que todas las celdas del mapa aparecerán vacías


    //**COLISION: RESTRINGIR AL JUGADOR PARA NO PASAR LOS LIMITES DEL MAPA
        //haremos una función tipo booleana:
        //con el objetivo de avisar si la celda está o no está bloqueada
        bool IsBlocked();
        
    };

#endif