/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:14:57 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 16:15:46 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_board		*new_board(int size)
{
	t_board	*new;
	int		i;
	int		j;

	i = 0;
	new = (t_board*)ft_memalloc(sizeof(t_board));
	new->size = size;
	new->arr = (char**)ft_memalloc(sizeof(char*) * size);
	while (i < size)
	{
		new->arr[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			new->arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (new);
}

int		get_upper_left(char *tetri)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
			return (i);
		i++;
	}
	return (-1);
}
/*
int		placeable(t_board *board, char *tetri, int x, int y, int upper_left)
{
	int i;
	int j;

	i = upper_left / 5;
	while (i < 4)
	{
		j = upper_left % 5;
		while (j < 4)
		{
			if (tetri[5 * i + j] == '#'
		}
	}
}*/
t_board		*solve(char **s)
{
	int		size;
	t_board	*board;

	size = 4;
	(void)s;
	board = new_board(size);
	return (board);
}
