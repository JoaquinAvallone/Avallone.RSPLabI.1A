#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "users.h"
#include "validaciones.h"


/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_UsersFromText(FILE* pFile , LinkedList* pLista)
{
	int retorno = 0;
	char buffer[5][100];
	eUser* auxUser = NULL;

	if(pFile!=NULL && pLista!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);
			auxUser = user_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

			if(auxUser != NULL)
			{
				ll_add(pLista, auxUser);
			}
		}
		retorno = 1;
	}
    return retorno;
}


/** \brief Carga los datos de las peliculas desde el archivo movies.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int
 *
 */
int controller_cargarUsersDesdeTexto(char* path , LinkedList* pLista)
{
	int retorno=0;
	FILE* file = NULL;

	if(pLista!=NULL && path!=NULL)
	{
		file=fopen(path,"r");

		if(file!=NULL)
		{
			parser_UsersFromText(file, pLista);
			retorno=1;
		}
		fclose(file);
	}
    return retorno;
}

int controller_listarUser(eUser* unUsuario)
{
	int retorno = 0;
	int id;
	char user[100];
	int likes;
	int dislikes;
	int followers;

	if(unUsuario!=NULL)
	{
		if(user_getId(unUsuario, &id) && user_getUser(unUsuario, user) && user_getLikes(unUsuario, &likes) &&
		   user_getDislikes(unUsuario, &dislikes) && user_getFollowers(unUsuario, &followers))
		{
			printf("| %-3d |  %-26s  |   %-4d  |    %-4d   |    %-5d   |\n", id, user, likes, dislikes, followers);
		}
	}


	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarUsers(LinkedList* pLista)
{
	int retorno = 0;
	int largo = ll_len(pLista);

	if(pLista != NULL && largo > 0)
	{
		limpiarConsola();
		printf( "=========================================================================\n"
				"|                          ***LISTA USUARIOS***                         |\n"
				"=========================================================================\n"
				"| ID  |            USER              |  LIKES  | DISLIKES |  FOLLOWERS  |\n"
			    "-------------------------------------------------------------------------\n");

		for(int i=0; i < largo; i++)
		{
			controller_listarUser((eUser*) ll_get(pLista, i));
		}
		printf( "=========================================================================\n");
		retorno=1;
	}
    return retorno;
}


int asignarLikes(LinkedList* listaPosteos)
{
	int retorno = 0;
	if(listaPosteos!=NULL)
	{
		ll_map(listaPosteos, asignarLikesAleatorio);
		retorno = 1;
	}
	return retorno;
}

void* asignarLikesAleatorio(void* elemento)
{
	int likes;
	eUser* auxUser = NULL;

	if(elemento!=NULL)
	{
		auxUser = (eUser*)elemento;
		likes= ((rand() % (5000 - 600 + 1)) + 100);
		user_setLikes(auxUser, likes);
	}

	return auxUser;
}

int asignarDislikes(LinkedList* listaPosteos)
{
	int retorno = 0;
	if(listaPosteos!=NULL)
	{
		ll_map(listaPosteos, asignarDislikesAleatorio);
		retorno = 1;
	}
	return retorno;
}

void* asignarDislikesAleatorio(void* elemento)
{
	int dislikes;
	eUser* auxUser = NULL;

	if(elemento!=NULL)
	{
		auxUser = (eUser*)elemento;
		dislikes= ((rand() % (3500 - 300 + 1)) + 100);
		user_setDislikes(auxUser, dislikes);
	}

	return auxUser;
}

int asignarFollowers(LinkedList* listaPosteos)
{
	int retorno = 0;
	if(listaPosteos!=NULL)
	{
		ll_map(listaPosteos, asignarFollowersAleatorio);
		retorno = 1;
	}
	return retorno;
}

void* asignarFollowersAleatorio(void* elemento)
{
	int followers;
	eUser* auxUser = NULL;

	if(elemento!=NULL)
	{
		auxUser = (eUser*)elemento;
		followers= ((rand() % (20000 - 10000 + 1)) + 100);
		user_setFollowers(auxUser, followers);
	}

	return auxUser;
}

int filtrarPosteosMasLikes(void* unUser)
{

	int retorno=0;
	eUser* auxUser;
	int likes;

	if(unUser!=NULL)
	{
		auxUser=(eUser*)unUser;
		user_getLikes(auxUser,&likes);

		if(likes > 4000)
		{
			retorno=1;
		}
	}
return retorno;
}


int filtrarPorHaters(void* unUser)
{
    int retorno = 0;
    eUser* auxUser;
    int likes;
    int dislikes;

    if(unUser!=NULL){
    auxUser=(eUser*)unUser;
    user_getLikes(auxUser,&likes);
    user_getDislikes(auxUser, &dislikes);


    if( dislikes>likes){

        retorno=1;
    }
}
return retorno;
}


int controller_guardarUsersTexto(char* path , LinkedList* listaPosteos)
{
	int retorno = 0;
	eUser* auxUser = NULL;
	int id;
	char user[100];
	int likes;
	int dislikes;
	int followers;
	int tam;
	FILE* f=fopen(path,"w");

	tam=ll_len(listaPosteos);

	if(path!=NULL && listaPosteos!=NULL && f!=NULL)
	{
		fprintf(f,"id,user,likes,dislikes,followers\n");

		for(int i=0;i<tam;i++)
		{
			auxUser=(eUser*)ll_get(listaPosteos, i);
			user_getId(auxUser, &id);
			user_getUser(auxUser, user);
			user_getLikes(auxUser, &likes);
			user_getDislikes(auxUser, &dislikes);
			user_getFollowers(auxUser, &followers);
			fprintf(f,"%d,%s,%d,%d,%d\n",id,user,likes,dislikes,followers);
			retorno = 1;
		}
	}
	fclose(f);

    return retorno;
}

int ordenarFollowers(void* userI, void* userJ)
{
    int returnAux=0;
    eUser* userIndiceI;
    eUser* userIndicej;
    int auxFollowersI;
    int auxFollowersJ;

    if(userI != NULL && userJ != NULL)
    {
    	userIndiceI = (eUser*)userI;
    	userIndicej = (eUser*)userJ;

       user_getFollowers(userIndiceI,&auxFollowersI);
        user_getFollowers(userIndicej,&auxFollowersJ);

        if(auxFollowersI < auxFollowersJ)
        {
            returnAux=1;
        }

    }
    return returnAux;
}
