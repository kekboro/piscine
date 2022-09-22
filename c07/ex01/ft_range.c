/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:10:32 by nevan-ge          #+#    #+#             */
/*   Updated: 2022/09/22 14:00:58 by nevan-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	i = 0;
	if (min >= max)
		return (0);
	range = (int *)malloc(sizeof(int) * (max - min));
	if (!(range))
		return (0);
	while (max < min)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
