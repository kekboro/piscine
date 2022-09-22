#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return(0);
	}
	tab = (int *) malloc (sizeof(int) * (max - min));
	if(!(tab))
		return(-1);
	while(min < max)
		tab[i++] = min++;
	*range = tab;
	return(i);
}

#include <stdio.h>
int		main(void)
{
	int		*range;
	int		i;

	i = 0;
	printf("return : %d\n", ft_ultimate_range(&range, -5, 5));
	while (i < 10)
	{
	printf("%d\n", range[i]);
		i++;
	}
	return (0);
}
