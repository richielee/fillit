/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:28:47 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 18:28:55 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

char	**str_truncate(char *str)
{
	int		n;
	int		block;
	char	**arr;
	int		i;

	i = 0;
	n = ft_strlen(str);
	block = (n + 1) / 21;
	if (!(arr = (char**)malloc(sizeof(char*) * (block + 1))))
		return (NULL);
	while (i < block)
	{
		if (!(arr[i] = (char*)malloc(sizeof(char*) * 21)))
			return (NULL);
		ft_strncpy(arr[i], str + (21 * i), 20);
		arr[i][20] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void	free_board(t_board *board)
{
	int i;

	i = 0;
	while (i < board->size)
	{
		ft_memdel((void **)&(board->arr[i]));
		i++;
	}
	ft_memdel((void **)&(board->arr));
	ft_memdel((void **)&(board));
}
