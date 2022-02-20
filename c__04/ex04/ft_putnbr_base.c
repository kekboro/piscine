/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:37:14 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/02/17 15:57:53 by nvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	nbr_final[100];
	int	i;

	i = 0;
	size = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[size])
		size++;
		while (nbr)
		{
			nbr_final[i] = nbr % size;
			nbr = nbr / size;
			i++;
		}
		while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	}
}

int main ()
{
	char base[] = "0123456789ABCDEF";
	int nb = 231;
	ft_putnbr_base(nb, base);
}