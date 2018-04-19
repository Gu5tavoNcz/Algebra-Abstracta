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
    cout<<"tamano del mensaje"<<mensaje.length()<<endl;
}

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

int main()
{
    string mensaje;
    int clave;
    cout<<"Introduzca un mensaje a encriptar: ";
    getline(cin,mensaje);
    cout<<"introduzca una clave para su mensaje: ";
    cin>>clave;
    cout<<"tamano del mensaje"<<mensaje.length()<<endl;
    //cout<<"\nTu mensaje invertido es: "<<invertir(mensaje)<<"tamano del mensaje"<<mensaje.length()<<endl;
    cout<<"Tu clave es: "<<clave<<"\n"<<endl;
    //encriptado(mensaje,clave);
    cout<<"\n\nMensaje encriptado: "<<mensaje<<endl;
    ofstream fs("Mi mensaje.txt");
    fs << mensaje << endl;
    fs.close();
    desencriptado(mensaje,clave);
    //desencriptado(mensaje,clave); Este es un mensaje ENCRIPTADO para la clase de Algebra Abstracta - Ciencia de la computacion. Gustavo Naupa Canaza 47819563
}
