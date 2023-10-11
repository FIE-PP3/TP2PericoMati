#ifndef RATON_H
#define RATON_H

class Raton{
public:
    Raton (float p): peso(p){}      //Constructor
    float Getpeso()                 //Get Peso
    {
        return peso;
    }
    float GetDistancia()            // Get Distancia al Gato
    {
        return distancia;
    }
private:
    float peso;
    float distancia=rand()%100+1;   //Distancia random de 1-99 mts
};

#endif