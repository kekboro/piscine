#include <stdlib.h>
#include <unistd.h>

int *ft_range(int min, int max)
{
	int i;
	int *tab;

	i = 0;
	if (min >= max)
		return NULL;
	tab = (int*)malloc(sizeof(*tab) * (max - min));
	while(min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}

#include <stdio.h>


int		main(void)
{
	int		i;
	int		*tab;

	tab = ft_range(52, 72);
	i = 0;
	while (i < 20)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

