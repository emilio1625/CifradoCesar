//
// Created by Emilio on 05/05/2016.
//

#include <stdio.h>
#include "Decodificar.h"

int main (int argc, char **argv) {
	int num_contactos;
	contacto *ap_lista_contactos;
	FILE *ap_archivo;

	presentacion ();
	getchar ();
	system (CLEAR);

	printf ("\t\t\t     Bienvenido de nuevo! :D");
	ap_archivo = fopen (RUTA_ARCHIVO, "r");
	num_contactos = contarRenglones (ap_archivo);
	printf ("%d", num_contactos);
	getchar ();
	return 0;
}
