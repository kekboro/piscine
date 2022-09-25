/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:09:38 by maykman           #+#    #+#             */
/*   Updated: 2022/02/20 11:18:37 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <sys/types.h>
//# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

// A REMOVE !!!!!
# include <stdio.h>

# define FD_ERROR		-1
# define MALLOC_ERROR	-2

// Files functions
int		get_file(char **line, char *filename);
int		get_file_size(char *filename);

// Utils functions
void	ft_putchar(char c);
void	ft_putstr(char *str);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif