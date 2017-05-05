/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:56:53 by rili              #+#    #+#             */
/*   Updated: 2017/04/21 17:56:58 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fresh = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < (int)len)
	{
		fresh[i] = s[i + start];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
