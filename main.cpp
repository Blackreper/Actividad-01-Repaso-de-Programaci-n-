#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Paquete
{
    private:
        int id;
        string origen, destino;
        float peso;

    public:
        // setter
        void SetPaquete(int i, string o, string d, float p);
        // getter
        void GetPaquete();
        void EliminarInicio();
        void Guardar();
        void Recuperar();
};

list<Paquete> Paqueteria;

void Paquete::SetPaquete(int i, string o, string d, float p)
{
    Paquete package;

    fflush(stdin);
    package.id = i;
    package.origen = o;
    package.destino = d;
    package.peso = p;
    Paqueteria.push_front(package);
}

void Paquete::GetPaquete()
{
    Paquete package;
    list<Paquete> Pqt;

    cout<<"\n\nMostrando datos de la paqueteria"<<endl<<endl;
    
    Pqt = Paqueteria;
    while(!Paqueteria.empty())
    {
        package = Paqueteria.front();

        cout<<"ID: "<<package.id<<endl;
        cout<<"origen: "<<package.origen<<endl;
        cout<<"Destino: "<<package.destino<<endl;
        cout<<"Peso Kg: "<<package.peso<<endl<<endl;

        Paqueteria.pop_front();
    }

    Paqueteria = Pqt;

}

void Paquete::EliminarInicio()
{
    Paqueteria.pop_front();
    cout<<"\n\nElemento del inicio eliminado."<<endl<<endl;    
}

void Paquete::Guardar()
{
    ofstream archivo("Respaldo.txt");
    if (archivo.is_open())
    {
        Paquete package;
        while(!Paqueteria.empty())
        {  
            package = Paqueteria.front();
            archivo << package.id << setw(10) << package.origen << setw(10) << package.destino << setw(10) << package.peso << endl;
            Paqueteria.pop_front();
        }
        cout<<"\n\nRespaldo generado con exito"<<endl;
    }
    else
    {
        cout<<"\n\nNo fue posible generar un respaldo"<<endl;
    }
    archivo.close();
}

void Paquete::Recuperar()
{
    ifstream archivo("Respaldo.txt");
    if (archivo.is_open())
    {
        Paquete package;

            while(!archivo.eof())
            {
                archivo >> package.id >> setw(10) >> package.origen >> setw(10) >> package.destino >> setw(10) >> package.peso;
                if(archivo.eof()){ break;}
                else
                Paqueteria.push_back(package);
            }
        cout<<"\n\nInformacion recuperada."<<endl;
    }
    else
    {
        cout<<"\n\nNo se pudo recuperar"<<endl;
    }
    archivo.close();
}

void Ingresar()
{
    Paquete package;
    int ID;
    string Orig, Dest;
    float kg;

    cout<<"\n\nIngresando datos: "<<endl<<endl;
    cout<<"Ingresa el ID:  ";
    cin>>ID; 
    cout<<"Ingresa el origen:  ";
    cin>>Orig; 
    cout<<"Ingresa el destino:  ";
    cin>>Dest; 
    cout<<"Ingresa el peso:  ";
    cin>>kg; 

    package.SetPaquete(ID, Orig, Dest, kg);
}

int main()
{
    Paquete paquete; 

    int num;
    do
    {
        cout << "\n\n||      PAQUETERIA      ||" << endl<<endl;
        cout << "1.- Insertar al inicio." << endl;
        cout << "2.- Eliminar al inicio." << endl;
        cout << "3.- Mostrar" << endl;
        cout << "4.- Guardar." << endl;
        cout << "5.- Recuperar" << endl;  
        cout << "0.- Salir" << endl;
        cout << "Seleccione una opcion:  ";
        cin >> num;
        switch(num)
        {
            case 1:
                Ingresar();
            break;

            case 2:
                paquete.EliminarInicio();
            break;

            case 3:
                paquete.GetPaquete();
            break;

            case 4:
                paquete.Guardar();
            break;

            case 5:
                paquete.Recuperar();
            break;

        
            default:
            break;
        };

    }while(num != 0);
    return 0;
}