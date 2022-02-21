/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:01:56 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/02/21 16:54:42 by nvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_lngth(int size, char **strs, char *sep)
{
	int	i;
	int	lng;

	i = 0;
	lng = 0;
	while (i < size)
	{
		lng = lng + ft_strlen(strs[i]);
		i++;
	}
	lng = lng + (ft_strlen(sep) * (size - 1)) + 1;
	return (lng);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*conc;

	if (size == 0)
	{
		conc = malloc(sizeof(char));
		*conc = 0;
		return (conc);
	}
	conc = (char *) malloc(sizeof(ft_lngth(size, strs, sep)));
	if (!(conc))
		return (0);
	i = 0;
	*conc = 0;
	while (i < size)
	{
		ft_strcat(conc, strs[i]);
		if (i < size - 1)
			ft_strcat(conc, sep);
		i++;
	}
	return (conc);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(4, argv + 1, " "));
}
