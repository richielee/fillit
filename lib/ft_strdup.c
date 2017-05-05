/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:06:48 by rili              #+#    #+#             */
/*   Updated: 2017/04/21 16:23:10 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		s[i] = *(((unsigned char*)s1) + i);
		i++;
	}
	s[i] = '\0';
	return (s);
}
