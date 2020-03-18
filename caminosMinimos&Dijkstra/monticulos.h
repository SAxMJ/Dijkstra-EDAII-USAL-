#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*
typedef int tipoClave;
typedef int tipoInfo;


typedef struct tipoElemento{

	tipoClave clave;
	tipoInfo info;

}tipoElemento;

typedef struct Monticulo{

	tipoElemento array[];
	int tamanho;	

}Monticulo;

*/

typedef int tipoClave;
typedef int tipoInfo;


typedef struct tipoElementoM{

	tipoClave clave; //Distancia conseguida, Se irán colocando en el montículo en función del tamaño de la clave
	tipoInfo info;	 //Qué vértice es 
	
}tipoElementoM;

typedef struct Monticulo{

	tipoElementoM array[MAX];
	int tamanho;

}Monticulo;

typedef Monticulo *MonticuloRef;


int compruebamonticuloVacio(Monticulo *m);
void monticuloVacio(Monticulo *m);
void insertarEnMonticulo(Monticulo *m);
void insertarEnMonticulo2(tipoElementoM xm,Monticulo *m);
tipoElementoM nuevoNodo(void);
tipoElementoM eliminarMinimo(Monticulo *m);
void filtradoDescendente(Monticulo *m, int i);
void crearMonticulo(Monticulo *m2);
int decrementarClave(int,int,Monticulo *m);
void filtradoAscendente(Monticulo *m, int i);
int incrementarClave(int pos, int cant, Monticulo *m);


