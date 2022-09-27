/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:14:58 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/09/27 15:03:25 by nevan-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	k;

	i = 1;
	k = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else if ((power == 0) && (nb == 0))
		return (1);
	while (i != power)
	{
		k = nb * k;
		i++;
	}
	return (k);
}
 #include <stdio.h>
 int main()
 {
	printf("%d\n", ft_iterative_power(0, 2));
 }