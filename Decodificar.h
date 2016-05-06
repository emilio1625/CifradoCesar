//
// Created by Emilio on 05/05/2016.
//

#ifndef PROYECTOHUICHO_DECODIFICAR_H
	#define PROYECTOHUICHO_DECODIFICAR_H
#endif //PROYECTOHUICHO_DECODIFICAR_H

#include "codificar.h"

int contarRenglones (FILE * ap_archivo) {
	int renglones = 0;
	unsigned char temp;
	while (!feof (ap_archivo)) {
		fscanf (ap_archivo, "%*[^\n]\n");
		renglones++;
	}
	rewind (ap_archivo);
	return renglones;
}

void cargarArchivo (FILE *ap_archivo, contacto *ap_lista_contactos) {
	while (!feof(ap_archivo)) {
		fscanf (ap_archivo, " %50[^\t]\t%10[^\t]\t%8[^\t]\t%[^\n]\n",
		        ap_lista_contactos -> nombre,
		        ap_lista_contactos -> celular,
		        ap_lista_contactos -> num_casa,
		        ap_lista_contactos -> correo
		);
	}
	rewind (ap_archivo);
}


