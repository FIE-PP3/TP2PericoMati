#ifndef MENU_H
#define MENU_H


class Menu
{
public:
    /* Menu Principal con sus cases*/
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
                if(ratones.size() && tom!=NULL) //para cazar tienen q existir ratones y Tom
                    Cazar();
                else
                    cout<<"No hay Ratones para cazar, o no se inicializo a Tom!!"<<endl;
                Pause();
                break;
            case 5:
                if(tom!=NULL) // para preguntar sobre la sutiacion de Tom tiene que existir
                {
                    SituacionTom();
                }else
                {
                    cout<<"No se inicializo a Tom!!"<<endl;
                }
                break;
            
            case 0:
                interactuar=false; // Accion de terminar el programa
                break;
            default:
                break;
            }
        }
    }
    /*Instancia un Un Objeto Gato y devuelve su direccion de memoria*/
    Gato * IniciarATom()
    {
        float inicio;
        cout<<"Ingrese la energia inicial de Tom... ";
        cin>>inicio;
        Gato * aux= new Gato(inicio);   // asignacion de memoria dinamica e instancia del objeto
        return aux;        
    }
    /* Inicio/ Agrego Objetos de la clase Raton en mi lista de punteros de Raton (list<Raton*>)*/
    void ListarRatones(int cant)
    {
        for (int i = 0; i < cant; i++)
        {
            float peso;
            cout<<"Ingrese el peso del raton "<<i+1<<" ..."<<endl;
            cin>>peso;
            ratones.push_back(CrearRaton(peso));        // agrega elementos al final de la lista
        }
    }
    /*Instancia un Un Objeto Raton y devuelve su direccion de memoria*/
    Raton * CrearRaton(float peso)
    {
        Raton * aux= new Raton(peso);
        return aux;
    }
    /*Imprime por pantalla la lista de Ratones*/
    void ImprimirRatones()
    {
        system("clear");
        int i=0;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|                    Lista de Ratones                       |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        for(auto & aux : ratones)
        {
            cout<<"Raton "<<i+1<<" tiene un peso de "<<aux->Getpeso()<<"g a una distancia de "<<aux->GetDistancia()<<"mts de Tom"<<endl;
            cout << "+-----------------------------------------------------------+" << endl;
            i++;
        }
    }
    /*Accion de "Cazar",Elige y Elimina un Raton de la lista, si le es posible cazarlo*/
    void Cazar()
    {
        int opcion;
        ImprimirRatones();
        cout<<"Presione el nro de raton a Cazar!!!"<<endl;
        cin>>opcion;
        if(opcion<=int(ratones.size()))     //validación
        {
            list<Raton*>::iterator iter = next(ratones.begin(), opcion-1);      //Identificando el elemento dentro de la lista
            if(tom->meConvieneComerRatonA((*iter),(*iter)->GetDistancia()))     //Evalua si puede cazarlo, si le da la energia para correr la distancia requerida
            {
                cout<<"Tom corrio "<<(*iter)->GetDistancia()<<" Gastando "<<tom->ConsumoXCorrer((*iter)->GetDistancia())<<"J de energia a una Velocidad de "<<tom->ConsultaVelocidad()<<" tardando "<<(*iter)->GetDistancia()/tom->ConsultaVelocidad()<<"seg"<<endl;
                tom->ComerRaton((*iter));           
                ratones.erase(iter);            //Elimina de la lista al elemento
            }else
            {
                cout<<"A Tom no le conviene correr a ese raton"<<endl;
            }
        }else
        {
            cout<<"Nro de Ratones invalido"<<endl;
        }
    }
    /*funcion para... Presionar una tecla antes de continuar*/
    void Pause()
    {
        cout<<endl<<"Aprete cualquier tecla para contunuar..."<<endl;
        system("read");
    }
    /*Informa la situacion de TOM*/
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