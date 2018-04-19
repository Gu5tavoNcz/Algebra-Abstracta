#ifndef DESENCRIPTADO_H_INCLUDED
#define DESENCRIPTADO_H_INCLUDED
#include "Encriptado.h"


void desencriptado(string mensaje, int clave)
{
    invertir(mensaje);
    string lista[clave];
    int pos=0,cont=0,salto=(clave-1)*2;
    bool emp=true;
    for(int i=0;i<clave;i++)
    {
        lista[i].resize(mensaje.length(),'*');
    }
    while(pos<mensaje.length())
    {
        cout<<mensaje[pos]<<"("<<pos<<")";
        if(pos+clave<mensaje.length())
        {
            emp=false;
        }
        else
        {
            emp=true;
        }
        pos=pos+salto;
        cout<<"\n"<<emp<<endl;
    }
    pos=0;
    if(emp==true)
    {
        while(pos<mensaje.length())
        {
            lista[0].replace(pos,1,mensaje,cont,1);
            pos=pos+salto;
            cont++;
        }
        pos=0;
        for(int i=1;i<clave-1;i++)
        {
            while(pos<mensaje.length())
            {
                if(pos-i>0)
                {
                    lista[i].replace(pos-i,1,mensaje,cont,1);
                    cont++;
                }
                if(pos+i<mensaje.length())
                {
                    lista[i].replace(pos+i,1,mensaje,cont,1);
                    cont++;
                }

                pos=pos+salto;
            }
            pos=0;
        }
        pos=clave-1;
        while(pos<mensaje.length())
        {
            lista[clave-1].replace(pos,1,mensaje,cont,1);
            pos=pos+salto;
            cont++;
        }
    }
    if(emp==false)
    {
        while(pos<mensaje.length())
        {
            lista[clave-1].replace(pos,1,mensaje,cont,1);
            pos=pos+salto;
            cont++;
            //En costruccion...
        }
    }


    for(int i=0;i<clave;i++)
    {
        cout<<lista[i]<<endl;
    }
}

#endif // DESENCRIPTADO_H_INCLUDED
