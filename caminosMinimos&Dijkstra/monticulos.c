#include <stdio.h> 
#include <stdlib.h>
#include "monticulos.h"


void monticuloVacio(MonticuloRef m){

	m->tamanho=0;
}


int compruebamonticuloVacio(MonticuloRef m){

	if(m->tamanho==0)
		return 1;
			else
				return 0;
}

tipoElementoM nuevoNodo(){
	
	tipoElementoM mNew;
	

	mNew.clave=rand() % 21;
	
	
return mNew;
}

void insertarEnMonticulo2(tipoElementoM xm,MonticuloRef m){

	tipoElementoM mNew,temp;	
	int hueco;

	if(m==NULL){
	}
			else{
			m->tamanho=m->tamanho+1;
			hueco=m->tamanho;
			m->array[hueco]=xm;

			while(m->array[hueco].clave<m->array[hueco/2].clave){
			temp=m->array[hueco/2];
			m->array[hueco/2].clave=m->array[hueco].clave;
			m->array[hueco].clave=temp.clave;
			hueco=hueco/2;
			}
			}





}

void insertarEnMonticulo(MonticuloRef m){

	tipoElementoM mNew,temp;	
	int hueco;

	if(m==NULL){
	}
			else{
			mNew=nuevoNodo();
			m->tamanho=m->tamanho+1;
			hueco=m->tamanho;
			m->array[hueco]=mNew;

			while(m->array[hueco].clave<m->array[hueco/2].clave){
			temp=m->array[hueco/2];
			m->array[hueco/2].clave=m->array[hueco].clave;
			m->array[hueco].clave=temp.clave;
			hueco=hueco/2;
			}
			}
}

void filtradoDescendente(MonticuloRef m, int i)
{
	int hijo,finFiltrado=0;
	tipoElementoM temp;

	while(2*i<=m->tamanho && !finFiltrado) //Controla que tenga un hijo
	{
		hijo=2*i;
		if(hijo!=m->tamanho)	//Controla que tenga hijo derecho tambien
		{
			if(m->array[hijo+1].clave<m->array[hijo].clave)
			{
				hijo+=1;
			}
		}
		if(m->array[i].clave>m->array[hijo].clave) 
		{
			temp=m->array[hijo];
			m->array[hijo]=m->array[i];
			m->array[i]=temp;
			i=hijo;
		}
		else
		{
			finFiltrado=1;
		}
	}
}


void filtradoAscendente(Monticulo *m, int i)
{
	tipoElementoM temp;

	while((m->array[i/2]).clave>(m->array[i]).clave && i!=1)
	{
		temp=m->array[i];
		m->array[i]=m->array[i/2];
		m->array[i/2]=temp;
		i/=2;
	}
}




tipoElementoM eliminarMinimo(MonticuloRef m){

	tipoElementoM min;
	int i;

	min=m->array[1];	
	m->array[1]=m->array[m->tamanho];
	m->tamanho=m->tamanho-1;	
	i=1;
	filtradoDescendente(m,i);



return min;
}


void crearMonticulo(MonticuloRef m2){

	int i,n;

	i=m2->tamanho;
	
	for(n=i; n>0; n--){
	m2->array[n].clave=rand() % 21;
	filtradoDescendente(m2,n);
	}
}

int decrementarClave(int pos,int cant,MonticuloRef m){


	int clve;
	clve=m->array[pos].clave-cant;
	//esta parte de arriba no es necesaria, la pongo para
	//saber si el resultado que me da está bien, de normal esta funcion devuelve un void	
	

	m->array[pos].clave=m->array[pos].clave-cant;
	filtradoAscendente(m,pos);

return clve;
}

int incrementarClave(int pos, int cant, MonticuloRef m){

	int vDes;

	if(m->tamanho==0){
	return 0;
	}
	m->array[pos].clave=m->array[pos].clave+cant;
	vDes=m->array[pos].clave;
	filtradoDescendente(m,pos);
	

return vDes;
}

/*
tipoElemento eliminarMinimo(MonticuloRef m){

	tipoElementoM min;
	int i=1;

	min=m.array[1];
	m->array[1].clave=m->array[m->tamanho].clave;
	m->tamanho=m->tamanho-1;

	filtradoDescendente(m,i);

return min;
}
*/



