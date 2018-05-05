#ifndef ENCRIPTADO_H_INCLUDED
#define ENCRIPTADO_H_INCLUDED
#include "funciones.h"

string encriptando(int n,int m,string mensaje)
{
    string encrip;
    int contando=0;
    mensaje.resize((n*n)*m,'*');
    while(contando<m)
    {
        if(contando<m)
        {
            encrip+=caracol(n,mensaje,cont);
            contando++;
        }
        if(contando<m)
        {
            encrip+=zeta(n,mensaje,cont);
            contando++;
        }
        if(contando<m)
        {
            encrip+=espiral(n,mensaje,cont);
            contando++;
        }
        if(contando<m)
        {
            encrip+=ene(n,mensaje,cont);
            contando++;
        }
    }

    string temp;
    contando=0;
    temp.resize((n*n)*n,'*');
    for(int i=0;i<n*n;i+=n) //<- LEYENDO EN FORMA HORIZONTAL
    {
        for(int j=i;j<(n*n)*m;j+=n*n)
        {
            temp.replace(contando,n,encrip,j,n);
            contando+=n;
        }
    }
    for(int i=temp.length()-1;i>=0;i--)
    {
        if(temp[i]=='*')
            temp.erase(i,1);
    }
    encrip=temp;
    return encrip;
}


#endif // ENCRIPTADO_H_INCLUDED
