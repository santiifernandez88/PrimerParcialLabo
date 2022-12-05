#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nexo.h"
#include "menu.h"

#define SIZE 4
#define TAM 3
#define LARGO 3

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int opcionActores;
	int opcionPeliculas;

	eActor listaActores[SIZE] = {{1,"Santiago","Fernandez","Batman",202,170000,{10,10,2024},{10,12,2028},1,1000,1},
								 {2,"francisco","Fernandez","superman",201,150000,{10,10,2024},{10,12,2028},1,1000,1},
								 {3,"gerardo","Fernandez","spiderman",200,190000,{10,10,2024},{10,12,2028},1,1000,1},
								 {4,"jorge","Fernandez","hitmamn",201,15000,{10,10,2015},{10,12,2028},0,1000,1}};

	ePelicula listaPeliculas[TAM] = {{1000, "Hulk y She Hulk", 120, 100, 150000,{1,3,2030},1,1},
									  {1001, "Doctor Strange 5", 100, 101, 265000,{1,7,2035},1,1},
									  {1002, "thor", 90,102,250000,{1,1,2025},1,1}};

	eDirector listaDirectores[LARGO] = {{100, "Jose", 54},
										{101, "Manuel", 39},
										{102, "Galo", 57}};

	eRol listaDeRoles[LARGO] = {{200, "Heroe"},
								{201, "Villano"},
								{202, "Secundario"}};

	do
	{
		opcion = menuPrincipal();

		switch(opcion)
		{
			case 1:
				opcionActores = subMenuGestionActores();
				switch(opcionActores)
				{
					case 1:
						if(crearListaActores(listaActores,listaPeliculas,SIZE, TAM, listaDeRoles, LARGO) == 0)
						{
							printf("Se pudo agregar correctamente el actor a la lista.\n");
						}
						break;
					case 2:
						eliminarUnActor(listaActores, SIZE, listaPeliculas,listaDeRoles,TAM,LARGO);
						break;
					case 3:
						modificarActor(listaActores, SIZE, listaPeliculas, TAM, listaDeRoles, LARGO);
						break;
				}
				break;
			case 2:
				opcionPeliculas = subMenuGestionPeliculas();
				switch(opcionPeliculas)
				{
					case 1:
						if(CrearListaPeliculas(listaPeliculas, TAM, listaDirectores, LARGO) == 0)
						{
							printf("Se agrego la pelicula correctamente.\n");
						}
						break;
					case 2:
						bajaDePeliculas(listaPeliculas, TAM, listaActores, SIZE);
						break;
					case 3:
						CalcularRecaudacion(listaPeliculas, TAM);
						break;
				}
				break;
			case 3:
				menuInformes(listaActores, listaPeliculas, listaDeRoles, listaDirectores, SIZE, TAM, LARGO);
				break;
			case 4:
				printf("Gracias por utilizar nuestro programa y por pasar por MARIANVEL STUDIOS!!!.\n");
				break;
		}

	}while(opcion != 4);

	mostrarListaPeliculas(listaPeliculas, TAM);

	return 0;
}

