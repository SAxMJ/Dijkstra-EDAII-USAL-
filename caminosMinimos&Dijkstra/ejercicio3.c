#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "grafos.h"
#include "cola.h"


tipoGrafo *creaGrafoT47();


int main(void)
{ tipoGrafo *gT47;
  int ciclico,distancia,vIni=1,vInit,vFin,v;
  Cola colDijk;
  
	gT47 = creaGrafoT47();
	printf("GRAFO CREADO\n");
	verGrafo(gT47);
	
	iniciarGrafo(gT47);
	printf("GRAFO INICIADO\n");
	verGrafo(gT47);
	
	caminosMinimos(vIni,gT47);
  	printf("GRAFO POR CAMINOS MINIMOS\n");
	verGrafo(gT47);

	printf("GRAFO INICIADO DE NUEVO\n");
	verGrafo(gT47);

	printf("VErtice inicial: ");
	scanf("%d",&vInit);
	printf("VErtice final: ");
	scanf("%d",&vFin);
	distancia=caminoMinimoInitFin(vInit,vFin,gT47);

	printf("LA DISTANCIA ENTRE LOS GRAFOS %d Y %d ES %d\n" ,vInit,vFin,distancia);
	verGrafo(gT47);
	
	printf("VOLVEMOS A INICIALIZAR EL GRAFO\n");
	iniciarGrafo(gT47);
	verGrafo(gT47);

	printf("LE APLICAMOS AL GRAFO DIJIKSTRA\n");
	//dijkstra(vIni,gT47);

	iniciarGrafo(gT47);
	printf("GRAFO INICIADO DE NUEVO\n");

	vIni=1;
	colaCreaVacia(&colDijk);
	printf("APLICAMOS DIJKSTRA CON UNA COLA\n");
	dijkstraYcola(vIni,gT47,&colDijk);

	printf("VISUALIZAMOS EL ORDEN DE LOS GRAFOS\n");
	
	while(!colaVacia(&colDijk))
	printf("%d\t",colaSuprime(&colDijk));	

	puts("");

	iniciarGrafo(gT47);
	verGrafo(gT47);
	printf("GRAFO INICIADO DE NUEVO\n");
	printf("APLICAMOS PRIM\n");
	prim(gT47);
	verGrafo(gT47);

//	liberarListas(g);
//	free(g);
}
/************************************************************/
/* Creación del grafo ponderado de la  1 (transparencia 47) */
/************************************************************/
tipoGrafo *creaGrafoT47()
{ int i;
  pArco  p,aux;
  tipoGrafo *g;

  g=(tipoGrafo *)calloc(1,sizeof(tipoGrafo));

  g->orden=7;

  // Lista de adyacencia del vértice 1
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 2;
  	p->peso = 2;
  	g->directorio[1].lista=p;
  	aux = p;
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	  p->v = 4;
	  p->peso = 1;
	  aux->sig = p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 2
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
  	p->v = 4;
	p->peso = 3;
  	g->directorio[2].lista=p;
	aux = p;
  p= (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
  	p->v = 5;
	p->peso = 10;
	aux->sig = p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 3
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 1;
	p->peso = 4;
	g->directorio[3].lista=p;
	aux = p;
  p= (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 6;
	p->peso = 5;
	aux->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 4
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 3;
	p->peso = 2;
	g->directorio[4].lista=p;
	aux = p;
  p= (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 5;
	p->peso = 2;
	aux->sig = p;
	aux = aux->sig;
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 6;
	p->peso = 8;
	aux->sig = p;
	aux = aux->sig;
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 7;
	p->peso = 4;
	aux->sig = p;
  p->sig=NULL;
// Lista de adyacencia del vértice 5
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 7;
	p->peso = 6;
	g->directorio[5].lista=p;
	p->sig=NULL;
// Lista de adyacencia del vértice 6
  g->directorio[6].lista=NULL;
// Lista de adyacencia del vértice 7
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 6;
	p->peso = 1;
	g->directorio[7].lista=p;
  p->sig=NULL;

  return g;
  }

