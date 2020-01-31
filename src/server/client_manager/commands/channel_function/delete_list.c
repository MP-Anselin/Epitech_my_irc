/*
** EPITECH PROJECT, 2018
** delete_list
** File description:
** delete_list
*/

#include "server.h"


void destroy_list (t_channel **list_ptr)
{
	t_channel *list = *list_ptr;
	t_channel *save;

	while (list) {
		save = list;
		list = list->next;
		if (save->name)
			free(save->name);
		if (save->topic)
			free(save->topic);
		if (save->pass)
			free(save->pass);
		//free(save->element);
		free(save);
	}
	*list_ptr = NULL;
}
