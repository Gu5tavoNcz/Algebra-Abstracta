#ifndef ENCRIPTADO_H_INCLUDED
#define ENCRIPTADO_H_INCLUDED
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

void encriptado(string &mensaje,int clave)
{
    invertir(mensaje);
    string lista[clave],encrip;
    int cont=1;
    bool f=true;
    lista[0].replace(0,1,mensaje,0,1);
    while(f==true)
    {
        for(int i=1;i<clave;i++)
        {
            if(cont<mensaje.length())
            {
                lista[i].resize(cont+1,'*');
                lista[i].replace(cont,cont+1,mensaje,cont,1);
                cont++;
            }
            else
            {
                lista[i].resize(cont,'*');
                lista[i].replace(cont,cont+1,"x");
                cont++;
            }
        }

        if (cont>=mensaje.length())
        {
            f=false;
            break;
        }

        for(int i=clave-2;i>=0;i--)
        {
            if(cont<mensaje.length())
            {
                lista[i].resize(cont+1,'*');
                lista[i].replace(cont,cont+1,mensaje,cont,1);
                cont++;
            }
            else
            {
                lista[i].resize(cont,'*');
                lista[i].replace(cont,cont+1,"x");
                cont++;
            }
        }
        if (cont>=mensaje.length())
            f=false;
    }
    for(int i=0;i<clave;i++)
    {
        cout<<lista[i]<<endl;
        encrip+=lista[i];
    }
    for(long i=encrip.length()-1;i>=0;i--)
    {
        if(encrip[i]=='*')
        {
            encrip.erase(i,1);
        }
    }
    mensaje=encrip;
}


#endif // ENCRIPTADO_H_INCLUDED
