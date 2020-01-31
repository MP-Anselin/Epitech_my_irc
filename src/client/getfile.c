/*
** EPITECH PROJECT, 2018
** getfile
** File description:
** getfile
*/

#include "client.h"

char *get_file (const char *filename)
{
	FILE *f = fopen(filename, "rt");
	//assert(f);
	fseek(f, 0, SEEK_END);
	long length = ftell(f);
	fseek(f, 0, SEEK_SET);
	char *buffer = (char *) malloc(length + 1);
	buffer[length] = '\0';
	fread(buffer, 1, length, f);
	fclose(f);
	return buffer;
}
