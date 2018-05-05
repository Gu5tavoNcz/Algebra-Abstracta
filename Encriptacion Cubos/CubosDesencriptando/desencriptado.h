#ifndef DESENCRIPTADO_H_INCLUDED
#define DESENCRIPTADO_H_INCLUDED
#include <string>
#include "funciones.h"

string rellenando(int n,int m,string &mensaje)
{
    int cont=0,mitad,salto,limite=(n*n)*m-(n*n);
    mitad=(n/2)-2;
    if(n%2!=0)
        mitad++;

    while(cont<n*m) //primera fila
    {
        cont+=n;
        if(cont<n*m)  //primer cuadrado
        {

            for(int i=0;i<n-1;i++)
            {
                mensaje.insert(cont,1,'*');
                cont++;
            }

        }
        cont+=n;
        if(cont<n*m) //tercer cuadrado
        {
            cont+=2;
            for(int i=0;i<n-2;i++)
            {
                mensaje.insert(cont,1,'*');
                cont++;
            }
            cont++; //Primera posicion de segunda fila
        }
    }
    for(int i=1;i<n-1;i++)//filas del cuerpo
    {
        int conteo=0;
        cont=(n*m)*i;
        while(conteo<m) //rellena todos los cuadrados m numero
        {
            conteo++;
            cont+=n;
            if(conteo<m)
            {

                if(i<mitad+1) //primer cuadrado N invertido
                {
                    mensaje.insert(cont,1,'*');
                    cont++;
                }
                else
                    cont++;
                for(int j=1;j<(n-1)-i;j++)
                {
                    mensaje.insert(cont,1,'*');
                    cont++;
                }
                cont++;
                for(int k=1;k<i;k++)
                {
                    mensaje.insert(cont,1,'*');
                    cont++;
                }
                conteo++;
            }
            cont+=n+2; // salto del cuadro caracol (3)
            if(conteo<m)
            {
                for(int l=1;l<i;l++)//segundo cuadrado N
                {
                    mensaje.insert(cont,1,'*');
                    cont++;
                }
                cont++;
                for(int m=1;m<(n-1)-i;m++)
                {
                    mensaje.insert(cont,1,'*');
                    cont++;
                }
                cont++;
                conteo++;
            }
            conteo++;
        }
    }
    cont=((n*n)*m-(n*m));//primera posicion de la ultima fila
    int conteo=0;
    while(conteo<m)
    {
        cont+=n+1;
        conteo++;
        if(conteo<m)
        {
            for(int i=0;i<n-2;i++)
            {
                mensaje.insert(cont,1,'*');
                cont++;
            }
            conteo++;
        }
        conteo++;
        if(conteo<m)
        {
            cont+=n+2;
            for(int i=0;i<n-2;i++)
            {
                mensaje.insert(cont,1,'*');
                cont++;
            }
            cont++;
            conteo++;
        }
    }

    int todj=0;
    cout<<"\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n*m;j++)
        {
            cout<<mensaje[todj];
            todj++;
        }
        cout<<"\n";
    }
    cout<<"\n";
    return mensaje;
}

string caracol_d(int n, string mensaje)
{
    int limite=n*n,cont2=0,cont=0;
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
            cadena.replace(cont,1,mensaje,i,1);
            cont++;
            cont2++;
        }

        ini_b=ini_b+n-1;
        fin_b=fin_b-n-1;
        for(int i=fin_i;i>ini_i;i--)
        {
            cadena.replace(cont,1,mensaje,i,1);
            cont++;
            cont2++;
        }
        ini_i=ini_i-n+1;
        fin_i=fin_i-n-1;
        for(int i=fin_a;i>=ini_a;i-=n)
        {
            cadena.replace(cont,1,mensaje,i,1);
            cont++;
            cont2++;
        }
        ini_a=ini_a+n+1;
        fin_a=fin_a-n+1;
        for(int i=ini_d;i<fin_d;i++)
        {
            cadena.replace(cont,1,mensaje,i,1);
            cont++;
            cont2++;
        }
        ini_d=ini_d+n+1;
        fin_d=fin_d+n-1;
    }//while(ini_d!=fin_d);
    if(cont2<limite)
    {
        cadena.replace(cont,1,mensaje,ini_b,1);
        cont++;
    }
    return cadena;
}

string zeta_d(int n,string mensaje)
{
    int ini_b,fin_b,cont=0;
    string cadena;
    ini_b=n/2;
    if(n%2!=0)
        ini_b++;
    cadena.resize(n*n,'*');
    for(int i=(ini_b*n)-n;i<=(n*n)-n;i+=n)
    {
        cadena.replace(cont,1,mensaje,i,1);
        cont++;
    }
    for(int i=((n*n)-(2*n))+1;i>=n-1;i=i-n+1)
    {
        cadena.replace(cont,1,mensaje,i,1);
        cont++;
    }
    for(int i=n+n-1;i<n*n;i+=n)
    {
        cadena.replace(cont,1,mensaje,i,1);
        cont++;
    }
    return cadena;
}

string ene_d(int n,string mensaje)
{
    int cont=0;
    string cadena;
    cadena.resize(n*n,'*');
    for(int i=(n*n)-n;i>0;i-=n)
    {
        cadena.replace(cont,1,mensaje,i,1);
        cont++;
    }
    for(int i=0;i<n*n-1;i+=n+1)
    {
        cadena.replace(cont,1,mensaje,i,1);
        cont++;
    }
    for(int i=(n*n)-1;i>+n-2;i-=n)
    {
        cadena.replace(cont,1,mensaje,i,1);
        cont++;
    }
    return cadena;
}

string desencriptando(int n,int m,string &mensaje)
{
    int salto=0;
    string lista,sms="*";
    while(salto<m)
    {

        if(salto<m)
        {
            lista=concatena(n,m,mensaje,salto);
            sms+=caracol_d(n,lista);
            salto++;
        }
        if(salto<m)
        {
            lista=concatena(n,m,mensaje,salto);
            sms+=zeta_d(n,lista);
            salto++;
        }
        if(salto<m)
        {
            lista=concatena(n,m,mensaje,salto);
            string tmp=caracol_d(n,lista);
            for(int i=0;i<tmp.length()/2;i++)
            {
                swap(tmp[i],tmp[tmp.length()-1-i]);
            }
            sms+=tmp;
            salto++;
        }
        if(salto<m)
        {
            lista=concatena(n,m,mensaje,salto);
            sms+=ene_d(n,lista);
            salto++;
        }
    }
    for(int i=sms.length()-1;i>=0;i--)
    {
        if(sms[i]=='*')
            sms.erase(i,1);
    }
    return sms;
}

#endif // DESENCRIPTADO_H_INCLUDED
