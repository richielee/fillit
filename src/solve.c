/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:14:57 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 19:25:25 by rili             ###   ########.fr       */
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

static void		put_tetris(t_board *board, t_tetri *tetri, int x, int y, char s)
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
				board->arr[x + i - mi][y + j - mj] = s;
			j++;
		}
		i++;
	}
}

int		placeable(t_board *board, t_tetri *tetri, int x, int y)
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
	put_tetris(board, tetri, x, y, tetri->seq);
	return (1);
}

int			solve_board(t_board *board, t_tetri **tetris, int block, int current)
{
	int		i;
	int		j;
	int		w;
	int		h;
	t_tetri	*tetri;

	if (current == block)
		return (1);
	tetri = (t_tetri*)malloc(sizeof(t_tetri));
	tetri = tetris[current];
	i = 0;
	h = (tetri->max->x) - (tetri->min->x) + 1;
	w = (tetri->max->y) - (tetri->min->y) + 1;
	while (i < board->size - h + 1)
	{
		j = 0;
		while (j < board->size - w + 1)
		{
			if (placeable(board, tetri, i, j))
			{
				if (solve_board(board, tetris, block, current + 1))
					return (1);
				else
					put_tetris(board, tetri, i, j, '.');
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

	size = 4;
	board = new_board(size);
	while (!solve_board(board, tetris, block, 0))
	{
		size++;
		free_board(board);
		board = new_board(size);
	}
	return (board);
}
