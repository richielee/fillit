/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:38:28 by rili              #+#    #+#             */
/*   Updated: 2017/04/25 13:57:46 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;

	len = ft_strlen(little);
	if (!*little)
		return ((char*)big);
	while (*big && n-- >= len)
	{
		if (ft_memcmp(big, little, len) == 0)
			return (char*)(big);
		big++;
	}
	return (NULL);
}
