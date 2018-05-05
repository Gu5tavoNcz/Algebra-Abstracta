#include "encriptado.h"
#include "desencriptado.h"
#include <fstream>

using namespace std;

int main()
{
    string mensaje,encriptado,desencriptado,temp,prueba2;
    int cuadrados,tamano,contando=0;
    cout<<"Introduzca el mensaje: ";
    getline(cin,mensaje);
    cout<<"intruzca el numero de cuadrados en su encrioptado: ";
    cin>>cuadrados;
    cout<<"Intriduzca el tamano de cada cuadrado: ";
    cin>>tamano;
    //invertir(mensaje);

    encriptado=encriptando(tamano,cuadrados,mensaje);
    temp="0ab1lvutEIO9fc2gkmwpsDHJN8ed3hjnxqrCGKM7654ioyzABFL";
    rellenando(tamano,cuadrados,temp);
    desencriptado=desencriptando(tamano,cuadrados,temp);
    cout<<"\n\n"<<encriptado<<"\n\n"<<desencriptado<<"\n\n"<<endl;
    ofstream fs("Mi mensaje.txt");
    fs <<"Num Cuadrados: "<<cuadrados<<"\n\nTamano de cada cuadrado: "<<tamano<<"\n\nMensaje :"<<mensaje<<"\n\nEncriptado :"<<encriptado<<"\n\nDesencriptado: "<<desencriptado<<endl;
    fs.close();
}
