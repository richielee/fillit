/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:18:32 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 16:18:49 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		count_n(char *input)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			c++;
		i++;
	}
	return (c);
}

int		main(int argc, char **argv)
{
	char	*input;
	t_board	*board;
	int		block;
	t_tetri	**test;

	if (argc == 2)
	{
		input = ft_read(argv[1]);
		if (!ft_check(input))
		{
			ft_putstr("error\n");
			return (1);
		}
		block = (ft_strlen(input) + 1) / 21;
		//ft_print_words_tables(str_truncate(input));
		printf("still alive\n");
		test = change_data_structure(str_truncate(input), block);
		printf("still alive after test\n");
		print_tetri(test, block);
		board = solve(str_truncate(input));
		printf("still alive\n");
		ft_print_words_tables(board->arr, board->size);
		printf("still alive\n");
		//free_board(*board);
		return (0);
	}
	else
	{
		ft_putstr("usage: fillit input_file\n");
	}
		return (1);
}
