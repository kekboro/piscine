/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:47:01 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/02/18 10:02:53 by nvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *src)
{
    char *new;
    int i;

    i = 0;
    if (!(new = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
        return NULL;
    while (*src)
        new[i++] = *src++;
    new[i] = '\0';
    return (new);
}
