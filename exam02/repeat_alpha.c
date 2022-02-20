#include <unistd.h>
void ft_putchar(char c)
{
	write (1, &c , 1);
}

int main (int argc, char **argv)
{	
	int i;
	int count;

	i = 0;
	count = 0;
	if (argc != 2)
		return(0);
	while (argv[1][i])
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			count = argv[1][i] - 64;
		else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			count = argv[1][i] - 96;
		while (count)
		{
			ft_putchar(argv[1][i]);
			count--;
		}
		count = 1;
		i++;
	}
	ft_putchar('\n');
}