/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include "common.h"

void add_new_text (char *stock, char *text, int x)
{
	if (stock) {
		for (size_t i = 0; i < strlen(text); x++) {
			stock[x] = text[i];
			i++;
		}
		stock[x] = '\0';
	}
	else
		stock = xstrdup(text);
}

char *alloc_and_fill (char *line, char *text, int size)
{
	char *stock = NULL;
	int len = 0;
	int x = 0;

	len = line ? strlen(line) : 0;
	stock = xmalloc(sizeof(char *) * (len + size + 1));
	if (!stock)
		exit(-1);
	if (line) {
		for (; x != len; x++)
			stock[x] = line[x];
		stock[x] = '\0';
	}
	add_new_text(stock, text, x);
	free(line);
	free(text);
	return (stock);
}

char *read_size (int fd, int *end, int *len)
{
	char *text = xmalloc(sizeof(char) * 10);
	static int rd = 0;
	char buff[1];
	int x = 0;

	*len = 0;
	for (; x < 9; x++) {
		rd = read(fd, buff, 1);
		(*len)++;
		if (rd <= 0 || buff[0] == '\n' || buff[0] == '\r' ||
		    buff[0] == 0
		    || buff[0] == '\0') {
			*end = rd == 0 ? 2 : 1;
			*end = rd == -1 ? 3 : *end;
			break;
		}
		text[x] = buff[0];
	}
	text[x] = '\0';
	return (text);
}

char *read_message (int fd)
{
	char *line = NULL;
	char *red = NULL;
	int end = 0;
	int len = 0;

	while (end == 0) {
		red = read_size(fd, &end, &len);
		if (end == 2)
			return (NULL);
		if (red[0] != '\0')
			line = alloc_and_fill(line, red, len);
	}
	if (end == 3) {
		exit(-1);
	}
	return (line);
}
