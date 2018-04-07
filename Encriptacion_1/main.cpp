#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string lista="abcdefghijklmnopqrstuvwxyz ";

string ejercicio1(string mensaje)
{
    for(int i=0;i<mensaje.length();i++)
    {
        for(int j=0;j<lista.length();j++)
        {
            if(mensaje[i]==lista[j])
            {
                mensaje[i]=lista[lista.length()-j-1];
                break;
            }
        }
    }
    return mensaje;
}


string ejercicio2(string mensaje,int clave)
{

}


int pruebas(string str) {
    char c = 'a';
    string reemplazo = "xxx";

    for (int i = 0; i < (int)str.length(); ++i) {
        if(str[i]==c)
        {
            str.replace(i,1,reemplazo);
        }
    }

    cout << str << endl;
    return 0;
}


int main()
{
    string mensaje;
    cout<<"Introduzca un mensaje a encriptar: ";
    getline(cin,mensaje);
    cout<<"Tu mensaje encriptado es: "<<ejercicio1(mensaje)<<endl;
    cout<<mensaje<<"\n";
    pruebas(mensaje);
    cout<<mensaje<<"\n";
}
