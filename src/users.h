/*
 * users.h
 *
 *  Created on: 7 dic. 2022
 *      Author: mac2020
 */

#ifndef USERS_H_
#define USERS_H_

typedef struct
{
	int id;
	char user[100];
	int likes;
	int dislikes;
	int followers;
}eUser;

#endif /* USERS_H_ */

eUser* user_new();

eUser* user_newParametros(char* idStr,char* user,char* likesStr, char* dislikesStr, char* followersStr);

int user_setId(eUser* this,int id);

int user_getId(eUser* this,int* pId);

int user_setUser(eUser* this,char* user);

int user_getUser(eUser* this,char* user);

int user_setLikes(eUser* this, int likes);

int user_getLikes(eUser* this, int* likes);

int user_setDislikes(eUser* this, int dislikes);

int user_getDislikes(eUser* this, int* dislikes);

int user_setFollowers(eUser* this, int followers);

int user_getFollowers(eUser* this, int* followers);
