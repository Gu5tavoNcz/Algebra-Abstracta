#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

//string lista="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";
string lista="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.-_0123456789";
int cont=0;

void mostrar(string mensaje, int n)
{
    int tod=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"\t"<<mensaje[tod];
            tod++;
        }
        cout<<"\n";
    }
    cout<<"\n";
}

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


string caracol(int n, string &mensaje,int &cont)
{
    int limite=n*n,cont2=0;
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
    if(mensaje.length()<cont+limite)
    {
        mensaje.resize(cont+limite,'*');
    }
    while(cont2<limite-1){
        for(int i=ini_b;i<fin_b;i+=n)
        {
            cadena.replace(i,1,mensaje,cont,1);
            cont++;
            cont2++;
        }

        ini_b=ini_b+n-1;
        fin_b=fin_b-n-1;
        for(int i=fin_i;i>ini_i;i--)
        {
            cadena.replace(i,1,mensaje,cont,1);
            cont++;
            cont2++;
        }
        ini_i=ini_i-n+1;
        fin_i=fin_i-n-1;
        for(int i=fin_a;i>=ini_a;i-=n)
        {
            cadena.replace(i,1,mensaje,cont,1);
            cont++;
            cont2++;
        }
        ini_a=ini_a+n+1;
        fin_a=fin_a-n+1;
        for(int i=ini_d;i<fin_d;i++)
        {
            cadena.replace(i,1,mensaje,cont,1);
            cont++;
            cont2++;
        }
        ini_d=ini_d+n+1;
        fin_d=fin_d+n-1;
    }//while(ini_d!=fin_d);
    if(cont2<limite)
    {
        cadena.replace(ini_b,1,mensaje,cont,1);
        cont++;
    }

    mostrar(cadena,n);
    return cadena;
}

string zeta(int n,string &mensaje,int &cont)
{
    int ini_b,fin_b;
    string cadena;
    ini_b=n/2;
    if(n%2!=0)
        ini_b++;
    cadena.resize(n*n,'*');
    for(int i=(ini_b*n)-n;i<=(n*n)-n;i+=n)
    {
        if(cont==mensaje.length()-1)
            mensaje.resize(cont+1,'*');
        cadena.replace(i,1,mensaje,cont,1);
        cont++;
    }
    for(int i=((n*n)-(2*n))+1;i>=n-1;i=i-n+1)
    {
        if(cont>=mensaje.length())
            mensaje.resize(cont+1,'*');
        cadena.replace(i,1,mensaje,cont,1);
        cont++;
    }
    for(int i=n+n-1;i<n*n;i+=n)
    {
        if(cont>=mensaje.length())
            mensaje.resize(cont+1,'*');
        cadena.replace(i,1,mensaje,cont,1);
        cont++;
    }

    mostrar(cadena,n);


    return cadena;
}

string espiral(int n, string &mensaje, int &cont)
{
    string lista="*";
    if(mensaje.length()<cont+(n*n))
    {
        mensaje.resize(cont+(n*n),'*');
    }
    lista.replace(0,1,mensaje,cont,n*n);
    for(int i=0;i<lista.length()/2;i++)
    {
        swap(lista[i],lista[lista.length()-1-i]);
    }

    int limite=n*n,cont2=0;
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
    while(cont2<limite-1){
        for(int i=ini_b;i<fin_b;i+=n)
        {
            cadena.replace(i,1,lista,cont2,1);
            cont++;
            cont2++;
        }

        ini_b=ini_b+n-1;
        fin_b=fin_b-n-1;
        for(int i=fin_i;i>ini_i;i--)
        {
            cadena.replace(i,1,lista,cont2,1);
            cont++;
            cont2++;
        }
        ini_i=ini_i-n+1;
        fin_i=fin_i-n-1;
        for(int i=fin_a;i>=ini_a;i-=n)
        {
            cadena.replace(i,1,lista,cont2,1);
            cont++;
            cont2++;
        }
        ini_a=ini_a+n+1;
        fin_a=fin_a-n+1;
        for(int i=ini_d;i<fin_d;i++)
        {
            cadena.replace(i,1,lista,cont2,1);
            cont++;
            cont2++;
        }
        ini_d=ini_d+n+1;
        fin_d=fin_d+n-1;
    }//while(ini_d!=fin_d);
    if(cont2<limite)
    {
        cadena.replace(ini_b,1,lista,cont2,1);
        cont++;
    }

    mostrar(cadena,n);
    return cadena;
}

string ene(int n,string &mensaje, int &cont)
{
    string cadena;
    cadena.resize(n*n,'*');
    if(mensaje.length()<cont+(n*n))
    {
        mensaje.resize(cont+(n*n),'*');
    }
    for(int i=(n*n)-n;i>0;i-=n)
    {
        cadena.replace(i,1,mensaje,cont,1);
        cont++;
    }
    for(int i=0;i<n*n-1;i+=n+1)
    {
        cadena.replace(i,1,mensaje,cont,1);
        cont++;
    }
    for(int i=(n*n)-1;i>+n-2;i-=n)
    {
        cadena.replace(i,1,mensaje,cont,1);
        cont++;
    }
    mostrar(cadena,n);
    //cout<<"\n"<<cadena<<endl;
    return cadena;
}

#endif // FUNCIONES_H_INCLUDED
