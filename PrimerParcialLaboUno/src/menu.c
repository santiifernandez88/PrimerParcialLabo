#include "menu.h"

int menuPrincipal()
{
	int opcion;

	validarEntero("\n\n \t\t---------------- MARANVEL STUDIOS ----------------\t\t\n\n\n"
								"1) GESTION DE ACTORES.\n"
								"2) GESTION DE PELICULAS.\n"
								"3) INFORMES.\n"
								"4) SALIR.\n"
								"Elija la opcion del menu a la que quiera ingresar: \n", "Error, reingrese la opcion valida.\n", 1, 4, 5, &opcion);

	return opcion;
}

int subMenuGestionActores()
{
	int opcion;

	validarEntero("1) Alta de actores.\n"
				  "2) Baja de actores.\n"
				  "3) Modificar un actor.\n"
				  "Elija la opcion del menu a la que quiera ingresar: \n", "Error, reingrese la opcion valida.\n", 1, 3, 5, &opcion);

	return opcion;
}

int subMenuGestionPeliculas()
{
	int opcion;

	validarEntero("1) Alta de peliculas.\n"
				  "2) Baja de pelicula.\n"
				  "3) Calcular recaudacion de las peliculas.\n"
				  "Elija la opcion del menu a la que quiera ingresar: \n", "Error, reingrese la opcion valida.\n", 1, 3, 5, &opcion);

	return opcion;
}

int subMenuGestionInformes()
{
	int opcion;

	validarEntero("1. Listado de todos los actores ordenados alfabéticamente por título de la película.\n"
				  "2. Listado de los actores ordenados por valor mensual del contrato.\n"
				  "3. Premiar actores.\n"
				  "4. Listado a los actores que hayan recibido un Oscar y que además hayan participado de una película que también haya sido ganadora.\n"
				  "5. Listado de películas ordenadas por fecha de estreno.\n"
				  "6. Listado de las películas con todos sus personajes ordenados por rol.\n"
				  "7. Listado de las películas estrenadas por recaudación y duración.\n"
				  "8. Que pelicula tuvieron ganancias o perdidas.\n"
				  "9. Listado de los actores que fueron dirigidos por el director ingresado en una pelicula.\n"
				  "10. Listado de los actores por rol que fueron dirigidos por un director ingresado en una pelicula.\n","Error, reingrese la opcion: \n"
				 													 "1. Listado de todos los actores ordenados alfabéticamente por título de la película.\n"
																	 "2. Listado de los actores ordenados por valor mensual del contrato.\n"
																	 "3. Premiar actores.\n"
																	 "4. Listado a los actores que hayan recibido un Oscar y que además hayan participado de una película que también haya sido ganadora.\n"
																	 "5. Listado de películas ordenadas por fecha de estreno.\n"
																	 "6. Listado de las películas con todos sus personajes ordenados por rol.\n"
				  	  	  	  	  	  	  	  	  	  	  	  	  	 "7. Listado de las películas estrenadas por recaudación y duración.\n"
																	 "8. Que pelicula tuvieron ganancias o perdidas.\n"
				  	  	  	  	  	  	  	  	  	  	  	  	  	 "9. Listado de los actores que fueron dirigidos por el director ingresado en una pelicula.\n"
				  				  	  	  	  	  	  	  	  	  	 "10. Listado de los actores por rol que fueron dirigidos por un director ingresado en una pelicula.\n", 1,10,5,&opcion);


	return opcion;
}


