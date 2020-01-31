/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include <stdlib.h>

void *xmalloc (int size)
{
	void *stock = malloc(size + 1);

	if (stock == NULL)
		exit(-1);
	return (stock);
}