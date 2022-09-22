#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}
char	*ft_strdup(char *src)
{
	int i;
	char *dup;

	i = 0;
	dup = (char *) malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!(dup))
		return(0);
	while (*src)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}