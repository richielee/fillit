/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:49:23 by rili              #+#    #+#             */
/*   Updated: 2017/04/25 12:52:07 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*srcc;
	unsigned char	*dstc;

	srcc = (unsigned char*)src;
	dstc = (unsigned char*)dst;
	if (srcc < dstc)
	{
		srcc += len;
		dstc += len;
		while (len--)
			*--dstc = *--srcc;
	}
	else
		while (len--)
			*dstc++ = *srcc++;
	return (dst);
}
