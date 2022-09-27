/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:42:08 by nevan-ge          #+#    #+#             */
/*   Updated: 2022/09/27 15:13:40 by nevan-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_nb(char c, char *base);
int		ft_atoi_base(char *str, char *base);
int		check_base(char *base);

void	ft_nbr_base(unsigned int nbr, char *base, char *result, int len)
{
	int		size;
	int		i;

	if (nbr == 0)
		result[0] = base[0];
	i = len - 1;
		size = 0;
	while (base[size])
		size++;
	while (nbr > 0)
	{
		result[i] = base[nbr % size];
		nbr = nbr / size;
		i--;
	}
}

int	nb_len(int nb, char *base)
{
	int				nb_len;
	unsigned int	base_len;
	unsigned int	nbr;

	nb_len = 0;
	base_len = 0;
	if (nb == 0)
		return (1);
	nbr = (unsigned int)nb;
	if (nb < 0)
	{
		nb_len++;
		nbr = (unsigned int)-nb;
	}
	while (base[base_len])
		base_len++;
	while (nbr >= 1)
	{
		nb_len++;
		nbr /= base_len;
	}
	return (nb_len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*result;
	int				nb;
	unsigned int	n;
	int				i;

	if ((!(check_base(base_from)) || (!(check_base(base_to)))))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	result = malloc (sizeof(char *) * (nb_len(nb, base_to)) + 1);
	if (!(result))
		return (0);
	n = (unsigned int)nb;
	i = 0;
	while (i <= nb_len(nb, base_to))
	{
		result[i] = '\0';
		i++;
	}
	if (nb < 0)
	{
		result[0] = '-';
		n = (unsigned int)-nb;
	}
	ft_nbr_base(n, base_to, result, nb_len(nb, base_to));
	return (result);
}

#include <stdio.h>

int main()
{
	printf("%s\n", ft_convert_base("-7b", "0123456789abcdef", "01"));
}
