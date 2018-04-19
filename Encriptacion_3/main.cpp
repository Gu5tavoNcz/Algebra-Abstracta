
#include "Encriptado.h"
#include "Desencriptado.h"


int main()
{
    string mensaje;
    int clave;
    cout<<"Introduzca un mensaje a encriptar: ";
    getline(cin,mensaje);
    cout<<"introduzca una clave para su mensaje: ";
    cin>>clave;
    encriptado(mensaje,clave);
    cout<<"\n\nMensaje encriptado: "<<mensaje<<endl;
    ofstream fs("Mi mensaje.txt");
    fs << mensaje << endl;
    fs.close();
    //desencriptado(mensaje,clave);
    //desencriptado(mensaje,clave); Este es un mensaje ENCRIPTADO para la clase de Algebra Abstracta - Ciencia de la computacion. Gustavo Naupa Canaza 47819563
}
