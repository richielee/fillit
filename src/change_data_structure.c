/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_data_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:29:11 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 17:35:58 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char			**get_graph(char *str)
{
	int		i;
	char	**arr;

	if (!(arr = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(arr[i] = (char*)malloc(sizeof(char*) * 5)))
			return (NULL);
		ft_strncpy(arr[i], str + (5 * i), 4);
		arr[i][4] = '\0';
		i++;
	}
	return (arr);
}

static t_point		*new_point(int x, int y)
{
	t_point	*new;

	new = ft_memalloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	return (new);
}

static t_point		*get_max(char **arr)
{
	int		i;
	int		j;
	t_point	*max;

	max = new_point(0, 0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
			{
				if (i > max->x)
					max->x = i;
				if (j > max->y)
					max->y = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

static t_point		*get_min(char **arr)
{
	int		i;
	int		j;
	t_point	*min;

	min = new_point(3, 3);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
			{
				if (i < min->x)
					min->x = i;
				if (j < min->y)
					min->y = j;
			}
			j++;
		}
		i++;
	}
	return (min);
}

t_tetri				**change_data_structure(char **arr, int block)
{
	int		i;
	t_tetri	**new;

	new = (t_tetri**)malloc(sizeof(t_tetri*) * block);
	i = 0;
	while (arr[i])
	{
		new[i] = (t_tetri*)malloc(sizeof(t_tetri));
		new[i]->graph = get_graph(arr[i]);
		new[i]->min = get_min(new[i]->graph);
		new[i]->max = get_max(new[i]->graph);
		new[i]->seq = 'A' + i;
		i++;
	}
	return (new);
}
