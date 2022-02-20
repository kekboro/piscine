/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:45:16 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/02/15 13:37:42 by nvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb == 2 || nb == 3)
		return (1);
	else if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	else
	{
		while (i * i < nb)
		{
			if (nb % i == 0)
				return (0);
			else
				i++;
		}
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb + 1) == 0)
		nb++;
	return (nb + 1);
}
