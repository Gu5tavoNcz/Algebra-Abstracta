#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string encriptar(string mensaje,string lista)
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

int main()
{
    string lista="abcdefghijklmnopqrstuvwxyz ";
    string mensaje;
    cout<<"Introduzca un mensaje a encriptar: ";
    getline(cin,mensaje);
    cout<<mensaje<<"\n";
    cout<<encriptar(mensaje,lista)<<endl;
}
