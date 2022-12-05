#include "actores.h"
#include <time.h>
#include "menu.h"

/// @fn void PeliculasOrdenadasPorFecha(ePelicula[], int, eActor[], int)
/// @brief  ordena las peliculas por fecha y las muestra
///
/// @param lista
/// @param size
/// @param listaActor
/// @param sizeActor
void PeliculasOrdenadasPorFecha(ePelicula lista[], int size, eActor listaActor[], int sizeActor);
/// @fn void ListarPeliculasRecaudacionDuracion(ePelicula[], int, eActor[], int)
/// @brief ordena las peliculas por recaudacion y duracion y las muestra
///
/// @param lista
/// @param size
/// @param listaActor
/// @param sizeActor
void ListarPeliculasRecaudacionDuracion(ePelicula lista[], int size, eActor listaActor[], int sizeActor);
/// @fn void PremiarActores(ePelicula[], eActor[], eRol[], int, int, int)
/// @brief premia actores aleatoriamente
///
/// @param lista
/// @param listaActor
/// @param listaRol
/// @param tam
/// @param tamPeliculas
/// @param tamRol
void PremiarActores(ePelicula lista[], eActor listaActor[], eRol listaRol[],int tam, int tamPeliculas, int tamRol);
/// @fn void ActoresYPeliculasGanadoresOscar(ePelicula[], int, eActor[], int, eRol[], int)
/// @brief muestra los actores que hayan ganado un oscar y su pelicula tambien
///
/// @param lista
/// @param size
/// @param listaActor
/// @param sizeActor
/// @param listaRol
/// @param largo
void ActoresYPeliculasGanadoresOscar(ePelicula lista[], int size, eActor listaActor[],int sizeActor,eRol listaRol[], int largo);
/// @fn void ActoresOrdenadosPorRol(ePelicula[], eActor[], eRol[], int)
/// @brief ordena los actores por rol
///
/// @param lista
/// @param listaActor
/// @param listaRol
/// @param largo
void ActoresOrdenadosPorRol(ePelicula lista[], eActor listaActor[], eRol listaRol[], int largo);
/// @fn void ListadoDeActoresOrdenadosPorRol(ePelicula[], eActor[], eRol[], int, int, int)
/// @brief  lista los actores ordenados por rol
///
/// @param lista
/// @param listaActor
/// @param listaRol
/// @param largo
/// @param tam
/// @param size
void ListadoDeActoresOrdenadosPorRol(ePelicula lista[], eActor listaActor[], eRol listaRol[], int largo, int tam, int size);
/// @fn void buscarActorPorIdRol(eActor[], int, int, ePelicula[], int, eRol)
/// @brief busca un actor por id de rol y los muestra
///
/// @param actores
/// @param size
/// @param index
/// @param pelicula
/// @param tam
/// @param rol
void buscarActorPorIdRol(eActor actores[], int size, int index, ePelicula pelicula[],int tam,eRol rol);
/// @fn void ActoresOrdenadosAlfabeticamente(ePelicula[], int, eActor[], int, eRol[], int)
/// @brief ordena las peliculas alfabeticamente
///
/// @param peliculas
/// @param size
/// @param actores
/// @param sizeActor
/// @param roles
/// @param largo
void ActoresOrdenadosAlfabeticamente(ePelicula peliculas[], int size, eActor actores[], int sizeActor, eRol roles[], int largo);
/// @fn void mostrarActoresOrdenadosAlfabeticamenteTitulo(ePelicula[], int, eActor[], int, eRol[], int)
/// @brief  muestra y ordena los actores ordenados alfabeticamente por titulo
///
/// @param peliculas
/// @param size
/// @param actores
/// @param sizeActor
/// @param roles
/// @param largo
void mostrarActoresOrdenadosAlfabeticamenteTitulo(ePelicula peliculas[], int size, eActor actores[], int sizeActor, eRol roles[], int largo);
/// @fn void mostrarActores(eActor, ePelicula, eRol)
/// @brief  muestra un actor
///
/// @param unActor
/// @param peliculas
/// @param roles
void mostrarActores(eActor unActor,ePelicula peliculas, eRol roles);
/// @fn void buscarActorPorCodigoPelicula(eActor[], int, int, ePelicula, eRol[], int)
/// @brief busca un actor por codigo de pelicula y los muestra
///
/// @param actores
/// @param size
/// @param index
/// @param pelicula
/// @param roles
/// @param largo
void buscarActorPorCodigoPelicula(eActor actores[], int size, int index, ePelicula pelicula,eRol roles[], int largo);
/// @fn void listarActoresPorDirector(ePelicula[], int, eDirector[], int, eActor[], int, eRol[])
/// @brief valida los directores y muestra los actores que trabajen con ese director validado
///
/// @param peliculas
/// @param tam
/// @param directores
/// @param largo
/// @param actores
/// @param size
/// @param roles
void listarActoresPorDirector(ePelicula peliculas[], int tam, eDirector directores[], int largo, eActor actores[], int size, eRol roles[]);
/// @fn void listarActoresPorRolyDirector(ePelicula[], int, eDirector[], int, eActor[], int, eRol[])
/// @brief  lista los actores por rol y que trabajen con el director que ingresa el usuario
///
/// @param peliculas
/// @param tam
/// @param directores
/// @param largo
/// @param actores
/// @param size
/// @param roles
void listarActoresPorRolyDirector(ePelicula peliculas[], int tam, eDirector directores[], int largo, eActor actores[], int size, eRol roles[]);
/// @fn eActor RetornarActorPorId(eActor[], int, int)
/// @brief retorna un actor por id
///
/// @param lista
/// @param size
/// @param index
/// @return un actor encontrado por su id
eActor RetornarActorPorId(eActor lista[],int size, int index);
/// @fn void CalcularGastosPelicula(ePelicula[], int, eActor[], int, eRol[])
/// @brief calcula los gastos de las peliculas y los muestra
///
/// @param lista
/// @param size
/// @param listaActor
/// @param sizeActor
/// @param listaRol
void CalcularGastosPelicula(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]);
/// @fn int bajaDePeliculas(ePelicula[], int, eActor[], int)
/// @brief muestra la lista de peliculas pide el ingreso de un id de una pelicula en especifica y hace una baja logica
///
/// @param peliculas
/// @param size
/// @param actores
/// @param sizeActor
/// @return retorna 1 si no se pudo dar de baja la pelicula o 0 si es que se pudo dar de baja la pelicula
int bajaDePeliculas(ePelicula peliculas[], int size, eActor actores[], int sizeActor);
/// @fn void DesemplearActor(eActor[], int, int)
/// @brief desemplea un actor de una pelicula
///
/// @param listaActor
/// @param size
/// @param index
void DesemplearActor(eActor listaActor[], int size, int index);
/// @fn void menuInformes(eActor[], ePelicula[], eRol[], eDirector[], int, int, int)
/// @brief pide el ingreso de un numero para las opciones del menu de informes y se cumple la funcion que pida el usuario
///
/// @param actores
/// @param peliculas
/// @param roles
/// @param directores
/// @param size
/// @param tam
/// @param largo
void menuInformes(eActor actores[], ePelicula peliculas[], eRol roles[], eDirector directores[], int size, int tam, int largo);
