/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:32:24 by febonaer          #+#    #+#             */
/*   Updated: 2022/02/13 18:54:58 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*int	*ft_handle32(int *res)
{
	
}*/

int	*ft_fillRow(int *res, int line)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i <= 3)
	{
		if (res[line] > 4)
			j = line;
		else
			count = count + res[line];
		i++;
		line++;
	}
	res[j] = 10 - count;
	return (res);
}

int	*ft_fillCol(int *res, int col)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i <= 3)
	{
		if (res[col] > 4)
			j = col;
		else
			count = count + res[col];
		i++;
		col = col + 4;
	}
	res[j] = 10 - count;
	return (res);
}

int	*ft_checkCol(int *res)
{
	int i;
	int	count;
	int k;
	int j;

	i = 0;
	while (i <= 3)
	{
		k = 0;
		count = 0;
		while (k <= 3)
		{
			j = k * 4 + i;
			if (res[j] < 10)
				count++;
			if (count == 3 && k == 3)
				res = ft_fillCol(res, i);
			k++;
		}
		i++;
	}
	return (res);
}

int	*ft_checkRow(int *res)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i >= 0 && i <= 3)
	{
		if (res[i] < 10)
			count++;
		if (count == 3 && i == 3)
			res = ft_fillRow(res, 0);
		i++;
	}
	count = 0;
	while (i >= 4 && i <= 7)
	{
		if (res[i] < 10)
			count++;
		if (count == 3 && i == 7)
			res = ft_fillRow(res, 4);
		i++;
	}
	count = 0;
	while (i >= 8 && i <= 11)
	{
		if (res[i] < 10)
			count++;
		if (count == 3 && i == 11)
			res = ft_fillRow(res, 8);
		i++;
	}
	count = 0;
	while (i >= 12 && i <= 15)
	{
		if (res[i] < 10)
			count++;
		if (count == 3 && i == 15)
			res = ft_fillRow(res, 12);
		i++;
	}
	return (res);
}
int	*ft_elimination(int *res)
{
	if (!(res = ft_checkRow(res)))
		return (0);
	if (!(res = ft_checkCol(res)))
		return (0);
	if (!(res = ft_handle32(res)))
		return (0);
	/*if (!(res = ft_handleposs(res)))
		return (0);*/
	return (res);
}

//Handle every single cases for the 1 clue.
int	*ft_one(int *res, int i)
{
	if (i == 1 || i == 9)
		res[0] = 4;
	else if (i == 2)
		res[1] = 4;
	else if (i == 3)
		res[2] = 4;
	else if (i == 4 || i == 13)
		res[3] = 4;
	else if (i == 14)
		res[7] = 4;
	else if (i == 15)
		res[11] = 4;
	else if (i == 8 || i == 16)
		res[15] = 4;
	else if (i == 7)
		res[14] = 4;
	else if (i == 6)
		res[13] = 4;
	else if (i == 12 || i == 5)
		res[12] = 4;
	else if (i == 11)
		res[8] = 4;
	else if (i == 10)
		res[4] = 4;
	return (res);
}

//Handle every single cases for the 4 clue.
int	*ft_four(int *res, int i, int j)
{
	int k;
	k = 1;
	while (i >= 0 && i <= 3 && k <= 4)
	{
		res[j] = k;
		k++;
		j = j + 4;
	}
	j = (i - 11) * 4 - 1;
	while (i >= 12 && i <= 15 && k <= 4)
	{
		res[j] = k;
		k++;
		j--;
	}
	j = (i - 8) * 4;
	while (i >= 8 && i <= 11 && k <= 4)
	{
		res[j] = k;
		printf("valeur j:%d\n", j);
		k++;
		j++;
	}
	j = (i - 4) + 12;
	while (i >= 4 && i <= 7 && k <= 4)
	{
		res[j] = k;
		k++;
		j = j - 4;
	}
	return (res);
}

//handle the clues we can already fill in.
int	*ft_edge(int *res, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '4')
			res = ft_four(res, i, i);
		printf("res[1] = %d\n", res[1]);
		if (str[i] == '1')
			res = ft_one(res, i + 1);
		i++;
	}
	return (res);
}

//Removes the spaces in the base string to be able to iterate faster.
char	*ft_stringformat(char *tab, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			tab[j] = str[i];
			j++;
		}
		i++;
	}
	return (tab);
}

int	ft_solver(char *str)
{
	int res[16];
	int i;
	char	*tab;

	i = 0;
	while (i < 16)
	{
		res[i] = 1234;
		i++;
	}
	if (!(tab = (char *)malloc(16)))
		return (0);
	tab = ft_stringformat(tab, str);
	ft_edge(res, tab);
	//while (i <= 4)
	//{
	ft_elimination(res);
	//	i++;
	//}
	i = 0;
	return (0);
}

//Verify if the string is 31 char long and if there are only digits in it.
int	ft_checkinput(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i != 31)
		return (0);
	i--;
	while (i >= 0)
	{
		if (i == 0 || i % 2 == 0)
		{
			if (str[i] <= '4' && str[i] >= '1')
				i--;
			else
				return (0);
		}
		else if (i % 2 == 1)
		{
			if (str[i] == ' ')
				i--;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_checkinput(argv[1]) != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_solver(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	int i = 0;
	return (0);
}
