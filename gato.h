#ifndef GATO_H
#define GATO_H


class Gato {
public:
    Gato(float e):energia(e){}
    void ComerRaton(Raton *A)
    {
        energia+=12+A->Getpeso();
        cantRaton++;
    }

    float ConsumoXCorrer(float distancia)
    {
        float consumo=0.5*distancia;
        energia-=consumo;
        return consumo;
    }

    float ConsultaEnergia()
    {
        return energia;
    }
    float ConsultaVelocidad()
    {
        return 5.0 + energia/10.0;
    }
    bool meConvieneComerRatonA(Raton * A, float mts)
    {
        float consumo=0.5*mts;
        float e=12+A->Getpeso();
        if(e>consumo){
            return true;
        }
        return false;
    }
    int GetRatoncesComidos()
    {
        return cantRaton;
    }
private:
    float energia;
    int cantRaton=0;
};

#endif