#include "actores.h"

int GenerarCodigo()
{
	static int codigoIncremental = 5;
	return codigoIncremental++;
}

eActor crearUnActor(ePelicula peliculas[], int size, eRol rol[], int tam)
{
	eActor unActor;

	unActor.codigo = GenerarCodigo();
	utn_getOnlyString("Ingrese el nombre del actor: \n", "Error, reingrese el nombre del actor: \n", 5,  100, unActor.nombre);
	utn_getOnlyString("Ingrese el apellido del actor: \n", "Error, reingrese el apellido del actor: \n", 5,  100, unActor.apellido);
	utn_getOnlyString("Ingrese el nombre del personaje: \n", "Error, reingrese el nombre del personaje: \n", 5,  100, unActor.nombrePersonaje);
	unActor.idRol = validarRol(rol, tam);
	unActor.valorMensualContrato = getValidFloat("Ingrese el valor mensual del contrato; \n","Error,reingrese el valor mensual del contrato; \n");
	validarEntero("Ingrese el año de inicio del contrato: \n", "Error, reingrese el año de inicio del contrato: \n",2022,2030,5,&unActor.fechaInicialContrato.anio);
	validarEntero("Ingrese el mes de inicio del contrato: \n", "Error, reingrese el mes de inicio del contrato: \n",1,12,5,&unActor.fechaInicialContrato.mes);
	unActor.fechaInicialContrato.dia = ValidarDia(unActor.fechaInicialContrato.mes, "Ingrese el dia de inicio del contrato: \n");
	validarEntero("Ingrese el año de finalizacion del contrato: \n", "Error, reingrese el año de finalizacion del contrato: \n",unActor.fechaInicialContrato.anio,2050,5,&unActor.fechaFinalContrato.anio);
	validarEntero("Ingrese el mes de finalizacion del contrato: \n", "Error, reingrese el mes de finalizacion del contrato: \n",1,12,5,&unActor.fechaFinalContrato.mes);
	unActor.fechaFinalContrato.dia = ValidarDia(unActor.fechaFinalContrato.mes, "Ingrese el dia de inicio del contrato: \n");
	validarEntero("Ingrese:\n0. SI NO GANO UN OSCAR \n1. GANO UN OSCAR", "Error, reingrese:\n0. SI NO GANO UN OSCAR \n1. GANO UN OSCAR", 0, 1, 5, &unActor.ganoOscar);
	unActor.codigoPelicula = validarPeliculaActor(peliculas,size);

	return unActor;
}

int validarPeliculaActor(ePelicula peliculas[], int size)
{
	int aux;

	mostrarListaPeliculas(peliculas, size);
	validarEntero("Ingrese el codigo de la pelicula en la que va actuar: \n", "Error, reingrese el codigo de la pelicula en la que va actuar: \n", 1, 500, 5,&aux);
	for(int i=0; i<size; i++)
	{
		if(peliculas[i].codigo == aux)
		{
			aux = peliculas[i].codigo;
		}
	}

	return aux;
}

void mostrarListaRol(eRol rol[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%4d \t--\t %20s \n", rol[i].id, rol[i].descripcion);
	}
}

int validarRol(eRol rol[], int size)
{
	int aux;

	mostrarListaRol(rol, size);
	validarEntero("Ingrese el id del rol del personaje: \n", "Error, reingrese el id del rol del personaje: \n", 200, 203, 5,&aux);
	for(int i=0; i<size; i++)
	{
		if(rol[i].id == aux)
		{
			aux = rol[i].id;
		}
	}

	return aux;
}

int crearListaActores(eActor actores[],ePelicula peliculas[], int size, int tam, eRol rol[], int largo)
{
	int retorno;
	retorno = -1;

	for(int i=0; i < size; i++)
	{
		if(actores[i].empty != 1)
		{
			actores[i] = crearUnActor(peliculas, tam, rol, largo);
			actores[i].empty = 1;
			retorno = 0;
			break;
		}
	}

	if(retorno == 1)
	{
		printf("No hay suficiente espacio en la lista para seguir agregando...\n");
	}

	return retorno;
}

ePelicula buscarActorPorPelicula(ePelicula peliculas[],int size, int indice)
{
	ePelicula auxPelicula;

	for(int i=0; i<size; i++)
	{
		if(peliculas[i].empty == 1 && peliculas[i].codigo == indice)
		{
			auxPelicula = peliculas[i];
		}
	}

	return auxPelicula;
}

eRol buscarActorPorRol(eRol roles[], int size, int indice)
{
	eRol auxRol;

	for(int i=0; i<size; i++)
	{
		if(roles[i].id == indice)
		{
			auxRol = roles[i];
		}
	}

	return auxRol;
}

