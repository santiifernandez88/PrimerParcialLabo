
#include "fecha.h"

typedef struct
{
	int codigo;
	char titulo[100];
	int duracion;
	int idDirector;
	float recaudacion;
	eFecha fechaDeEstreno;
	int oscar;
	int empty;

}ePelicula;

typedef struct
{
	int id;
	char nombre[100];
	int edad;

}eDirector;


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "inputs.h"

/// @fn int GenerarCodigoPelicula()
/// @brief genera una id unica e irrepetible de las peliculas
///
/// @return el id generado
int GenerarCodigoPelicula();
/// @fn ePelicula AltaPelicula(eDirector[], int)
/// @brief  crea una pelicula
///
/// @param directores
/// @param size
/// @return retorna la pelicula creada
ePelicula AltaPelicula(eDirector directores[], int size);
/// @fn int ValidarDirectores(eDirector[], int)
/// @brief muestra todos los directores y se ingresa la id de un director existente para que diriga la pelicula
///
/// @param directores
/// @param size
/// @return se retorna la id del director
int ValidarDirectores(eDirector directores[], int size);
/// @fn void CalcularRecaudacion(ePelicula[], int)
/// @brief se calcula la recaudacion de la pelicula entre parametros
///
/// @param lista
/// @param size
void CalcularRecaudacion(ePelicula lista[], int size);
/// @fn ePelicula traerPeliculaCodigo(ePelicula[], int, char*)
/// @brief muestra todas las peliculas y se ingresa la id de una pelicula existente para retornar la pelicula ingresada
///
/// @param peliculas
/// @param size
/// @param mensaje
/// @return la pelicula que ingreso el usuario
ePelicula traerPeliculaCodigo(ePelicula peliculas[], int size, char* mensaje);
/// @fn int CrearListaPeliculas(ePelicula[], int, eDirector[], int)
/// @brief crea una lista de peliculas
///
/// @param peliculas
/// @param size
/// @param directores
/// @param tam
/// @return retorna 0 si se pudo crear efectivamente o 1 si es que pasa lo contrario
int CrearListaPeliculas(ePelicula peliculas[], int size, eDirector directores[], int tam);
/// @fn void mostrarUnaPelicula(ePelicula)
/// @brief muestra una pelicula
///
/// @param pelicula
void mostrarUnaPelicula(ePelicula pelicula);
/// @fn void mostrarListaPeliculas(ePelicula[], int)
/// @brief muestra la lista de peliculas
///
/// @param peliculas
/// @param size
void mostrarListaPeliculas(ePelicula peliculas[], int size);
/// @fn void mostrarListaDirectores(eDirector[], int)
/// @brief muestra la lista de directores
///
/// @param directores
/// @param size
void mostrarListaDirectores(eDirector directores[], int size);


