/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:35:00 by rili              #+#    #+#             */
/*   Updated: 2017/04/21 18:11:15 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!(mem = (char*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void*)mem);
}
