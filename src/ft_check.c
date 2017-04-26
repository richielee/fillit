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

void	ft_check(char *read)
{
	int period;
	int pound;
	int end;

	period = 0;
	pound = 0;
	end = 0;
	while (*read)
	{
		if (*read == '.')
			period++;
		else if (*read == '#')
			pound++;
		else if (*read == '\n')
			end++;
		read++;
	}
	if (period < 4)
		error_msg();
	if (period % 4 || pound % 4 || (end + 1) % 5)
		error_msg();
}
