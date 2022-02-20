#include <unistd.h>
#include <stdio.h>

int is_power_off_2(unsigned int n)
{
	unsigned int i;

	i = 2;
	if (n == 2)
		return(1);
	while (i <= n)
	{
		if (i == n)
			return(1); 
		i = i * i;
	} 
	return (0);
}

int main()
{
	printf("%d\n", is_power_off_2(16));
}