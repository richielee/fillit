/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:18:32 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 21:28:05 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	char	*input;
	t_board	*board;
	int		block;
	t_tetri	**tetris;

	if (argc == 2)
	{
		input = ft_read(argv[1]);
		block = (ft_strlen(input) + 1) / 21;
		if (!ft_check(input, block))
		{
			ft_putstr("error\n");
			return (1);
		}
		tetris = change_data_structure(str_truncate(input), block);
		board = solve(tetris, block);
		ft_print_words_tables(board->arr, board->size);
		free_board(board);
		return (0);
	}
	else
	{
		ft_putstr("usage: fillit input_file\n");
	}
	return (1);
}
