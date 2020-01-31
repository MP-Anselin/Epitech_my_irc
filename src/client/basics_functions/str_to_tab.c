/*
** EPITECH PROJECT, 2018
** str_to_tab
** File description:
** str_to_tab
*/

#include "server.h"

void print_tab(char **tab)
{
	int i = 0;

	while (tab[i]){
		printf("%s\n", tab[i]);
		i++;
	}
}

int tab_len(char **tab)
{
	int i = 0;

	while (tab[i]){
		i++;
	}
	return (i);
}

void free_tab(char **tab)
{
	int i = 0;

	while (tab[i]){
		free(tab[i]);
		i++;
	}
	free(tab);
}

char **str_to_tab_bis(char *str, char *op, int max_size, int nbr_words)
{
	char **tab;
	int size = 0;
	int i = 0;

	tab = xmalloc(sizeof(char*) * nbr_words);
	nbr_words = 0;	
	while (str[i] != '\0' && rindex(op, str[i]))
		i++;
	while (str[i] != '\0'){
		size = 0;
		tab[nbr_words] = malloc(sizeof(char) * max_size);
		while (str[i] != '\0' && !rindex(op, str[i]))
			tab[nbr_words][size++] = str[i++];
		tab[nbr_words][size] = '\0';
		while (str[i] != '\0' && rindex(op, str[i]))
			i++;
		nbr_words++;
	}
	tab[nbr_words] = NULL;
	return (tab);
}

char **str_to_tab(char *str, char *op)
{
	int i = 0;
	int max_size = 0;
	int size = 0;
	int nbr_words = 0;

	while (str[i] != '\0' && rindex(op, str[i]))
		i++;
	while (str[i] != '\0'){
		size = 0;
		while (str[i] != '\0' && !rindex(op, str[i])){
			i++;
			size++;
		}
		if (size > max_size)
			max_size = size;
		while (str[i] != '\0' && rindex(op, str[i]))
			i++;
		nbr_words++;
	}
	max_size++;
	nbr_words++;
	return (str_to_tab_bis(str, op, max_size, nbr_words));
}
