 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:08:35 by maykman           #+#    #+#             */
/*   Updated: 2022/02/20 10:53:13 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int argc, char **argv)
{
	char	*file;
	char	*filename;

	(void)argc;
	(void)argv;
	file = NULL;
	filename = "numbers.dict";
	if (get_file(&file, filename))
		printf("%s\n", file);
	else
		printf("ERROR\n");
	return (0);
}