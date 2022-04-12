/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:42:27 by nvan-ges          #+#    #+#             */
/*   Updated: 2022/04/12 15:13:54 by nvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memcpy(void *dest, const void *src, size_t n) 
{
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *) src)[i];
		n--;
	}
	return (dest);
}
