#ifndef TYPES_H
# define TYPES_H

# include "main.h"

/*
**	This file contains only the types and defs used on more than one file across
**	the program.
*/

/*
**	ERRORS
*/

typedef enum e_errors {
	ILLEGAL_INPUT				= -1,
	FAILED_MALLOC				= -2,
}	t_errors;

typedef enum e_args {
	PHILOSOPHERS,
	T_DIE,
	T_EAT,
	T_SLEEP,
	MUST_EAT
} 	t_args;

#endif
