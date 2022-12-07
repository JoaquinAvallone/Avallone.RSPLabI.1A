/*
 * controller.h
 *
 *  Created on: 7 dic. 2022
 *      Author: mac2020
 */
#include "users.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

int parser_UsersFromText(FILE* pFile , LinkedList* pLista);

int controller_cargarUsersDesdeTexto(char* path , LinkedList* pLista);

int controller_listarUser(eUser* unUsuario);

int controller_listarUsers(LinkedList* pLista);

int asignarLikes(LinkedList* listaPosteos);

void* asignarLikesAleatorio(void* elemento);

int asignarDislikes(LinkedList* listaPosteos);

void* asignarDislikesAleatorio(void* elemento);

int asignarFollowers(LinkedList* listaPosteos);

void* asignarFollowersAleatorio(void* elemento);

int filtrarPosteosMasLikes(void* unUser);

int filtrarPorHaters(void* unUser);

int controller_guardarUsersTexto(char* path , LinkedList* listaPosteos);

int ordenarFollowers(void* userI, void* userJ);
