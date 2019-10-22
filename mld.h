/*
Nombre de archivo: mld.h 
Descripción:  Este fichero define las estructuras de datos utilizadas para la herramienta MLD
Versión: 1.0 
Creado:  Jueves 28 de febrero de 2019 05:14:18 IST
Revisión: 1.0
Compilador: gcc
 
Autor:  Er. Abhishek Sagar, Desarrollador de redes (AS), sachinites@gmail.com

Este programa es software libre: puede redistribuirlo y/o modificarlo. 
*/

#ifndef __MLD__
#include <assert.h>
#include <string.h>

#define MAX_STRUCTURE_NAME_SIZE 128
#define MAX_FIELD_NAME_SIZE 128

typedef enum
{
	UINT8,
	UINT32,
	INT32,
	CHAR,
	OBJ_PTR,
	VOID_PTR, /para identificar void * pointers*/
	FLOAT,
	DOUBLE,
	OBJ_STRUCT
} data_type_t;

typedef enum
{
	MLD_FALSE,
	MLD_TRU
} mld_boolean_t;

#define OFFSETOF(struct_name, fld_name) (unsigned int)&(((struct_name *)0)->fld_name)
#define FIELD_SIZE(struct_name, fld_name) sizeof(((struct_name *)0)->fld_name)

typedef struct _struct_db_rec_ struct_db_rec_t;

/*estructura que almacena información de los campos*/
typedef struct _field_info_
{
	char fname[MAX_FIELD_NAME_SIZE]; /*nombre del campo*/
	data_type_t dtype; /*tipo del campo*/
	unsigned int size; /*tamaño del campo*/
	unsigned int offset; /*offset del campo*/
	// El campo de abajo sólo tiene sentido si dtype = OBJ_PTR o OBJ_STRUCT
	char nested_str_name[MAX_STRUCTURE_NAME_SIZE];
} field_info_t;

/*estructura para almacenar la información de una estructura C que podría tener N campos*/
struct _struct_db_rec_
{
	struct_db_rec_t *next; /*puntero a la siguiente estructura de la lista enlazada*/
	char struct_name[MAX_STRUCTURE_NAME_SIZE]; //key
	unsigned int ds_size; /*tamaño de la estructura*/
	unsigned int n_fields; /*numero de campos*/
	field_info_t *fields; /*puntero al array de campos de esa estructura*/
};

/*la cabecera de la lista enlazada que representa la base de datos de la estructura*/
typedef struct _struct_db_
{
	struct_db_rec_t *head;
	unsigned int count;
} struct_db_t;

/*definición de la base de datos de estructurad finales*/ 

/*funciones de impresión*/
void print_structure_rec(struct_db_rec_t *struct_rec);
void print_structure_db(struct_db_t *struct_db);

#endif /* __MLD__ */