
#include "peliculas.h"
#include "inputs.h"

typedef struct
{
	int codigo;
	char nombre[100];
	char apellido[100];
	char nombrePersonaje[100];
	int idRol;
	float valorMensualContrato;
	eFecha fechaInicialContrato;
	eFecha fechaFinalContrato;
	int ganoOscar;
	int codigoPelicula;
	int empty;

}eActor;

typedef struct
{
	int id;
	char descripcion[100];
}eRol;


/// @fn int GenerarCodigo()
/// @brief genera un id autoincremental
///
/// @return el id autoincremental
int GenerarCodigo();
/// @fn eActor crearUnActor(ePelicula[], int, eRol[], int)
/// @brief  crea un actor
///
/// @param peliculas
/// @param size
/// @param rol
/// @param tam
/// @return un actor creado
eActor crearUnActor(ePelicula peliculas[], int size, eRol rol[], int tam);
/// @fn int crearListaActores(eActor[], ePelicula[], int, int, eRol[], int)
/// @brief crea una lista de actores
///
/// @param actores
/// @param peliculas
/// @param size
/// @param tam
/// @param rol
/// @param largo
/// @return retorna 0 si se pudo crear exitosamente y -1 si no lo fue
int crearListaActores(eActor actores[],ePelicula peliculas[], int size, int tam, eRol rol[], int largo);
/// @fn void mostrarTodoDeUnActor(eActor, ePelicula[], eRol[], int, int)
/// @brief muestra todos los campos de un actor ingresando los datos
///
/// @param unActor
/// @param peliculas
/// @param roles
/// @param tam
/// @param largo
void mostrarTodoDeUnActor(eActor unActor,ePelicula peliculas[], eRol roles[],int tam, int largo);
/// @fn void mostrarTodoDeUnaListaActores(eActor[], ePelicula[], eRol[], int, int, int)
/// @brief  muestra la lista de actores utilizando la funcion mostrarTodoDeUnActor
///
/// @param actores
/// @param peliculas
/// @param roles
/// @param size
/// @param tam
/// @param largo
void mostrarTodoDeUnaListaActores(eActor actores[], ePelicula peliculas[], eRol roles[],int size, int tam, int largo);
/// @fn int eliminarUnActor(eActor[], int, ePelicula[], eRol[], int, int)
/// @brief elimina un actor de la lista
///
/// @param actores
/// @param size
/// @param peliculas
/// @param roles
/// @param tam
/// @param largo
/// @return retorna 0 si se elimino correctamente, y -1 si no se pudo eliminar
int eliminarUnActor(eActor actores[], int size, ePelicula peliculas[], eRol roles[], int tam, int largo);
/// @fn eActor traerActorPorCodigo(eActor[], int, char*, ePelicula[], eRol[], int, int)
/// @brief muestra todos los actores y traes el actor por id que ingresa el usuario
///
/// @param actores
/// @param size
/// @param mensaje
/// @param peliculas
/// @param roles
/// @param tam
/// @param largo
/// @return el actor encontrado
eActor traerActorPorCodigo(eActor actores[], int size, char* mensaje, ePelicula peliculas[], eRol roles[], int tam, int largo);
/// @fn eRol buscarActorPorRol(eRol[], int, int)
/// @brief busca un actor por rol
///
/// @param roles
/// @param size
/// @param indice
/// @return el rol encontrado
eRol buscarActorPorRol(eRol roles[], int size, int indice);
/// @fn ePelicula buscarActorPorPelicula(ePelicula[], int, int)
/// @brief  busca una pelicula y la retorna
///
/// @param peliculas
/// @param size
/// @param indice
/// @return la pelicula encontrada
ePelicula buscarActorPorPelicula(ePelicula peliculas[],int size, int indice);
/// @fn int modificarActor(eActor[], int, ePelicula[], int, eRol[], int)
/// @brief muestra los actores y elige que campo modificar del actor ingresado por el usuario
///
/// @param actores
/// @param size
/// @param peliculas
/// @param tam
/// @param rol
/// @param largo
/// @return 0 si se pudo modificar correctamente y -1 lo contrario
int modificarActor(eActor actores[], int size, ePelicula peliculas[], int tam, eRol rol[], int largo);
/// @fn int validarPeliculaActor(ePelicula[], int)
/// @brief muestra todas las peliculas y se ingresa un id que se valida con las peliculas existentes y se retorna
///
/// @param peliculas
/// @param size
/// @return el id de la pelicula validada
int validarPeliculaActor(ePelicula peliculas[], int size);
/// @fn void mostrarListaRol(eRol[], int)
/// @brief muestra la lista de roles
///
/// @param rol
/// @param size
void mostrarListaRol(eRol rol[], int size);
/// @fn int validarRol(eRol[], int)
/// @brief muestra todos los roles y se ingresa un id que se valida con los roles existentes y se retorna
///
/// @param rol
/// @param size
/// @return el id del rol existente
int validarRol(eRol rol[], int size);
/// @fn int DuracionEnMeses(eActor)
/// @brief diferencia entre la fecha de inicio del contrato y la fecha final
///
/// @param lista
/// @return los meses de diferencia en total entre las dos fechas
int DuracionEnMeses(eActor lista);
/// @fn void MostrarGanancias(eActor, int, eRol)
/// @brief muestra ciertos campos de la estructura eActor y muestra la ganancia
///
/// @param listaActor
/// @param contrato
/// @param listaRol
void MostrarGanancias(eActor listaActor, int contrato, eRol listaRol);
/// @fn void OrdenarActoresPorValorMensualContrato(ePelicula[], int, eActor[], eRol[], int)
/// @brief ordena los actores por valor mensual del contrato
///
/// @param lista
/// @param sizeActor
/// @param listaActor
/// @param listaRol
/// @param largo
void OrdenarActoresPorValorMensualContrato(ePelicula lista[], int sizeActor, eActor listaActor[], eRol listaRol[], int largo);
/// @fn void ListadoPorValorDelContrato(ePelicula[], eActor[], int, eRol[])
/// @brief ordena los listados por valor de contrato
///
/// @param lista
/// @param listaActor
/// @param sizeActor
/// @param listaRol
void ListadoPorValorDelContrato(ePelicula lista[], eActor listaActor[], int sizeActor, eRol listaRol[]);
/// @fn float CalcularGananciasTotalesDelContrato(eActor)
/// @brief calcula las ganancias totales de los contratos de los actores
///
/// @param actor
/// @return
float CalcularGananciasTotalesDelContrato(eActor actor);


