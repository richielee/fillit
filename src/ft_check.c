/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:31:17 by rili              #+#    #+#             */
/*   Updated: 2017/05/05 14:10:11 by rili             ###   ########.fr       */
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

static int		coordinate_check(t_point *hash)
{
	int i;
	int j;
	int distance;
	int neighbor_count;

	i = 0;
	neighbor_count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != j)
			{
				distance = ft_abs(hash[i].x - hash[j].x) \
						+ ft_abs(hash[i].y - hash[j].y);
				neighbor_count += (distance == 1);
			}
			j++;
		}
		i++;
	}
	return (neighbor_count == 6 || neighbor_count == 8);
}

/*
** We start with block_check, which is a function that returns 1 if the input
** is 'globally' acceptable. It checks for the number of '.', '#' and '\n'.
** We then proceed to check that the '\n' separating the blocks are at the
** right positions. Once the above are done, we then check that each block
** represents a piece of valid tetri. This is done by first truncating the
** input string into blocks, then iterating through each block to check if
** the tetri is valid in each block. A tetri is valid when the sum of the
** number of neighbors each '#' is either 6 or 8.
*/

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
