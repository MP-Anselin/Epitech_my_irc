/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

char *xstrcat (char *dest, char *src)
{
	size_t x = 0;
	char *save;

	if (dest == NULL)
		return (xstrdup(src));
	save = xstrdup(dest);
	dest = xmalloc(strlen(dest) + strlen(src) + 2);
	for (size_t i = 0; save[i] != '\0'; i++, x++)
		dest[x] = save[i];
	for (size_t i = 0; src[i] != '\0'; i++, x++)
		dest[x] = src[i];
	dest[x] = '\0';
	free(save);
	return (dest);
}
