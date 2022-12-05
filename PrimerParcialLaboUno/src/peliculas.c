#include "peliculas.h"

int GenerarCodigoPelicula()
{
	static int codigoIncrementalPelicula = 1004;
	return codigoIncrementalPelicula++;
}

ePelicula AltaPelicula(eDirector directores[], int size)
{
	ePelicula unaPelicula;

	unaPelicula.codigo = GenerarCodigoPelicula();
	utn_getOnlyString("Ingrese el nombre de la pelicula: \n", "Error, reingrese el nombre de la pelicula: \n", 5,  100, unaPelicula.titulo);
	validarEntero("Ingrese la duracion de la pelicula: \n", "Error, reingrese la duracion de la pelicula: \n",0,180,5,&unaPelicula.duracion);
	unaPelicula.idDirector = ValidarDirectores(directores, size);
	validarEntero("Ingrese el año que se va a estrenar la pelicula: \n", "Error, reingrese el año que se va a estrenar la pelicula: \n",2022,2030,5,&unaPelicula.fechaDeEstreno.anio);
	validarEntero("Ingrese el mes que se va a estrenar la pelicula: \n", "Error, reingrese el mes que se va a estrenar la pelicula: \n",1,12,5,&unaPelicula.fechaDeEstreno.mes);
	unaPelicula.fechaDeEstreno.dia = ValidarDia(unaPelicula.fechaDeEstreno.mes, "Ingrese el dia que se va a estrenar la pelicula: \n");
	validarEntero("Ingrese:\n0. SI NO GANO UN OSCAR \n1. GANO UN OSCAR", "Error, reingrese:\n0. SI NO GANO UN OSCAR \n1. GANO UN OSCAR", 0, 1, 5, &unaPelicula.oscar);

	return unaPelicula;
}

int ValidarDirectores(eDirector directores[], int size)
{
	int aux;

	mostrarListaDirectores(directores, size);
	validarEntero("Ingrese el id del director de la pelicula: \n", "Error, reingrese el id del director de la pelicula: \n", 1, 500, 5,&aux);
	for(int i=0; i<size; i++)
	{
		if(directores[i].id == aux)
		{
			aux = directores[i].id;
		}
	}

	return aux;
}


int CrearListaPeliculas(ePelicula peliculas[], int size, eDirector directores[], int tam)
{
	int retorno;
	retorno = 1;

	for(int i=0; i<size; i++)
	{
		if(peliculas[i].empty != 1)
		{
			peliculas[i] = AltaPelicula(directores, tam);
			peliculas[i].empty = 1;
			retorno = 0;
		}

	}

	if(retorno == 1)
	{
		printf("No se puede agregar una pelicula a la lista..\n");
	}

	return retorno;
}

void CalcularRecaudacion(ePelicula lista[], int size)
{

	srand(time(0));

	for(int i = 0; i < size; i++){

		lista[i].recaudacion = (rand() % (750 - 150 + 1) + 150) * 1000000;
	}
}

ePelicula traerPeliculaCodigo(ePelicula peliculas[], int size, char* mensaje)
{
	int flag = 0;
	int id;
	ePelicula peliculaAux;

	mostrarListaPeliculas(peliculas, size);
	validarEntero(mensaje,"Error, reingrese el id: \n", 0, 500, 5, &id);

	for(int i=0; i<size; i++)
	{
		if(id == peliculas[i].codigo && peliculas[i].empty == 1)
		{
			printf("La pelicula que usted ingreso es: \n");
			mostrarUnaPelicula(peliculas[i]);
			peliculaAux = peliculas[i];
			flag = 1;
		}
	}

	if(flag == 0)
	{
		printf("La pelicula no existe..\n");
	}

	return peliculaAux;
}

void mostrarListaDirectores(eDirector directores[], int size)
{
	for(int i=0; i<size;i++)
	{
		printf("%d -- %s -- %d \n", directores[i].id, directores[i].nombre, directores[i].edad);
	}
}

void mostrarUnaPelicula(ePelicula pelicula)
{
	printf("%d -- %s -- %d -- %d -- %2.f -- %d/%d/%d -- %d \n", pelicula.codigo, pelicula.titulo, pelicula.duracion, pelicula.idDirector, pelicula.recaudacion, pelicula.fechaDeEstreno.dia,  pelicula.fechaDeEstreno.mes,  pelicula.fechaDeEstreno.anio, pelicula.oscar);
}

void mostrarListaPeliculas(ePelicula peliculas[], int size)
{
	for(int i=0; i<size; i++)
	{
		if(peliculas[i].empty == 1)
		{
			mostrarUnaPelicula(peliculas[i]);
		}
	}
}
