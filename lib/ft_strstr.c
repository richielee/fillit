/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:38:28 by rili              #+#    #+#             */
/*   Updated: 2017/04/25 13:43:10 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(big);
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (i < len)
	{
		if (ft_memcmp(big + i, little, ft_strlen(little)) == 0)
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
