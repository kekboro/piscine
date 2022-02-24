#include <stdlib.h>
#include <stdio.h> // printf

int		count_word(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			cnt++;
		}
	}
	return (cnt);
}

int		word_len(char *str, int i)
{
	int cnt;

	cnt = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		cnt++;
		i++;
	}
	return (cnt);
}

char 	**ft_split(char *str, char *sep)
{
	int i;
	int j;
	int k;
	char **tab;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char *) * (count_word(str) + 1))))
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i])
		{
			k = 0;
			if (!(tab[j] = malloc(sizeof(char) * (word_len(str, i) + 1))))
				return (NULL);
			while (str[i] && str[i] != sep)
			{
				tab[j][k++] = str[i++]; // segfault 
			}
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}

int		main(void)
{
	int i = 0;
	char **tab;
		
	tab = ft_split("bonjour je m'appel Arthur", " ");
	while (i < 4)
	{
		printf("string %d : %s\n", i, tab[i]);
		i++;
	}
	return (0);
}