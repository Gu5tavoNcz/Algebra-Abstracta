#include "encriptado.h"
#include <fstream>

using namespace std;

int main()
{
    string mensaje,encriptado;
    int cuadrados,tamano,contando=0;
    cout<<"Introduzca el mensaje: ";
    getline(cin,mensaje);
    cout<<"intruzca el numero de cuadrados en su encrioptado: ";
    cin>>cuadrados;
    cout<<"Intriduzca el tamano de cada cuadrado: ";
    cin>>tamano;
    //invertir(mensaje);

    encriptado=encriptando(tamano,cuadrados,mensaje);
    cout<<"\n\n"<<mensaje<<"\n"<<encriptado<<endl;
    cout<<mensaje.length()<<"\t"<<encriptado.length()<<endl;
    ofstream fs("Mi mensaje.txt");
    fs <<"Num Cuadratos: "<<cuadrados<<"\n\nTamano de cada cuadrado: "<<tamano<<"\n\nMensaje :"<<mensaje<<"\n\nEncriptado :"<<encriptado<<endl;
    fs.close();
}
