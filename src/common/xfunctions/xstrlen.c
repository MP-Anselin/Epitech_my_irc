/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

int xstrlen (char *str)
{
	int len = 0;

	if (str)
		for (; str[len]; len++);
	return (len);
}