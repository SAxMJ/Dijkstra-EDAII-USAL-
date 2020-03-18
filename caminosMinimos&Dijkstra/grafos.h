/*
 * grafos.h
 *
 *  Created on: 21/04/2014
 *      Author: MJ Polo
 */

#include "cola.h" 
#ifndef GRAFOS_H
#define GRAFOS_H

  #define N 20
  #define INF 999999

  typedef struct tagarco
  { int v;
    int peso;
    struct tagarco *sig;
  } arco;

  typedef arco *pArco;

  typedef struct
  { int alcanzado;
    int gradoEntrada;
    int ordenTop;
    int distancia;
    int peso;
    int anterior;
    pArco lista;
  } vertices;

  typedef struct {
	vertices directorio[N];
	int orden;
  }tipoGrafo;

 
void verGrafo(tipoGrafo *g);

void liberarListas(tipoGrafo *g);

/* Ejercicio 1*/

void iniciarGrafo(tipoGrafo *g);
void profundidad(int v_inicio,tipoGrafo *grafo);
void amplitud(int v_inicio,tipoGrafo *grafo);

/* Ejercicio 2*/

int ordenTop1(tipoGrafo *grafo);
//Utilizaremos la 2 comprobando si el grafo es acíclico
int ordenTop2(tipoGrafo *grafo);

/* Ejercicio 3: Caminos mínimos en grafos dirigidos */
/* a) NO Ponderados */

void caminosMinimos(int vInit, tipoGrafo *g);
int caminoMinimoInitFin(int vInit, int vFin, tipoGrafo *g);
void caminos1(int vInicio, tipoGrafo *g);
void caminos2(int vInicio, tipoGrafo *g);

/* b) PONDERADOS */
void dijkstra(int vInicio, tipoGrafo *g);
void dijkstra2(int vInicio, tipoGrafo *g);
void dijkstraYcola(int vIni,tipoGrafo *g, Cola *colDijk);

/* Interpretación de los algoritmos ¡Secuencia de vértices en caminos mínimos y distancias !!! */

int costeyTrayectoria(int vIni, int vFin, tipoGrafo *g); // Un camino!!
void todosCaminosMin(int vIni, tipoGrafo *g);		 // Todos!!

/* Ejercicio 4: Árbol de Expansión en grafos NO dirigidos */
/* a) Prim  ¡ Algoritmo e interpretación del resultado!!! */
void prim(tipoGrafo *grafo);
tipoGrafo * prim2(tipoGrafo *grafo);
/* c) Kruskal*/
tipoGrafo * kruskal(tipoGrafo *grafo);



#endif
