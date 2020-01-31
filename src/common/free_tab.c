/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

void free_tab (char **tab)
{
	for (int i = 0; tab[i]; i++)
		if (tab[i])
			free(tab[i]);
	if (tab)
		free(tab);
}