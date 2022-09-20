/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:13:51 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/02/20 15:52:04 by nvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	j = argc;
	i = 1;
	while (++i <= argc)
	{
		j = 1;
		while (++j <= argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j - 1]) < 0)
			{
				tmp = argv[j];
				argv[j] = argv[j - 1];
				argv[j - 1] = tmp;
			}
		}
	}
	i = 0;
	while (++i < argc)
		ft_putstr(argv[i]);
}
