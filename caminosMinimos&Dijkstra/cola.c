#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"


//Ponemos la celda de frente y la de fondo a null
int colaCreaVacia(Cola *c)
{
   	c->frente=NULL;
	c->fondo=NULL;
 	return 0; 
    
}


//Si la cola de frente y la de fondo están ambas apuntando a null quiere decir que la cola está vacia
int colaVacia(Cola *c)
{
    if(c->frente==NULL && c->fondo==NULL)
		return 1;
	
	return 0;  
    
}


int colaInserta(tipoElemento elemento, Cola *c)
{
	//creamos una nueva celda de tipocelda
    tipoCelda *nuevo = (tipoCelda *) malloc(sizeof (tipoCelda));

	//Si la nueva celda está apuntando a null quiere decir que no se ha reservado memoria conrrectamente para la nueva celda
	if(nuevo == NULL)
		return -1;
	
	nuevo->sig=NULL;
	nuevo->elemento= elemento;
	
	//Si la cola está vacia quiere decir que la nueva celda será la misma para el frente y para el fondo de la cola
	if(colaVacia(c)){
		c->frente=nuevo;
		c->fondo=nuevo;

	//Si no, la celda de fondo, apuntaráa la nueva celda
	}else{
		(c->fondo)->sig=nuevo;
		c->fondo=nuevo;
	}
	return 0;    
    
}

tipoElemento colaSuprime(Cola *c)
{
    tipoElemento element;
	tipoCelda *aux=c->frente;

	//si la cola está vacia no podemos borrar ninguna celda, por lo que devolvemos -1
	if(colaVacia(c))
		exit(-1);
	
	element=(c->frente)->elemento;

	if(c->frente == c->fondo){
		c->fondo=NULL;
		free(c->frente);
		c->frente=NULL;
	}else{
		c->frente=aux->sig;
		free(aux);
		aux=NULL;	
	}	
	return element;
    
}
