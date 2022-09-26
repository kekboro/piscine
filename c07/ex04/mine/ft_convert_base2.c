/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:52:17 by nevan-ge          #+#    #+#             */
/*   Updated: 2022/09/26 17:07:45 by nevan-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nb_len(int nb, char *base);
char	*ft_nbr_base(int nbr, char *base);
/*
char	*if_neg(int nb, char *base_to)
{
	int		i;
	char	*result;
	char	*neg_result;
	
	nb *= -1;
	result[0] = '-';
	i = 0;
	result = malloc (sizeof(char *) * (nb_len(nb, base_to)));
	result = ft_nbr_base(nb, base_to);
	while (i <= nb_len(nb, base_to))
	{
		neg_result[i + 1] = result[i];
		i++;
	}
	return (neg_result);
}
*/
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

int	get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	s;
	int	i;
	int	res;
	int	negative;
	int	base_length;

	base_length = 0;
	while (base[base_length])
		++base_length;
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' || str[s] == '\r'
			|| str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s)
			|| (str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	}
	return (res * negative);
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

/*
#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi_base("-348792", "0123456789"));
}
*/