void mostrarTodoDeUnActor(eActor unActor,ePelicula peliculas[], eRol roles[],int tam, int largo)
{
	ePelicula unaPelicula;
	eRol miRol;

	unaPelicula = buscarActorPorPelicula(peliculas,tam, unActor.codigoPelicula);
	miRol = buscarActorPorRol(roles, largo, unActor.idRol);
	if(unActor.empty == 1)
	{
		printf("%d -- %s -- %s -- %s -- %s -- %2.f -- %d/%d/%d -- %d/%d/%d -- %d -- %s\n", unActor.codigo, unActor.nombre, unActor.apellido, unActor.nombrePersonaje,
																						   miRol.descripcion,unActor.valorMensualContrato,unActor.fechaInicialContrato.dia,
																						   unActor.fechaInicialContrato.mes, unActor.fechaInicialContrato.anio,
																						   unActor.fechaFinalContrato.dia,unActor.fechaFinalContrato.mes,unActor.fechaFinalContrato.anio,
																						   unActor.ganoOscar,unaPelicula.titulo);
	}


}

void mostrarTodoDeUnaListaActores(eActor actores[], ePelicula peliculas[], eRol roles[],int size,int tam, int largo)
{
	for(int i=0; i<size; i++)
	{
		mostrarTodoDeUnActor(actores[i],peliculas,roles,tam,largo);
	}
}

int eliminarUnActor(eActor actores[], int size, ePelicula peliculas[], eRol roles[], int tam, int largo)
{
	eActor actorAEliminar;
	int respuesta;
	int retorno;
	retorno = -1;

	actorAEliminar = traerActorPorCodigo(actores, size, "Ingrese el id del actor que quiera eliminar: \n", peliculas, roles, tam, largo);
	for(int i=0; i<size; i++)
	{
		if(actorAEliminar.codigo == actores[i].codigo && actorAEliminar.empty == 1)
		{
			validarEntero("Si usted esta seguro que quiere ELIMINAR el actor, presione:\n1.CONFIRMAR\n2.SALIR\n","Error, reingrese la opcion presione: \n1.CONFIRMAR\n2.SALIR\n", 1, 2, 5, &respuesta);
			if(respuesta == 1)
			{
				actores[i].empty = 0;
				printf("El jugador se elimino correctamente.\n");
				retorno = 0;
			}
		}
	}

	return retorno;
}

eActor traerActorPorCodigo(eActor actores[], int size, char* mensaje, ePelicula peliculas[], eRol roles[], int tam, int largo)
{
	int id;
	eActor actorAux;
	int flag = 0;

	mostrarTodoDeUnaListaActores(actores, peliculas, roles,size, tam, largo);
	validarEntero(mensaje,"Error, reingrese el id: \n", 0, 500, 5, &id);

	for(int i=0; i<size; i++)
	{
		if(id == actores[i].codigo && actores[i].empty == 1)
		{
			printf("El actor que usted ingreso es: \n");
			mostrarTodoDeUnActor(actores[i],peliculas,roles,tam,largo);
			actorAux = actores[i];
			flag = 1;
			break;
		}
	}

	if(flag == 0)
	{
		printf("El actor no existe...\n");
	}

	return actorAux;
}

