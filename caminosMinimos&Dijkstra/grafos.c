/*
 * grafos.c
 *
 *  Created on: 21/04/2014
 *      Author: MJ Polo
 */
#include <stdio.h>
#include "cola.h"
#include "grafos.h"
#include "monticulos.h"



void iniciarGrafo(tipoGrafo *g){

	int i;
	pArco lsta;

	for(i=1; i<=g->orden; i++){

	g->directorio[i].alcanzado=0;
	g->directorio[i].gradoEntrada=0;
	g->directorio[i].ordenTop=0;
	g->directorio[i].distancia=INF;
	g->directorio[i].peso=0;
	g->directorio[i].anterior=0;

	}
	
	for(i=1; i<=g->orden; i++){

	lsta=g->directorio[i].lista;
	
	while(lsta!=NULL){

	g->directorio[lsta->v].gradoEntrada++;
	lsta=lsta->sig;
	}
	}	
	
}


/****************************************************************************************************/
/* Recorrido en PROFUNDIDAD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/***************************************************************************************************/
void profundidad(int v_inicio,tipoGrafo * grafo)
{ int w;
  pArco  p;
  printf("%d ",v_inicio);
  grafo->directorio[v_inicio].alcanzado=1;
  p = grafo->directorio[v_inicio].lista;
  while (p!=NULL)
  { w=p->v;
    if (!grafo->directorio[w].alcanzado)
        profundidad(w,grafo);
    p = p->sig;
  }
}
/************************************************************************************************/
/* Recorrido en AMPLITUD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/************************************************************************************************/
void amplitud(int v_inicio,tipoGrafo *grafo)
{ int w;
  pArco  p;
  Cola c;

  colaCreaVacia(&c);
  colaInserta(v_inicio,&c);
  while (!colaVacia(&c))  {
	w =colaSuprime(&c);
        if (!grafo->directorio[w].alcanzado) {
		printf("%d ",w);
	        grafo->directorio[w].alcanzado=1;
        	p =grafo->directorio[w].lista;
 		while (p!=NULL){
			w = p->v;
			colaInserta(w,&c);
			p = p->sig;
		}
	}
  }
	  
}

//RECORRIENDO LA LISTA DE ADYACENCIA, CUANDO UN VÉRTICE ES 0, LO AÑADIMOS A LA COLA
int ordenTop2(tipoGrafo *g){

	pArco lsta;
	Cola c;
	int i,v,w,ciclico=1;
	int ordTop=1;

	iniciarGrafo(g);
	colaCreaVacia(&c);
	

	for(i=1; i<=g->orden; i++){

		if(g->directorio[i].gradoEntrada==0){

		colaInserta(i,&c);
		ciclico=0;	
	
			if(g->directorio[i].alcanzado==0){
			g->directorio[i].alcanzado=1;
			}
	
		}
	}

	//No existe un vertice inicial con gradoEntrada=0
	if(ciclico){
	return 0;
	}

	while(!colaVacia(&c)){

	v=colaSuprime(&c);
	g->directorio[v].ordenTop=ordTop;
	ordTop++;
	lsta=g->directorio[v].lista;

		//Vamos decrementando en 1 el grado de entrada
		while(lsta!=NULL){
		//w es el vértice adyacente que viene despues
		w=lsta->v;
		g->directorio[w].gradoEntrada=(g->directorio[w].gradoEntrada)-1;
		if(g->directorio[w].gradoEntrada==0){
		colaInserta(w,&c);
		}
		lsta=lsta->sig;
		}
	}	
return 1;
}

//Grafos dirigidos
void caminosMinimos(int vInit, tipoGrafo *g){


	pArco lsta;
	int i,v,w; //v se corresponde con el vértice anterior a w
	Cola c;

	colaCreaVacia(&c);
	iniciarGrafo(g);
	g->directorio[vInit].distancia=0;
	g->directorio[vInit].anterior=0;
	
	colaInserta(vInit,&c);
	
	while(!colaVacia(&c)){

	v=colaSuprime(&c);
	
	g->directorio[v].alcanzado=1;
	lsta=g->directorio[v].lista;

		while(lsta!=NULL){
		w=lsta->v;

			if(g->directorio[w].distancia==INF){
			g->directorio[w].distancia=g->directorio[v].distancia+1;
			g->directorio[w].anterior=v;
			colaInserta(w,&c);
			}
		lsta=lsta->sig;
		}
	}


}

