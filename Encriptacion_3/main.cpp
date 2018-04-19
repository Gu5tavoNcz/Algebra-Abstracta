#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string lista="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";

string invertir(string &mensaje)
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

string encriptar(string mensaje,int clave)
{
    string cadena[clave];
    for(int i=0;i<clave;i++)
        cadena[i].resize(clave,' ');
    int cont=0;
    for(int i=0;i<mensaje.length();i++)
    {
        if(cont>0)
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
