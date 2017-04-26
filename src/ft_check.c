/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:31:17 by rili              #+#    #+#             */
/*   Updated: 2017/04/26 19:42:45 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes//fillit.h"

int	ft_check(char *read)
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
		read++;
	}
	if (dot < 4)
		return (0);
	if (dot % 4 || hash % 4 || (end + 1) % 5)
		return (0);
	return (1);
}
