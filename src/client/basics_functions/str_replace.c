/*
** EPITECH PROJECT, 2018
** str_replace
** File description:
** str_replace
*/

#include "client.h"

char *str_replace (char *in, char *pattern, char *by)
{
	char *oc = in;
	size_t outsize = strlen(in);

	while ((oc = strstr(oc, pattern))) {
		if (*oc == '\0')
			return NULL;
		else {
			outsize -= strlen(pattern);
			outsize += strlen(by);
		}
		oc = oc + 1;
	}
	outsize++;
	char *res = malloc(outsize);
	size_t resoffset = 0;
	char *needle;

	while ((needle = strstr(in, pattern))) {
		memcpy(res + resoffset, in, needle - in);
		resoffset += needle - in;
		in = needle + strlen(pattern);
		outsize = outsize - strlen(pattern) + strlen(by);
		res = realloc(res, outsize);
		memcpy(res + resoffset, by, strlen(by));
		resoffset += strlen(by);
	}
	strcpy(res + resoffset, in);
	return res;
}

/*

char *str_replace(char *str, char *replace, char *subject)
{
	char *oc = str;
	(void)subject;
	int size = strlen(str);
	char *new;
	int i = 0;

	while ((oc = strstr(oc, replace))){
		if (*oc == '\0')
			return NULL;
		else{
			size -= strlen(replace);
			size += strlen(subject);
		}
		oc = oc + 1;
	}
	if ((new = malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	oc = str;
	new[0] = '\0';
	while ((oc = strstr(oc, replace))){
		if (str == strstr(str, replace)){
			str = str + strlen(replace);
			new = strcat(new, subject);
			i = i + strlen(subject);
		}
		while (str != oc && str != oc + strlen(subject)){
			new[i++] = *str;
			new[i] = '\0';
			str++;
		}
		if (*oc == '\0')
			return NULL;
		oc = oc + 1;
	}
	if (str == strstr(str, replace)){
		new = strcat(new, subject);
		i = i + strlen(subject);
		str = str + strlen(replace);
	}
	while (*str && str != oc + strlen(subject)){
		new[i++] = *str;
		new[i] = '\0';
		str++;
	}
	//printf("%s %d == %d\n", new, (int)strlen(new), size);
	//printf("%s", subject);
	//printf("%d\n", size);
	//printf("hello\n");
	return (new);
}
*/
