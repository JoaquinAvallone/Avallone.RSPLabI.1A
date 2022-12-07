/*
 ============================================================================
 Name        : 1A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "users.h"
#include "menu.h"
#include "time.h"
#include "validaciones.h"



int main(void) {
	setbuf(stdout,NULL);
	char respuesta = 'n';
	int flagValores = 0;
	srand(time(NULL));
	LinkedList* listaPosteos = ll_newLinkedList();
	LinkedList* listaLikes = ll_newLinkedList();
	LinkedList* listaHaters = ll_newLinkedList();

	do{
		switch(menuPrincipal())
		{
		case 1:
			if(controller_cargarUsersDesdeTexto("posts.csv", listaPosteos))
			{
				printf("El archivo se cargo con exito.\n");
			}
			else
			{
				printf("No pudo cargarse el archivo.\n");
			}
			pausa();
			break;
		case 2:
			if(ll_isEmpty(listaPosteos))
			{
				printf("No hay posteos, ingrese al punto 1.\n");
			}
			else
			{
				controller_listarUsers(listaPosteos);
			}
			pausa();
			break;
		case 3:

			if(ll_isEmpty(listaPosteos))
			{
				printf("No hay posteos, ingrese al punto 1.\n");
			}
			else
			{
				if(asignarLikes(listaPosteos) && asignarDislikes(listaPosteos) && asignarFollowers(listaPosteos))
				{
					flagValores = 1;
					printf("Estadisticas asignados con exito.\n");
					pausa();
					controller_listarUsers(listaPosteos);
				}
			}
			pausa();
			break;
		case 4:
			if(ll_isEmpty(listaPosteos))
			{
				printf("No hay posteos, ingrese al punto 1.\n");
			}
			else
			{
				if(!flagValores)
				{
					printf("Primero se deben asignar las estadisticas de los posteos en el punto 3.\n");
				}
				else
				{
					listaLikes = ll_filter(listaPosteos,filtrarPosteosMasLikes);
					controller_listarUsers(listaLikes);
					controller_guardarUsersTexto("posteosMasLikes.csv", listaLikes);
				}
			}
			pausa();
			break;
		case 5:
			if(ll_isEmpty(listaPosteos))
			{
				printf("No hay posteos, ingrese al punto 1.\n");
			}
			else
			{
				if(!flagValores)
				{
					printf("Primero se deben asignar las estadisticas de los posteos en el punto 3.\n");
				}
				else
				{
					listaHaters = ll_filter(listaPosteos,filtrarPosteosMasLikes);
					controller_listarUsers(listaHaters);
					controller_guardarUsersTexto("haters.csv", listaHaters);
				}
			}
			pausa();
			break;
		case 6:

			if(ll_isEmpty(listaPosteos))
			{
				printf("No hay posteos, ingrese al punto 1.\n");
			}
			else
			{
				if(!flagValores)
				{
					printf("Primero se deben asignar las estadisticas de los posteos en el punto 3.\n");
				}
				else
				{
					ll_sort(listaPosteos,ordenarFollowers,1);
					controller_listarUsers(listaPosteos);
					controller_guardarUsersTexto("followers.csv", listaPosteos);
				}
			}
			break;
		case 7:
			break;
		case 8:
			pausa();
			break;
		default:
			printf("La opcion elegida no existe");
			pausa();
		}
		limpiarConsola();
		}while(respuesta=='n');

	return 0;
}

