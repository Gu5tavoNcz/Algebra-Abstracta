#include <iostream>
#include <string>

using namespace std;

void ejercicio1()
{
    //Recibir una cadena e imprimirla al revés usando iteradores.
    string cadena;
    cout<<"Introduzca una cadena: ";
    getline(cin,cadena);
    cout<<"Cadena normal:    "<<cadena<<endl;
    for(int i=0;i<cadena.length()/2;i++)
    {
        swap(cadena[i],cadena[cadena.length()-1-i]);
    }
    cout<<"Cadena invertida: "<<cadena<<endl;
}

void ejercicio2()
{
    //Recibir dos strings por entrada estándar. Imprimir el número de veces que
    //aparece el segundo string en el primer string. Las cadenas no contienen espacios en blanco.
    string cadena, palabra;
    int cont=0;
    bool res=true;
    cout<<"Introduzca una cadena: ";
    getline(cin,cadena);
    cout<<"introduzca una palabra: ";
    getline(cin,palabra);
    size_t busca=cadena.find(palabra);
    while(res==true)
    {
        if(busca!=std::string::npos)
        {
            busca=cadena.find(palabra,busca+1);
            cont++;
        }
        else
            res=false;
    }
    cout<<cont;
}

void ejercicio3()
{
    //Recibir por consola un entero impar n. Imprimir un rombo de caracteres
    //“*” cuyas diagonales deberán tener un tamaño de n caracteres.
    int n,m=0;
    cout<<"Introduzca un numero impar: ";
    cin>>n;
    string cadena[n];
    string signo="abcdefghijklmnopqrstuvwxyz";
    //signo.resize(n,'*');
    for(int i=0;i<n/2+1;i++)
    {
        cadena[i].resize(n,'*');
        cadena[i].replace(n/2-i,n/2+i,signo,0,i*2+1);
    }
    for(int i=n-(n/2);i<n;i++)
    {
        int cont=2;
        cadena[i].resize(n,'*');
        cadena[i].replace(n/2-(n-i-1),n/2+(n-i-1),signo,0,n-cont);
        cont+=2;
    }
    for(int i=0;i<n;i++)
        cout<<cadena[i]<<endl;
}


int main()
{
    ejercicio3();
}
