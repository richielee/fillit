/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:59:28 by rili              #+#    #+#             */
/*   Updated: 2017/04/21 18:01:22 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	totallen;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	totallen = ft_strlen(s1) + ft_strlen(s2);
	if (!(fresh = (char*)malloc(sizeof(char) * (totallen + 1))))
		return (NULL);
	while (++i < ft_strlen(s1))
		fresh[i] = s1[i];
	while (++j < ft_strlen(s2))
		fresh[i + j] = s2[j];
	fresh[i + j] = '\0';
	return (fresh);
}
