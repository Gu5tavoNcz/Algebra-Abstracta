
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string lista="abcdefghijklmnopqrstuvwxyz ";

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
    string lista[clave],encrip;
    int cont=1;
    bool f=true;
    cout<<"\n\n"<<endl;
    lista[0].replace(0,1,mensaje,0,1);
    while(f==true)
    {
        for(int i=1;i<clave;i++)
        {
            if(cont<mensaje.length())
            {
                lista[i].resize(cont+1,'.');
                lista[i].replace(cont,cont+1,mensaje,cont,1);
                cont++;
            }
            else
            {
                lista[i].resize(cont,'.');
                lista[i].replace(cont,cont+1,"*");
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
                lista[i].resize(cont+1,'.');
                lista[i].replace(cont,cont+1,mensaje,cont,1);
                cont++;
            }
            else
            {
                lista[i].resize(cont,'.');
                lista[i].replace(cont,cont+1,"*");
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
        if(encrip[i]=='.')
        {
            encrip.erase(i,1);
        }
    }
    mensaje=encrip;
}

void desencriptado(string mensaje, int clave)
{
    invertir(mensaje);
    for(int i=0;i<100;i++)
    {
        encriptado(mensaje,clave);
        cout<<"\n\n"<<i<<" .- Mensaje encriptado: "<<mensaje<<"\nTamano: "<<mensaje.length()<<endl;
    }
}

int main()
{
    string mensaje;
    int clave;
    cout<<"Introduzca un mensaje a encriptar: ";
    getline(cin,mensaje);
    cout<<"introduzca una clave para su mensaje: ";
    cin>>clave;
    cout<<"\nTu mensaje invertido es: "<<invertir(mensaje)<<endl;
    cout<<mensaje<<endl;
    cout<<"Tu clave es: "<<clave<<"\n"<<endl;
    encriptado(mensaje,clave);
    cout<<"\n\nMensaje encriptado: "<<mensaje<<endl;
    desencriptado(mensaje,clave);
}
