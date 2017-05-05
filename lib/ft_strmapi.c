/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:47:18 by rili              #+#    #+#             */
/*   Updated: 2017/04/21 17:56:07 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fresh = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
