#include "nexo.h"

void PeliculasOrdenadasPorFecha(ePelicula lista[], int size, eActor listaActor[], int sizeActor)
{
	ePelicula auxLista;

	for(int i = 0; i < sizeActor-1; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if (lista[i].fechaDeEstreno.anio > lista[j].fechaDeEstreno.anio)
			{
						auxLista = lista[i];
						lista[i] = lista[j];
						lista[j] = auxLista;
			}
			if (lista[i].fechaDeEstreno.anio == lista[j].fechaDeEstreno.anio)
			{
				if(lista[i].fechaDeEstreno.mes > lista[j].fechaDeEstreno.mes)
				{

					auxLista = lista[i];
					lista[i] = lista[j];
					lista[j] = auxLista;
				 }
			}
			if(lista[i].fechaDeEstreno.anio == lista[j].fechaDeEstreno.anio)
			{
				if(lista[i].fechaDeEstreno.mes == lista[j].fechaDeEstreno.mes)
				{
					if(lista[i].fechaDeEstreno.dia > lista[j].fechaDeEstreno.dia)
					{
						auxLista = lista[i];
						lista[i] = lista[j];
						lista[j] = auxLista;
					}
				}
			}
		}
	}
	mostrarListaPeliculas(lista, size);
}

void ListarPeliculasRecaudacionDuracion(ePelicula lista[], int size, eActor listaActor[], int sizeActor)
{

	ePelicula auxLista;

	for(int i = 0; i < sizeActor-1; i++)
	{
		for(int j = i + 1; j < size; j++)
		{

			if (lista[i].recaudacion < lista[j].recaudacion)
			{
						auxLista = lista[i];
						lista[i] = lista[j];
						lista[j] = auxLista;
			}
			if(lista[i].recaudacion == lista[j].recaudacion )
			{
				if(lista[i].duracion < lista[j].duracion)
				{

						auxLista = lista[i];
						lista[i] = lista[j];
						lista[j] = auxLista;
				}
			}
		}
	}

	mostrarListaPeliculas(lista, size);
}

void PremiarActores(ePelicula lista[], eActor listaActor[], eRol listaRol[],int tam, int tamPeliculas, int tamRol)
{
	eRol auxRol;
	ePelicula auxPelicula;
	int num[5];
	int i;
	int numAleatorio;
	srand(time(0));


	for(i = 0; i < 4; i++)
	{
		numAleatorio =rand () % (4-0+1) + 0;

		while(NumeroRepetido(num, i, numAleatorio, tam) == 0)
		{
			numAleatorio =rand () % (4-0+1) + 0;
		}

		num[i] = numAleatorio;
		listaActor[numAleatorio].ganoOscar = 1;
		auxRol = buscarActorPorRol(listaRol, tamRol, listaActor[numAleatorio].idRol);
		auxPelicula = buscarActorPorPelicula(lista, tamPeliculas, listaActor[numAleatorio].codigoPelicula);
		mostrarActores(listaActor[numAleatorio], auxPelicula, auxRol);
	}
}

void ActoresYPeliculasGanadoresOscar(ePelicula lista[], int size, eActor listaActor[],int sizeActor,eRol listaRol[], int largo)
{
	ePelicula aux;
	eRol auxRol;

	for(int j = 0; j < sizeActor; j++)
	{
		aux = buscarActorPorPelicula(lista,size, listaActor[j].codigoPelicula);
		auxRol = buscarActorPorRol(listaRol,largo, listaActor[j].idRol);

		if(aux.oscar == 1 && listaActor[j].ganoOscar == 1)
		{
			mostrarActores(listaActor[j],aux, auxRol);
		}
	}
}

void ActoresOrdenadosPorRol(ePelicula lista[], eActor listaActor[], eRol listaRol[], int largo)
{
	eRol auxLista;

	for (int i = 0; i < largo - 1; i++)
	{

		for (int j = i + 1; j < largo; j++)
		{
			if (strcmp(listaRol[i].descripcion, listaRol[j].descripcion)>0)
			{
				auxLista = listaRol[i];
				listaRol[i] = listaRol[j];
				listaRol[j] = auxLista;
			}
		}
	}
}

void ListadoDeActoresOrdenadosPorRol(ePelicula lista[], eActor listaActor[], eRol listaRol[], int largo, int tam, int size)
{
	ActoresOrdenadosPorRol(lista, listaActor, listaRol, largo);
	for(int i=0; i<largo; i++)
	{
		buscarActorPorIdRol(listaActor, size, listaRol[i].id, lista,tam,listaRol[i]);
	}
}

void buscarActorPorIdRol(eActor actores[], int size, int index, ePelicula pelicula[],int tam,eRol rol)
{
	ePelicula miPelicula;

	for(int i=0;i<size; i++)
	{
		miPelicula = buscarActorPorPelicula(pelicula,tam,actores[i].codigoPelicula);
		if(actores[i].empty == 1 && actores[i].idRol ==  index)
		{
			mostrarActores(actores[i],miPelicula,rol);
		}
	}
}

void ActoresOrdenadosAlfabeticamente(ePelicula peliculas[], int size, eActor actores[], int sizeActor, eRol roles[], int largo)
{

	ePelicula auxLista;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(peliculas[i].titulo, peliculas[j].titulo)>0)
			{
				auxLista = peliculas[i];
				peliculas[i] = peliculas[j];
				peliculas[j] = auxLista;

			}
		}
	}
}

void mostrarActoresOrdenadosAlfabeticamenteTitulo(ePelicula peliculas[], int size, eActor actores[], int sizeActor, eRol roles[], int largo)
{
	ActoresOrdenadosAlfabeticamente(peliculas, size,actores,sizeActor, roles, largo);

	for(int i=0; i<size; i++)
	{
		buscarActorPorCodigoPelicula(actores,sizeActor,peliculas[i].codigo,peliculas[i],roles,largo);
	}
}

