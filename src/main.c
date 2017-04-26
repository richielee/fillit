/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:18:32 by rili              #+#    #+#             */
/*   Updated: 2017/04/26 19:44:51 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"

void	error_msg(void)
{
	ft_putstr("error\n");
}

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
	int		n;
	int		x;

	if (argc == 2)
	{
		input = ft_read(argv[1]);
		ft_putstr(input);
		ft_putstr("testing complete\n");
		x = (n + 1) / 5;
		ft_check(input);
		ft_print_words_tables(str_truncate(input));
		return (0);
	}
	else
		return (1);
}
