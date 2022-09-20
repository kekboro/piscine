/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:51:50 by nevan-ge          #+#    #+#             */
/*   Updated: 2022/09/20 16:33:33 by nevan-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_printable(char c)
{
	if
		((c < 32) || (c == 127))
			return (0);
	return (1);
}

void	put_non_printable(int np)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex[np / 16], 1);
	write(1, &hex[np % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_printable(str[i]))
			ft_putchar(str[i]);
		else
			put_non_printable(str[i]);
		i++;
	}
}

int main()
{
	ft_putstr_non_printable("\n");
}
