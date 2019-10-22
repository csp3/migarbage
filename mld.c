/*
Nombre de archivo:  mld.c
Descripcion:  This file implements the functions and routines for mld library
Version:  1.0
Created:  Thursday 28 February 2019 06:17:28  IST
Revision:  1.0
Compiler:  gcc

Author:  Er. Abhishek Sagar, Networking Developer (AS), sachinites@gmail.com

Este programa es software libre: puede redistribuirlo y/o modificarlo. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "mld.h"
#include <assert.h>
#include <memory.h>

char *DATA_TYPE[]={"UINT8", "UINT32", "INT32", "CHAR", "OBJ_PTR", "VOID_PTR", "FLOAT", "DOUBLE", "OBJ_STRUCT"};

/*funciones de volcado*/

//La función debe devolver el puntero al registro de estructura 
//(correspondiente al nombre de estructura pasado como 
//segundo arg). Si no se encuentra tal registro, devuelva NULL
static struct_db_rec_t* struct_db_look_up(struct_db_t *struct_db, char *struct_name)
{
	struct_db_rec_t *head = NULL;
	while(strncmp(head->struct_name, struct_name, MAX_STRUCTURE_NAME_SIZE)!=0)
	{
		head->next = struct_db->head;
	}
	
	return head;
}