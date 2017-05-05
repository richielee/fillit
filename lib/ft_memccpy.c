/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:04:23 by rili              #+#    #+#             */
/*   Updated: 2017/04/25 12:31:54 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dstu;
	unsigned char	*srcu;

	dstu = (unsigned char*)dst;
	srcu = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		if ((*dstu++ = *srcu++) == (unsigned char)c)
			return (dstu);
		i++;
	}
	return (NULL);
}
