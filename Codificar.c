//
// Created by Emilio on 03/05/2016.
//

#include <stdio.h>
#include "Codificar.h"

int main (int argc, char **argv) {
	int num_contactos = 0;
	contacto *ap_lista_contactos;
	FILE *ap_archivo;

	presentacion();
	getchar ();
	system (CLEAR);

	printf ("\t\t\t      Bienvenido de nuevo!\n");
	printf ("\t%cCu%cntos contactos deseas a%cadir%c:\t", 168, 160, 164, 63);
	scanf ("%d",&num_contactos);
	getchar ();
	system (CLEAR);
	ap_lista_contactos = crearArreglo (num_contactos);
	leeContacto (ap_lista_contactos, num_contactos);


	printf ("Guardando tus contactos!!\n");
	printf ("No cierres el programa D;\n");
	ap_archivo = fopen (RUTA_ARCHIVO, "a");
	if (ap_archivo == NULL) {
		printf ("Error abriendo el archivo D;\n\t");
	} else {
		printf ("\tCodificando contactos...\n");
		codificar (ap_lista_contactos, num_contactos);
		printf ("\tGuardando archivo...\n");
		grabarArchivo (ap_archivo, ap_lista_contactos, num_contactos);
		fclose (ap_archivo);
		printf ("Contactos guardados :D\n");
	}

	printf ("Hasta luego!! ;D");
	getchar ();
	return  0;
}