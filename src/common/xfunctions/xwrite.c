/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

void xwrite (char *text, int nbr)
{
	write(nbr, text, strlen(text));
}