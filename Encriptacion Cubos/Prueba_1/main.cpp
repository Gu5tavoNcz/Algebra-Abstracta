#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string caracol(int n, string &mensaje)
{
    int cont=0,cont2=n-1,limite=n*n;
    int ini_i,fin_i,ini_a,fin_a,ini_b,fin_b,ini_d,fin_d;
    string cadena;
    fin_i=limite-1;
    ini_i=limite-n;
    ini_a=n;
    fin_a=limite-n;
    ini_b=n-1;
    fin_b=limite-n;
    ini_d=0;
    fin_d=n-1;
    cadena.resize(limite,'*');
    if(mensaje.length()<limite)
        mensaje.resize(limite,'*');
    //while(g==true)
    while(cont<limite-1){
        for(int i=ini_b;i<fin_b;i+=n)
        {
            cadena.replace(i,1,mensaje,cont,1);
            cont++;
        }

        ini_b=ini_b+n-1;
        fin_b=fin_b-n-1;
        for(int i=fin_i;i>ini_i;i--)
        {
            cadena.replace(i,1,mensaje,cont,1);
            cont++;
        }
        ini_i=ini_i-n+1;
        fin_i=fin_i-n-1;
        for(int i=fin_a;i>=ini_a;i-=n)
        {
            cadena.replace(i,1,mensaje,cont,1);
            cont++;
        }
        ini_a=ini_a+n+1;
        fin_a=fin_a-n+1;
        for(int i=ini_d;i<fin_d;i++)
        {
            cadena.replace(i,1,mensaje,cont,1);
            cont++;
        }
        ini_d=ini_d+n+1;
        fin_d=fin_d+n-1;
    }//while(ini_d!=fin_d);

    mensaje=cadena;
    int tod=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mensaje[tod];
            tod++;
        }
        cout<<"\n";
    }
    return cadena;
}

int main()
{
    string mensaje;
    int cuadrados,tamano;
    cout<<"Introduzca el mensaje: ";
    getline(cin,mensaje);
    cout<<"intruzca el numero de cuadrados en su encrioptado: ";
    cin>>cuadrados;
    cout<<"Intriduzca el tamano de cada cuadrado: ";
    cin>>tamano;
    caracol(tamano,mensaje);
    cout<<"\n\n"<<mensaje<<endl;
}
