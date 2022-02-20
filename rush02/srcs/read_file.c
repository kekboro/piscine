/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:12:53 by maykman           #+#    #+#             */
/*   Updated: 2022/02/20 11:19:16 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	get_file_size(char *filename)
{
	int	fd;
	int	size;
	char	buff[1];

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (-1);
	size = 0;
	while (read(fd, buff, 1) > 0)
		size++;
	close(fd);
	return (size);
}

int	copy_file(char **file, char *filename, int size)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (0);
	if (read(fd, *file, size) < 0)
		return (0);
	return (1);
}

int	get_file(char **file, char *filename)
{
	int	filesize;

	filesize = get_file_size(filename);
	if (filesize < 0)
		return (0);
	*file = (char *)ft_calloc(sizeof(char), filesize + 1);
	if (!*file)
		return (0);
	if (!copy_file(file, filename, filesize))
		return (0);
	return (1);
}
