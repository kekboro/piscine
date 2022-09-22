/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:01:56 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/09/22 14:31:55 by nevan-ge         ###   ########.fr       */
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
	int	lngth;

	i = 0;
	lngth = 0;
	while (i < size)
	{
		lngth = lngth + ft_strlen(strs[i]);
		i++;
	}
	lngth = lngth + (ft_strlen(sep) * (size - 1)) + 1;
	return (lngth);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;

	if (size == 0)
	{
		result = malloc(sizeof(char));
		*result = 0;
		return (result);
	}
	result = (char *) malloc(sizeof(ft_lngth(size, strs, sep)));
	if (!(result))
		return (0);
	i = 0;
	*result = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
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

