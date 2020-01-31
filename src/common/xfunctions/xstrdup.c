/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

char *xstrdup (char *str)
{
	char *stock;

	if (str == NULL)
		return (NULL);
	stock = strdup(str);
	if (!stock)
		exit_error("Strdup failed\n", -1);
	return (stock);
}