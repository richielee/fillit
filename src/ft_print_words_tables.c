/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:29:11 by rili              #+#    #+#             */
/*   Updated: 2017/05/05 13:54:41 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** This is the modified version of the original ft_print_words_tables.
** As the custom data strcuture is not 0-terminated, it is necessary to
** stipulate the size of the **tab.
*/

void	ft_print_words_tables(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
