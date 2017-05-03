/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:09:00 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 16:47:47 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
		i++;
	}
}
