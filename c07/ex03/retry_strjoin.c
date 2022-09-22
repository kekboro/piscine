#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int ft_total_len(int size, char **str, char *sep)
{
	int i;
	int len;

	i = 0;
	while(str[i])
	{
		len = len + ft_strlen(str[i]);
		i++;
	}
	len = (ft_strlen(sep) * (size - 1) + 1);
	return(len);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	int i;
	int j;
	char *string;

	string = (char *) malloc (sizeof(ft_total_len(size, str, sep)));
	if (!(string))
		return(0);
	if (size == 0)
		return(string);
	while(i < size)
	{
		ft_strcat(string, str[i]);
		if (i < size - 1)
			ft_strcat(string, sep);
		i++;
	}
	return(string);
}

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int main()
{
	char *str1 = "Hallo";
	char *str2 = "dit is een";
	char *str3 = "test";

	char *str[3] = {str1, str2, str3};
	char *sep = " ";
	ft_putstr(ft_strjoin(3, str, sep));
}