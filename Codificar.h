//
// Created by Emilio on 03/05/2016.
//

#ifndef PROYECTOHUICHO_CODIFICAR_H
	#define PROYECTOHUICHO_CODIFICAR_H
#endif //PROYECTOHUICHO_CODIFICAR_H

#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_NUM_CEL 10
#define MAX_NUM_CASA 8
#define MAX_CORREO 30
#define RUTA_ARCHIVO ".contactosCodificados.txt"
#if _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

struct contacto {
	unsigned char nombre[MAX_NOMBRE];
	char celular[MAX_NUM_CEL + 1];
	char num_casa[MAX_NUM_CASA + 1];
	char correo[MAX_CORREO + 1];
};

typedef struct contacto contacto;

/* Declaración: presentacion : vacío -> vacío
 * Próposito: Esta función imprime nuestra portada, no toma ni devuelve nada
 * Ejemplo : presentacion();
 *	debería imprimir
 *	##################################
 *	#          Proyecto 3            #
 *	##################################
 */
void presentacion () {
	system (CLEAR);
	printf ("\n%c",201);
	for (int i = 0; i < 77; i++) {
		printf ("%c", 205);
	}
	printf ("%c\n",187);
	printf ("%c                   Universidad Nacional A%ctonoma de M%cxico                    %c\n", 186, 163, 130, 186);
	printf ("%c                           Facultad de Ingenier%ca                             %c\n", 186, 161, 186);
	printf ("%c                  Programaci%cn avanzada y m%ctodos num%cricos                   %c\n", 186, 162, 130, 130, 186);
	printf ("%c                                 Proyecto 1                                   %c\n", 186, 186);
	printf ("%c                         Cabrera L%cpez Oscar Emilio                           %c\n", 186, 162, 186);
	printf ("%c                           Mendoza Garc%ca Ulises                              %c\n", 186, 161, 186);
	printf ("%c                      Sierra Gonz%clez H%cctor Alejandro                        %c\n", 186, 160, 130, 186);
	printf ("%c                           Mart%cnez Ortiz Sa%cl Axel                             %c\n", 186, 161, 163, 186);
	printf ("%c                             D%caz Alferez Melisa                              %c\n", 186, 161, 186);
	printf ("%c",200);
	for (int i = 0; i < 77; i++) {
		printf ("%c", 205);
	}
	printf ("%c\n", 188);
}

/* Declaración: crearArreglo : entero -> contactos
 * Proposito: La tarea de esta función es alojar suficiente memoria para que se guarde
 * un arreglo de contactos sobre el que se realizarán distintas operaciones
 */

contacto *crearArreglo(size_t num_contactos) {
	contacto *arreglo;
	arreglo = (contacto *) calloc (num_contactos, sizeof (contacto));
	return arreglo;
}

int nombreValido (unsigned char cadena_validar[]) {
	for (int i = 0; i < strlen ((const char *) cadena_validar); i++) {
		if ((cadena_validar[i] < 65  && cadena_validar[i] != 32) ||
				(cadena_validar[i] > 90  && cadena_validar[i] < 97 ) ||
				(cadena_validar[i] > 122 && cadena_validar[i] < 128) ||
				(cadena_validar[i] > 154 && cadena_validar[i] < 160) ||
				(cadena_validar[i] > 166 && cadena_validar[i] < 181) ||
				(cadena_validar[i] > 183 && cadena_validar[i] < 198) ||
				(cadena_validar[i] > 199 && cadena_validar[i] < 209) ||
				(cadena_validar[i] > 217 && cadena_validar[i] < 224) ||
				(cadena_validar[i] > 238)
		) return 0;
	}
	return 1;
}

int numeroAscii (unsigned char cadena_validar[]) {
	for (int i = 0; i < strlen ((const char *) cadena_validar); i++) {
		if (cadena_validar[i] < 48 || cadena_validar[i] > 57)
			return 0;
	}
	return 1;
}

int correoValido (unsigned char cadena_validar[]) {
	int tiene_arroba = 0, valido = 0;
	for (int i = 0; i < strlen ((const char *) cadena_validar); i++) {
		if (cadena_validar[i] < 48  || (cadena_validar[i] > 57 && cadena_validar[i] < 65 ) ||
		    (cadena_validar[i] > 90  && cadena_validar[i] < 97) || cadena_validar[i] > 122) {
			if (cadena_validar[i] == 46 || cadena_validar[i] == 64 || cadena_validar[i] == 95 || cadena_validar[i] == 45) {
				if (cadena_validar[i] == 46) {
					valido = ((tiene_arroba == 19) ? 1 : 0);
				} else if (cadena_validar[i] == 64) {
					if (tiene_arroba || valido) {
						valido = 0;
						tiene_arroba ++;
					} else {
						tiene_arroba++;
					}
				}
			} else {
				return 0;
			}
		}
	}
	return valido;
}

