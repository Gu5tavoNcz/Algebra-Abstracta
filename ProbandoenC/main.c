
#include <stdio.h>


#include <string.h>

//using namespace std;
//Variables globales
int nmatriz = 0;
void generarMatriz(int nmatriz);

//Funcion principal
int main(){
    printf("Inserta el tamaño de la matriz\n");
    scanf("%d",&nmatriz);
    generarMatriz(nmatriz);
}

//Funcion que generara la matriz en caracol
void generarMatriz(nmatriz){
    int i,j;
    int countTotal = 1,tamanioTotal = nmatriz*nmatriz;
    int fila = 0, check = nmatriz, band = 1;
    int matrizCaracol[nmatriz][nmatriz];

    //Llena matriz
    while(countTotal<=tamanioTotal){
        //Hacia la derecha
        for(i=band-1; i < check; i++){
            matrizCaracol[fila][i] = countTotal;
            countTotal = countTotal++;
        }
        fila = nmatriz - band;
        check = nmatriz - band;

        //Hacia abajo
        for(i=band; i <= check; i++){
            matrizCaracol[i][fila] = countTotal;
            countTotal = countTotal++;
        }

        //Hacia la izquierda
        for(i=check-1; i >= (band-1) ; i--){
            matrizCaracol[fila][i] = countTotal;
            countTotal = countTotal++;
        }

        fila = band-1;

        //Hacia arriba
        for(i=check-1; i >= band ; i--){
            matrizCaracol[i][fila] = countTotal;
            countTotal = countTotal++;
        }
        band++;
        fila = band-1;
    }

    //Imprimir matriz
    for(i=0; i<nmatriz; i++){
        for(j=0; j<nmatriz; j++){
            printf("%d \t", matrizCaracol[i][j]);
        }
        printf("\n");
    }
}
