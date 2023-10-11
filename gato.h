#ifndef GATO_H
#define GATO_H


class Gato {
public:
    /*Constructor*/
    Gato(float e):energia(e){}
    /*"Come" un raton, Carga su energia y aumenta en 1 la cantidad de ratones comidos*/
    void ComerRaton(Raton *A)
    {
        energia+=12+A->Getpeso();
        cantRaton++;
    }
    /*Resta el consumo de energia por correr y devuelve dicho consumo*/
    float ConsumoXCorrer(float distancia)
    {
        float consumo=0.5*distancia;
        energia-=consumo;
        return consumo;
    }
    /*Get energia de vuelve la energia*/
    float ConsultaEnergia()
    {
        return energia;
    }
    /*Devuelve la velocidad teniendo en cuenta la energia en ese momento*/
    float ConsultaVelocidad()
    {
        return 5.0 + energia/10.0;
    }
    /*De vuelve true o false dependiendo si llega a cazar al raton*/
    bool meConvieneComerRatonA(Raton * A, float mts)
    {
        float consumo=0.5*mts;
        float e=12+A->Getpeso();
        if(e>consumo){
            return true;
        }
        return false;
    }
    /*Get Ratones comidos de vuelve un int*/
    int GetRatoncesComidos()
    {
        return cantRaton;
    }
private:
    float energia;
    int cantRaton=0; // inicializado en 0
};

#endif