int validarCadena (unsigned char cadena_validar[], int tipo) {
	switch (tipo) {
		case 1:
			return nombreValido (cadena_validar) ? 1 : 0;
		case 2:
			return numeroAscii (cadena_validar) ? 1 : 0;
		case 3:
			return correoValido (cadena_validar) ? 1 : 0;
		default:
			return 0;
	}
}

void leeContacto (contacto *ap_lista_contactos, int num_contactos) {
	int valido = 0;
	unsigned char cadena_validar[MAX_NOMBRE + 5];
	for (int i = 1; i <= num_contactos; i++) {
		do {
			printf ("Introduce el nombre del %d%c contacto: ", i, 167);
			scanf (" %50[^\n]", cadena_validar);
			getchar ();
			if (validarCadena (cadena_validar, 1)) {
				valido = 1;
			} else {
				valido = 0;
				printf ("Formato no v%clido D:\n", 160);
				printf ("int%cntalo de nuevo\n", 130);
				getchar ();
			}
			system (CLEAR);
		} while (!valido);
		strcpy (ap_lista_contactos -> nombre, cadena_validar);
		do {
			printf ("Introduce el n%cmero de celular del %d%c contacto: ", 163, i, 167);
			scanf ("%10[^\n]", cadena_validar);
			getchar ();
			if (validarCadena (cadena_validar, 2)) {
				valido = 1;
			} else {
				valido = 0;
				printf ("Formato no v%clido D:\n", 160);
				printf ("int%cntalo de nuevo\n", 130);
				getchar ();
			}
			system (CLEAR);
		} while (!valido);
		strcpy (ap_lista_contactos -> celular, (const char *) cadena_validar);
		do {
			printf ("Introduce el n%cmero de la casa del %d%c contacto: ", 163, i, 167);
			scanf ("%8[^\n]", cadena_validar);
			getchar ();
			if (validarCadena (cadena_validar, 2)) {
				valido = 1;
			} else {
				valido = 0;
				printf ("Formato no v%clido D:\n", 160);
				printf ("int%cntalo de nuevo\n", 130);
				getchar ();
			}
			system (CLEAR);
		} while (!valido);
		strcpy (ap_lista_contactos -> num_casa, (const char *) cadena_validar);
		do {
			printf ("Introduce el correo electr%cnico del %d%c contacto: ", 162, i, 167);
			scanf ("%30[^\n]", cadena_validar);
			getchar ();
			if (validarCadena (cadena_validar, 3)) {
				valido = 1;
			} else {
				valido = 0;
				printf ("Formato no v%clido D:\n", 160);
				printf ("int%cntalo de nuevo\n", 130);
				getchar ();
			}
			system (CLEAR);
		} while (!valido);
		strcpy (ap_lista_contactos -> correo, (const char *) cadena_validar);
	}
}

/* Declaración: codificar : contactos, entero -> vacío
 * Propósito: Esta función toma como argumentos un apuntador a un arreglo de
 * contactos y un entero que indica el número de los mismos, para despues recorrer
 * cada uno de los datos de los mismos sumandole 3 al codigo de sus caracteres
 */
void codificar (contacto *ap_lista_contactos, int num_contactos) {
	for (int i = 0; i < num_contactos; i++) {
		for (int j = 0; j < strlen ((const char *) (ap_lista_contactos + i)->nombre); j++) {
			ap_lista_contactos -> nombre[j] += 3;
		}
		for (int j = 0; j < strlen ((const char *) (ap_lista_contactos + i)->celular); j++) {
			ap_lista_contactos -> celular[j] += 3;
		}
		for (int j = 0; j < strlen ((const char *) (ap_lista_contactos + i)->num_casa); j++) {
			ap_lista_contactos->num_casa[j] += 3;
		}
		for (int j = 0; j < strlen ((const char *) (ap_lista_contactos + i)->correo); j++) {
			ap_lista_contactos ->correo[j] += 3;
		}
	}
}

void grabarArchivo (FILE *ap_archivo, contacto *ap_lista_contactos, int num_contactos) {
	for (int i = 0; i < num_contactos; i++) {
		fprintf (ap_archivo, "%s\t%s\t%s\t%s\n", (ap_lista_contactos + i) -> nombre,
		         (ap_lista_contactos + i) -> celular,
		         (ap_lista_contactos + i) -> num_casa,
		         (ap_lista_contactos + i) -> correo
		);
	}
}