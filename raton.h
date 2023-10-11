#ifndef RATON_H
#define RATON_H

class Raton{
public:
    Raton (float p): peso(p){}
    float Getpeso()
    {
        return peso;
    }
    float GetDistancia()
    {
        return distancia;
    }
private:
    float peso;
    float distancia=rand()%100+1;
};

#endif