void mostrarActores(eActor unActor,ePelicula peliculas, eRol roles)
{

	if(unActor.empty == 1)
	{
		printf("%d -- %s -- %s -- %s -- %s -- %2.f -- %d/%d/%d -- %d/%d/%d -- %d -- %s\n", unActor.codigo, unActor.nombre, unActor.apellido, unActor.nombrePersonaje,
																						   roles.descripcion,unActor.valorMensualContrato,unActor.fechaInicialContrato.dia,
																						   unActor.fechaInicialContrato.mes, unActor.fechaInicialContrato.anio,
																						   unActor.fechaFinalContrato.dia,unActor.fechaFinalContrato.mes,unActor.fechaFinalContrato.anio,
																						   unActor.ganoOscar,peliculas.titulo);
	}
}

void buscarActorPorCodigoPelicula(eActor actores[], int size, int index, ePelicula pelicula,eRol roles[], int largo)
{
	eRol miRol;

	for(int i=0; i<size; i++)
	{
		miRol = buscarActorPorRol(roles, largo, actores[i].idRol);
		if(actores[i].empty == 1 && actores[i].codigoPelicula== index)
		{
			mostrarActores(actores[i], pelicula, miRol);
		}
	}
}

void listarActoresPorDirector(ePelicula peliculas[], int tam, eDirector directores[], int largo, eActor actores[], int size, eRol roles[])
{
	int aux;

	aux = ValidarDirectores(directores,largo);

	for(int i=0; i<tam; i++)
	{
		if(peliculas[i].idDirector == aux)
		{
			buscarActorPorCodigoPelicula(actores, size, peliculas[i].codigo, peliculas[i], roles, largo);
		}
	}
}

void listarActoresPorRolyDirector(ePelicula peliculas[], int tam, eDirector directores[], int largo, eActor actores[], int size, eRol roles[])
{
	int aux;

	aux = ValidarDirectores(directores,largo);

	for(int i=0; i<tam; i++)
	{
		if(peliculas[i].idDirector == aux)
		{
			ListadoDeActoresOrdenadosPorRol(peliculas, actores, roles, largo, tam, size);
		}
	}

}

eActor RetornarActorPorId(eActor lista[],int size, int index)
{
	eActor aux;

    for(int i=0;i<size;i++)
    {
        if(lista[i].empty == 1 && lista[i].codigoPelicula == index)
        {
            aux = lista[i];
            break;
        }
    }

    return aux;
}

void CalcularGastosPelicula(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[])
{
	eActor aux;
	int contrato;

	for(int j = 0; j < size; j++)
	{
		aux = RetornarActorPorId(listaActor,sizeActor,lista[j].codigo);
		contrato = CalcularGananciasTotalesDelContrato(aux);

		if(lista[j].codigo == aux.codigoPelicula)
		{
			lista[j].recaudacion = lista[j].recaudacion - contrato;
		}
	}

	mostrarListaPeliculas(lista, size);
}

void DesemplearActor(eActor listaActor[], int size, int index)
{
    for(int i = 0; i<size;i++)
    {
        if(listaActor[i].codigoPelicula == index)
        {
        	listaActor[i].codigoPelicula = 0;
        }
    }
}

int bajaDePeliculas(ePelicula peliculas[], int size, eActor actores[], int sizeActor)
{
	int retorno;
	retorno = 1;
	ePelicula peliculaAEliminar;
	int respuesta;

	peliculaAEliminar = traerPeliculaCodigo(peliculas, size, "Ingrese el id de la pelicula: \n");
	for(int i=0; i<size; i++)
	{
		if(peliculaAEliminar.codigo == peliculas[i].codigo && peliculas[i].empty == 1)
		{
			validarEntero("Si usted esta seguro que quiere ELIMINAR la pelicula, presione:\n1.CONFIRMAR\n2.SALIR\n","Error, reingrese la opcion presione: \n1.CONFIRMAR\n2.SALIR\n", 1, 2, 5, &respuesta);
			if(respuesta == 1)
			{
				peliculas[i].empty = 0;
				printf("La pelicula se dio de baja correctamente.\n");
				DesemplearActor(actores, sizeActor, peliculas[i].codigo);
				retorno = 0;
			}
		}
	}

	return retorno;
}

void menuInformes(eActor actores[], ePelicula peliculas[], eRol roles[], eDirector directores[], int size, int tam, int largo)
{
	int opcion;

	opcion = subMenuGestionInformes();

	switch(opcion)
	{
	case 1:
		mostrarActoresOrdenadosAlfabeticamenteTitulo(peliculas, tam, actores, size, roles,largo);
		break;
	case 2:
		OrdenarActoresPorValorMensualContrato(peliculas, size, actores, roles, largo);
		break;
	case 3:
		PremiarActores(peliculas, actores, roles,size, tam, largo);
		break;
	case 4:
		ActoresYPeliculasGanadoresOscar(peliculas, tam, actores,size,roles, largo);
		break;
	case 5:
		PeliculasOrdenadasPorFecha(peliculas, tam, actores, size);
		break;
	case 6:
		ListadoDeActoresOrdenadosPorRol(peliculas, actores, roles, largo, tam, size);
		break;
	case 7:
		ListarPeliculasRecaudacionDuracion(peliculas, tam, actores, size);
		break;
	case 8:

		break;
	case 9:
		listarActoresPorDirector(peliculas, tam, directores, largo, actores, size, roles);
		break;
	case 10:
		listarActoresPorRolyDirector(peliculas, tam, directores, largo, actores, size, roles);
		break;
	}
}
