/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** Created by MP,
*/

#include     <common.h>

int nbr_str (char *line, char c)
{
	int nbr = 0;
	int len = strlen(line);

	for (int i = 0; line[i] != '\0' && i != len; i++) {
		if (line[i] == c || line[i] == ' ' || line[i] == '\t') {
			while (i < len && (line[i] == c ||
					   line[i] == ' ' || line[i] == '\t'))
				i++;
		}
		else {
			nbr++;
			while (i < len && (line[i] != c &&
					   line[i] != ' ' && line[i] != '\t'))
				i++;
		}
		if (i == len)
			break;
	}
	return (nbr);
}

char *catch_str (char *line, char c, int *i)
{
	char *str;
	int x = *i;
	int l = *i;
	int p = 0;

	while (line[l] && (line[l] != c && line[l] != ' ' && line[l] != '\t'))
		l++;
	if (l == 0)
		return (NULL);
	str = malloc(sizeof(char) * (l + 1));
	while (line[x] && (line[x] != c && line[x] != ' ' && line[x] != '\t')) {
		str[p] = line[x];
		p++;
		x++;
	}
	str[p] = '\0';
	*i = x;
	return (str);
}

char *check_line (char *line, char c, int *i)
{
	int len = strlen(line);

	for (; line[*i] != '\0' && *i < len; (*i)++) {
		if (line[*i] == c || line[*i] == ' ' || line[*i] == '\t') {
			while (*i < len && (line[*i] == c || line[*i] == ' ' ||
					    line[*i] == '\t'))
				(*i)++;
			(*i)--;
		}
		else
			return (catch_str(line, c, i));
	}
	return (NULL);
}

char **the_strtowordtab (char *line, char c)
{
	static int i = 0;
	char **tab = NULL;
	int r = 0;
	int limit = 0;

	if (line == NULL)
		return (NULL);
	limit = nbr_str(line, c);
	tab = malloc(sizeof(char *) * (limit + 1));
	while (r != limit) {
		tab[r] = check_line(line, c, &i);
		r++;
	}
	tab[r] = NULL;
	i = 0;
	return (tab);
}
