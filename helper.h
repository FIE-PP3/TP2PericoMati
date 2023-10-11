#ifndef HELPER_H
#define HELPER_H

#include<iostream>
#include<list>
#include<time.h>

using namespace std;

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

class Menu
{
public:
    void menu()
    {
        while(interactuar){
            system("clear");

            cout << "+-------------------------------------------------+" << endl;
            cout << "|                 ELIJA UNA OPCION                |" << endl;
            cout << "| 1. Iniciar a Tom                                |" << endl;
            cout << "| 2. Crear un Ratones                             |" << endl;
            cout << "| 3. Lista de ratones                             |" << endl;
            cout << "| 4. Cazar un Raton                               |" << endl;
            cout << "| 5. Situacion de Tom                             |" << endl;
            cout << "|                                                 |" << endl;
            cout << "|                                                 |" << endl;
            cout << "| 0. SALIR                                        |" << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << "- Opcion: ";

            int opcion;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                if(tom==NULL)
                {
                    tom = IniciarATom();
                }else
                {
                    cout<<"Tom ya esta iniciado con "<<tom->ConsultaEnergia()<<"J de energia!!"<<endl;
                    Pause();
                }
                break;
            case 2:
                int cant;
                cout<<"Ingrese la cantidad de ratones a cargar... ";
                cin>>cant;
                ListarRatones(cant);
                break;
            case 3:
                ImprimirRatones();
                Pause();
                break;
            case 4:
                if(ratones.size() && tom!=NULL)
                    Cazar();
                else
                    cout<<"No hay Ratones para cazar, o no se inicializo a Tom!!"<<endl;
                Pause();
                break;
            case 5:
                if(tom!=NULL)
                {
                    SituacionTom();
                }else
                {
                    cout<<"No se inicializo a Tom!!"<<endl;
                }
                break;
            
            case 0:
                interactuar=false;
                break;
            default:
                break;
            }
        }
    }
    Gato * IniciarATom()
    {
        float inicio;
        cout<<"Ingrese la energia inicial de Tom... ";
        cin>>inicio;
        Gato * aux= new Gato(inicio);
        return aux;        
    }
    void ListarRatones(int cant)
    {
        for (int i = 0; i < cant; i++)
        {
            float peso;
            cout<<"Ingrese el peso del raton "<<i+1<<" ..."<<endl;
            cin>>peso;
            ratones.push_back(CrearRaton(peso));
        }
    }
    Raton * CrearRaton(float peso)
    {
        Raton * aux= new Raton(peso);
        return aux;
    }
    void ImprimirRatones()
    {
        system("clear");
        int i=0;
        cout << "+-------------------------------------------------------+" << endl;
        cout << "|                  Lista de Ratones                     |" << endl;
        cout << "+-------------------------------------------------------+" << endl;
        for(auto & aux : ratones)
        {
            cout<<"Raton "<<i+1<<" tiene un peso de "<<aux->Getpeso()<<" a una distancia de "<<aux->GetDistancia()<<" de Tom"<<endl;
            cout << "+-------------------------------------------------------+" << endl;
            i++;
        }
    }
    void Cazar()
    {
        int opcion;
        ImprimirRatones();
        cout<<"Presione el nro de raton a Cazar!!!"<<endl;
        cin>>opcion;
        if(opcion<=int(ratones.size()))
        {
            list<Raton*>::iterator iter = next(ratones.begin(), opcion-1);
            if(tom->meConvieneComerRatonA((*iter),(*iter)->GetDistancia()))
            {
                cout<<"Tom corrio "<<(*iter)->GetDistancia()<<" Gastando "<<tom->ConsumoXCorrer((*iter)->GetDistancia())<<"J de energia a una Velocidad de "<<tom->ConsultaVelocidad()<<" tardando "<<(*iter)->GetDistancia()/tom->ConsultaVelocidad()<<"seg"<<endl;
                tom->ComerRaton((*iter));
                ratones.erase(iter);
            }else
            {
                cout<<"A Tom no le conviene correr a ese raton"<<endl;
            }
        }else
        {
            cout<<"Nro de Ratones invalido"<<endl;
        }
    }
    void Pause()
    {
        cout<<endl<<"Aprete cualquier tecla para contunuar..."<<endl;
        system("read");
    }
    void SituacionTom()
    {
        system("clear");
        cout << "+-------------------------------------------------+" << endl;
        cout << "|                       TOM                       |" << endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "| Energia: "<<tom->ConsultaEnergia()<<endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "| Ratones comidos: "<<tom->GetRatoncesComidos()<<endl;
        cout << "+-------------------------------------------------+" << endl;
        Pause();
    }
private:
    Gato * tom=NULL;
    list<Raton*> ratones;
    bool interactuar= true;
};

#endif
