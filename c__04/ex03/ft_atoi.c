/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:37:36 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/02/18 12:17:05 by nvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	num;
	int	i;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\r')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == ' ')))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("---+--+1234ab567"));
}