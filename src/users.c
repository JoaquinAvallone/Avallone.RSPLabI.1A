#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "users.h"



eUser* user_new()
{
	eUser* u = (eUser*) malloc(sizeof(eUser));
	    if(u != NULL)
	    {
	        u->id = 0;
	        *(u->user) = '\0';;
	        u->likes = 0;
	        u->dislikes = 0;
	        u->followers = 0;
	    }

	    return u;
}


eUser* user_newParametros(char* idStr,char* user,char* likesStr, char* dislikesStr, char* followersStr)
{
	eUser* u = user_new();
	    if(u != NULL)
	    {
	        if(!(user_setId(u, atoi(idStr)) &&
	        user_setUser(u, user) &&
			user_setLikes(u,atoi(likesStr)) &&
			user_setDislikes(u,atoi(dislikesStr)) &&
			user_setFollowers(u, atoi(followersStr))))
	        {
	            free(u);
	            u = NULL;
	        }
	    }

	return u;
}

int user_setId(eUser* this,int id)
{
	int retorno = 0;

	if(this!=NULL && id>=1)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}
int user_getId(eUser* this,int* pId)
{
	int retorno = 0;

	if(this!=NULL && pId!=NULL)
	{
		*pId = this->id;
		retorno = 1;
	}
	return retorno;
}

int user_setUser(eUser* this,char* user)
{
	int retorno=0;
	int largoCad;
	char auxCad[200];

	largoCad = strlen(user);

	if(this !=NULL && user!=NULL && largoCad<100)
	{
		strcpy(auxCad, user);
		//strlwr(auxCad);
		auxCad[0]=toupper(auxCad[0]);
		strcpy(this->user, auxCad);
		retorno = 1;
	}
	else
	{
		printf("El nombre de usuario ingresado es demsiado largo.\n");
	}

	return retorno;
}
int user_getUser(eUser* this,char* user)
{
	int retorno=0;

	if(this!=NULL && user!=NULL)
	{
		strcpy(user, this->user);
		retorno=1;
	}

	return retorno;
}

int user_setLikes(eUser* this, int likes)
{
	int retorno = 0;

	if(this!=NULL && likes>=0)
	{
		this->likes = likes;
		retorno = 1;
	}

	return retorno;
}
int user_getLikes(eUser* this, int* likes)
{
	int retorno=0;

	if(this!=NULL && likes!=NULL)
	{
		*likes = this->likes;
		retorno=1;
	}

	return retorno;
}

int user_setDislikes(eUser* this, int dislikes)
{
	int retorno = 0;

	if(this!=NULL && dislikes>=0)
	{
		this->dislikes = dislikes;
		retorno = 1;
	}

	return retorno;
}
int user_getDislikes(eUser* this, int* dislikes)
{
	int retorno=0;

	if(this!=NULL && dislikes!=NULL)
	{
		*dislikes = this->dislikes;
		retorno=1;
	}

	return retorno;
}

int user_setFollowers(eUser* this, int followers)
{
	int retorno = 0;

	if(this!=NULL && followers>=0)
	{
		this->followers = followers;
		retorno = 1;
	}

	return retorno;
}
int user_getFollowers(eUser* this, int* followers)
{
	int retorno=0;

	if(this!=NULL && followers!=NULL)
	{
		*followers = this->followers;
		retorno=1;
	}

	return retorno;
}