//Grafos dirigidos
int caminoMinimoInitFin(int vInit, int vFin, tipoGrafo *g){


	pArco lsta;
	int i,v,w; //v se corresponde con el vértice anterior a w
	Cola c;

	colaCreaVacia(&c);
	iniciarGrafo(g);
	g->directorio[vInit].distancia=0;
	g->directorio[vInit].anterior=0;
	
	colaInserta(vInit,&c);
	
	while(!colaVacia(&c)){

	v=colaSuprime(&c);
	
	g->directorio[v].alcanzado=1;
	lsta=g->directorio[v].lista;

		while(lsta!=NULL){
		w=lsta->v;
	
			if(w==vFin && g->directorio[w].distancia==INF){
			g->directorio[w].distancia=g->directorio[v].distancia+1;
			return g->directorio[w].distancia;
			}
			
			if(g->directorio[w].distancia==INF){
			g->directorio[w].distancia=g->directorio[v].distancia+1;
			g->directorio[w].anterior=v;
			colaInserta(w,&c);
			}
		lsta=lsta->sig;
		}
	}
}


void dijkstraYcola(int vIni,tipoGrafo *g, Cola *colDijk){

	tipoElementoM xm;
	Monticulo m;
	int v,w;
	pArco lsta;
	int coste;

	iniciarGrafo(g);
	monticuloVacio(&m);
	
	g->directorio[vIni].distancia=0;
	g->directorio[vIni].anterior=0;

	
	xm.clave=0;
	xm.info=vIni;
	
	
	insertarEnMonticulo2(xm,&m);

	while(!compruebamonticuloVacio(&m)){
	xm=eliminarMinimo(&m);
	v=xm.info;

		if(!g->directorio[v].alcanzado){
		
		g->directorio[v].alcanzado=1;
		v=xm.info;
		lsta=g->directorio[v].lista;
		colaInserta(v,&(*colDijk));
	
			while(lsta!=NULL){
			w=lsta->v;

				if(!g->directorio[w].alcanzado){
				
				coste=g->directorio[v].distancia+lsta->peso;
		
					if(coste<g->directorio[w].distancia){
					g->directorio[w].distancia=coste;
					g->directorio[w].anterior=v;
					xm.clave=coste;
					xm.info=w;
					insertarEnMonticulo2(xm,&m);
					}
				}
			lsta=lsta->sig;
			}
		}
	}
	
}





/**********************************************************************************************/
/* Función auxiliar para ver el contenido de la estructura que representa un grafo en memoria */
/**********************************************************************************************/
void verGrafo(tipoGrafo *g)
{  int i;
   pArco p;

   printf("\nGrafo  (Orden %d)\n\n",g->orden);
   printf("       alc gEnt oTop dist peso ant \n");
   printf("     +----+----+----+----+----+----+\n");

   for(i=1;i<=g->orden;i++)
   {  printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado,
                       g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);
       if (g->directorio[i].distancia == INF) printf("  * |");
       else   printf(" %2d |", g->directorio[i].distancia);
       if (g->directorio[i].peso == INF) printf("  * |");
       else   printf(" %2d |", g->directorio[i].peso);
       printf(" %2d |",g->directorio[i].anterior);
       p = g->directorio[i].lista;
       while (p != NULL)
       {   printf(" ->%2d", p->v);	// Grafos no ponderados
           //printf(" ->%2d, %2d", p->v, p->peso); // Grafos ponderados
           p = p->sig;
       }
       printf("\n");
   }
   printf("     +----+----+----+----+----+----+\n\n");
}
