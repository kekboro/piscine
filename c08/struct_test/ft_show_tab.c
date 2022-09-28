/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:41:29 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/09/28 15:06:02 by nevan-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}


void	ft_show_tab(struct s_stock_str *tab)
{
	int i;

	i = 0;
	while (tab[i].str != 0)
	{
		ft_putstr(tab[i].str);
		ft_putchar('\n');
		ft_putnbr(tab[i].size);
		ft_putchar('\n');
		ft_putstr(tab[i].copy);
		ft_putchar('\n');
		i++;
	}
}

int main(int ac, char **av)
{
	ft_show_tab(ft_strs_to_tab(ac, av));
}