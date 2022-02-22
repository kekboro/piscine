/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:47:01 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/02/22 14:50:29 by nvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!(new))
		return (0);
	while (*src)
		new[i++] = *src++;
	new[i] = '\0';
	return (new);
}

#include <stdio.h>

int main()
{
	char *src = "hello";
	char *theirs = NULL;
	char *mine = NULL;

	mine = ft_strdup(src);
	theirs = ft_strdup(src);
	printf("%s\n%s\n", mine, theirs);
	return(0);
}