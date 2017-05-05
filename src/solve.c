/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:14:57 by rili              #+#    #+#             */
/*   Updated: 2017/05/05 14:01:47 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Generate a new board.
*/

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

/*
** A function that places a t_tetri object at point p on the board.
** This is achievable because board is passed by address.
*/

static void	put_tetris(t_board *board, t_tetri *tetri, t_point *p, char s)
{
	int	i;
	int	j;
	int	mi;
	int	mj;

	mi = tetri->min->x;
	mj = tetri->min->y;
	i = mi;
	while (i <= tetri->max->x)
	{
		j = mj;
		while (j <= tetri->max->y)
		{
			if (tetri->graph[i][j] == '#')
				board->arr[p->x + i - mi][p->y + j - mj] = s;
			j++;
		}
		i++;
	}
}

/*
** A helper function to determine whether an item can be placed in the x, y
** postion. If the item can be placed, the function  tentatively place the
** item by calling the function put_tetris and return 1. Otherwise the
** function return 0.
*/

static int	placeable(t_board *board, t_tetri *tetri, int x, int y)
{
	int	i;
	int	j;
	int	mi;
	int	mj;

	mi = tetri->min->x;
	mj = tetri->min->y;
	i = mi;
	while (i <= tetri->max->x)
	{
		j = mj;
		while (j <= tetri->max->y)
		{
			if (tetri->graph[i][j] == '#' && \
					board->arr[x + i - mi][y + j - mj] != '.')
				return (0);
			j++;
		}
		i++;
	}
	put_tetris(board, tetri, new_point(x, y), tetri->seq);
	return (1);
}

/*
** Implementation of the backtracking algorithm. We assume that the current
** configuration is correct and proceed to place the item. By doing so
** recursively, we could reach the end of **tetris, in which case we
** claim that we have found the solution. We could also read to a state where
** it is not possible to place the remaining item, in which case we would
** abort the current configuration (thus backtrack) and try the next possible
** configuration.
*/

static int	solve_board(t_board *board, t_tetri **tetris, int block, int cur)
{
	int		i;
	int		j;

	if (cur == block)
		return (1);
	i = 0;
	while (i < board->size - tetris[cur]->max->x + tetris[cur]->min->x)
	{
		j = 0;
		while (j < board->size - tetris[cur]->max->y + tetris[cur]->min->y)
		{
			if (placeable(board, tetris[cur], i, j))
			{
				if (solve_board(board, tetris, block, cur + 1))
					return (1);
				else
					put_tetris(board, tetris[cur], new_point(i, j), '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_board		*solve(t_tetri **tetris, int block)
{
	int		size;
	t_board	*board;

	size = 3;
	board = new_board(size);
	while (!solve_board(board, tetris, block, 0))
	{
		size++;
		free_board(board);
		board = new_board(size);
	}
	return (board);
}
