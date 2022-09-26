/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:42:08 by nevan-ge          #+#    #+#             */
/*   Updated: 2022/09/26 17:04:12 by nevan-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src);
int		get_nb(char c, char *base);
int		ft_atoi_base(char *str, char *base);
int 	check_base(char * base);
char	*if_neg(int nb, char *base_to);


char	*ft_nbr_base(int nbr, char *base)
{
	int		size;
	int		nbr_final[100];
	int		i;
	char	*result;
	int		j;

	i = 0;
	size = 0;
	j = 0;
	while (base[size])
	size++;
	while (nbr)
	{
		nbr_final[i] = nbr % size;
		nbr = nbr / size;
		i++;
	}
	result = malloc (sizeof (char *) * i + 1);
	while (i-- > 0)
	{
		result[j] = base[nbr_final[i]];
		j++;
	}
	return (result);
}

int	nb_len(int nb, char *base)
{
	int	nb_len;
	int	base_len;

	nb_len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	while (nb >= base_len)
	{
		nb_len++;
		nb /= base_len;
	}
	return (nb_len);
}
#include <string.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		nb;

	if ((!(check_base(base_from)) || (!(check_base(base_to)))))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	result = malloc (sizeof(char *) * (nb_len(nb, base_to)));
	if (!(result))
		return (0);
	if (nb < 0)
	{
		result = if_neg(nb, base_to);
		return (result);
	}
	result = ft_nbr_base(nb, base_to);
	return (result);
}

#include <stdio.h>

int main(int ac, char **av)
{
	printf("%s\n", ft_convert_base("-7b", "0123456789abcdef", "01"));
}

//neg_result = malloc (sizeof(char *) * (nb_len(nb, base_to) + 1));