/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:31:17 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 21:55:53 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes//fillit.h"

static int		block_check(char *read)
{
	int dot;
	int hash;
	int end;

	dot = 0;
	hash = 0;
	end = 0;
	while (*read)
	{
		if (*read == '.')
			dot++;
		else if (*read == '#')
			hash++;
		else if (*read == '\n')
			end++;
		else
			return (0);
		read++;
	}
	if (dot < 4)
		return (0);
	if (dot % 4 || hash % 4 || (end + 1) % 5 || !hash)
		return (0);
	return (1);
}

static t_point	*assign_hash_positions(char *str)
{
	int		i;
	int		c;
	t_point	*hashes;
	t_point	tmp;

	if (!(hashes = (t_point*)malloc(sizeof(t_point) * 4)))
		return (NULL);
	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			tmp.x = i % 5;
			tmp.y = i / 5;
			hashes[c] = tmp;
			c++;
		}
		i++;
	}
	return (hashes);
}

static int		coordinate_check(t_point *hash)
{
	int i;
	int j;
	int distance;
	int answer;

	i = 0;
	j = 0;
	while (i < 4)
	{
		answer = 0;
		while (j < 4)
		{
			if (i != j)
			{
				distance = ft_abs(hash[i].x - hash[j].x) + \
						ft_abs(hash[i].y - hash[j].y);
				answer += distance;
			}
			if (answer > 6)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		check_spaces(char *read, int block)
{
	int i;

	i = 0;
	while (i < (block - 1))
	{
		if (read[21 * (i + 1) - 1] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int				ft_check(char *read, int block)
{
	int		i;
	char	**arr;

	i = 0;
	if (!block_check(read) || !check_spaces(read, block))
		return (0);
	else
	{
		arr = str_truncate(read);
		while (arr[i])
		{
			if (!coordinate_check(assign_hash_positions(arr[i])))
				return (0);
			i++;
		}
		return (1);
	}
}
