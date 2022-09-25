
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base [i] < 32 || base[i] == 127)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int get_digit(char c, int digits_in_base)
{
	int max_digit;
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';

	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		++str;
	}
	return (result);
}

int	nb_len(int nb, char *base)
{
	int nb_len;
	int base_len;

	nb_len = 0;
	base_len = 0;
	while(base[base_len])
		base_len++;
	while (nb >= base_len)
	{
		nb_len++;
		nb /= base_len;
	}
	return(nb_len + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int	nb;
	int last_index;

	if(!nbr || !(check_base(base_from) || !(check_base(base_to))))
		return(0);
	nb = ft_atoi_base(base_from, ft_strlen(base_from));
	result = malloc(sizeof(char) * nb_len(nb, base_to));
	if(!(result))
		return(0);
	

}


#include <stdio.h>

int main(int ac, const char **av)
{
	printf("%s\n", ft_convert_base(av[1], av[2], av[3]));
	return 0;
}