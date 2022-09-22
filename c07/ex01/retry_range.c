#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int j;
	int *range;

	i = 0;
	j = min;
	if(min >= max)
		return NULL;
	range = (int *) malloc(sizeof(int) * (max - min));
	if (!(range))
		return(0);
	while(min < max)
		range[i++] = min++;
	range[i] = '\0';
	return(range);
}