int modificarActor(eActor actores[], int size, ePelicula peliculas[], int tam, eRol rol[], int largo)
{
	int retorno;
	eActor actorAModificar;
	int opcion;
	retorno = -1;

	actorAModificar = traerActorPorCodigo(actores, size, "Ingrese el id del actor a modificar: \n", peliculas, rol, tam, largo);
	validarEntero("Ingrese el numero del campo a modificar:"
					"\n1.NOMBRE"
					"\n2.APELLIDO"
					"\n3.NOMBRE DE PERSONAJE"
					"\n4.ROL DEL PERSONAJE"
					"\n5.VALOR MENSUAL DEL CONTRATO"
					"\n6.FECHA DE INICIO DEL CONTRATO"
					"\n7.FECHA DE FINALIZACION DEL CONTRATO"
					"\n8.SI GANO O NO UN OSCAR"
					"\n9.PELICULA EN LA QUE ACTUA","Error, reingrese la opcion correcta:"
													"\n1.NOMBRE"
													"\n2.APELLIDO"
													"\n3.NOMBRE DE PERSONAJE"
													"\n4.ROL DEL PERSONAJE"
													"\n5.VALOR MENSUAL DEL CONTRATO"
													"\n6.FECHA DE INICIO DEL CONTRATO"
													"\n7.FECHA DE FINALIZACION DEL CONTRATO"
													"\n8.SI GANO O NO UN OSCAR\n"
													"\n9.PELICULA EN LA QUE ACTUA", 1, 9, 5, &opcion);

	for(int i=0; i<size; i++)
	{
		if(actorAModificar.codigo == actores[i].codigo)
		{
			switch(opcion)
			{
			case 1:
				utn_getOnlyString("Ingrese el nombre del actor: \n", "Error, reingrese el nombre del actor: \n", 5,  100, actores[i].nombre);
				break;
			case 2:
				utn_getOnlyString("Ingrese el apellido del actor: \n", "Error, reingrese el apellido del actor: \n", 5,  100, actores[i].apellido);
				break;
			case 3:
				utn_getOnlyString("Ingrese el nombre del personaje: \n", "Error, reingrese el nombre del personaje: \n", 5,  100, actores[i].nombrePersonaje);
				break;
			case 4:
				 actores[i].idRol = validarRol(rol,largo);
				break;
			case 5:
				actores[i].valorMensualContrato = getValidFloat("Ingrese el valor mensual del contrato; \n","Error,reingrese el valor mensual del contrato; \n");
				break;
			case 6:
				validarEntero("Ingrese el año de inicio del contrato: \n", "Error, reingrese el año de inicio del contrato: \n",2022,2030,5,&actores[i].fechaInicialContrato.anio);
				validarEntero("Ingrese el mes de inicio del contrato: \n", "Error, reingrese el mes de inicio del contrato: \n",1,12,5,&actores[i].fechaInicialContrato.mes);
				actores[i].fechaInicialContrato.dia = ValidarDia(actores[i].fechaInicialContrato.mes, "Ingrese el dia de inicio del contrato: \n");
				break;
			case 7:
				validarEntero("Ingrese el año de finalizacion del contrato: \n", "Error, reingrese el año de finalizacion del contrato: \n",actores[i].fechaInicialContrato.anio,2050,5,&actores[i].fechaFinalContrato.anio);
				validarEntero("Ingrese el mes de finalizacion del contrato: \n", "Error, reingrese el mes de finalizacion del contrato: \n",1,12,5,&actores[i].fechaFinalContrato.mes);
				actores[i].fechaFinalContrato.dia = ValidarDia(actores[i].fechaFinalContrato.mes, "Ingrese el dia de inicio del contrato: \n");
				break;
			case 8:
				validarEntero("Ingrese:\n0. SI NO GANO UN OSCAR \n1. GANO UN OSCAR", "Error, reingrese:\n0. SI NO GANO UN OSCAR \n1. GANO UN OSCAR", 0, 1, 5, &actores[i].ganoOscar);
				break;
			case 9:
				actores[i].codigoPelicula = validarPeliculaActor(peliculas,tam);
				break;
			}
			if(opcion > 0)
			{
				printf("Se modifico el actor correctamente.\n");
				retorno = 0;
			}
		}
	}

	return retorno;
}

int DuracionEnMeses(eActor lista)
{
	int meses;
	int anios;
	int retorno = -1;

	meses = lista.fechaFinalContrato.mes - lista.fechaInicialContrato.mes;
	anios = lista.fechaFinalContrato.anio - lista.fechaInicialContrato.anio;

	meses = (anios * 12) + meses;
	if(meses > 0)
	{
		retorno =  meses;
	}

	return retorno;
}

float CalcularGananciasTotalesDelContrato(eActor actor)
{
	int meses;
	float contrato;
	contrato = 0;
	meses = DuracionEnMeses(actor);
	if(meses != -1)
	{
		contrato = (actor.valorMensualContrato * meses);
	}

	return contrato;
}

void ListadoPorValorDelContrato(ePelicula lista[], eActor listaActor[], int sizeActor, eRol listaRol[])
{
	eActor auxLista;

	for (int i = 0; i < sizeActor - 1; i++)
	{
		for (int j = i + 1; j < sizeActor; j++)
		{
			if (listaActor[i].valorMensualContrato > listaActor[j].valorMensualContrato)
			{
				auxLista = listaActor[i];
				listaActor[i] = listaActor[j];
				listaActor[j] = auxLista;
			}
		}
	}
}

void OrdenarActoresPorValorMensualContrato(ePelicula lista[], int sizeActor, eActor listaActor[], eRol listaRol[], int largo)
{
	int ganancias;
	eRol auxRol;
	ListadoPorValorDelContrato(lista, listaActor, sizeActor, listaRol);

	for(int i = 0; i < sizeActor ; i++)
	{
		ganancias = CalcularGananciasTotalesDelContrato(listaActor[i]);
		auxRol = buscarActorPorRol(listaRol,largo, listaActor[i].idRol);
		MostrarGanancias(listaActor[i], ganancias, auxRol);
	}
}
void MostrarGanancias(eActor listaActor, int contrato, eRol listaRol)
{
	printf("%5s  %5s  \t%2.f \t%4d \t%10s\n" ,listaActor.nombre,listaActor.apellido,listaActor.valorMensualContrato,contrato ,listaRol.descripcion);
}

