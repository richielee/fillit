/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:09:00 by rili              #+#    #+#             */
/*   Updated: 2017/05/05 13:54:59 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** The function print_tetri prints each block of the original file,
** the min and max of x and y, and the corresponding character.
** This is mainly used for debugging.
*/

static void	ft_putpoint(t_point *point)
{
	ft_putnbr(point->x);
	ft_putstr(", ");
	ft_putnbr(point->y);
	ft_putstr(".\n");
}

void		print_tetri(t_tetri **input, int block)
{
	int i;

	i = 0;
	ft_putstr("printing tetris...\n");
	while (i < block)
	{
		ft_putstr("Tetri number ");
		ft_putnbr(i);
		ft_putstr(":\n");
		ft_print_words_tables(input[i]->graph, 4);
		ft_putstr("min_x, min_y: \n");
		ft_putpoint(input[i]->min);
		ft_putstr("max_x, max_y: \n");
		ft_putpoint(input[i]->max);
		ft_putstr("seq is:");
		ft_putchar(input[i]->seq);
		ft_putchar('\n');
		i++;
	}
}
