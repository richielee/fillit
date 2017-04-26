/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:18:32 by rili              #+#    #+#             */
/*   Updated: 2017/04/26 17:51:48 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
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
	int		n;

	if (argc == 2)
	{
		input = ft_read(argv[1]);
		n = count_n(input);
		ft_putnbr(n);
		return (0);
	}
	else
		return (1);
}
