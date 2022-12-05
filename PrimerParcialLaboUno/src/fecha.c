#include "fecha.h"


int ValidarDia(int mes, char mensaje[])
{
	int dia;

	switch(mes)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 11:
		validarEntero(mensaje, "Error, reingrese el dia: \n", 1, 31, 5, &dia);
		break;
	case 4:
	case 6:
	case 9:
	case 12:
		validarEntero(mensaje, "Error, reingrese el dia: \n", 1, 30, 5, &dia);
		break;
	case 2:
		validarEntero(mensaje, "Error, reingrese el dia: \n", 1, 28, 5, &dia);
		break;
	}



	return dia;
}

