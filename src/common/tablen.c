/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

size_t tablen(char **tab)
{
	int len = 0;

	if (tab && tab[0])
		for (; tab[len]; len++);
	return (len);
}