/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:35:10 by rili              #+#    #+#             */
/*   Updated: 2017/04/21 18:29:10 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cw(char const *str, char c)
{
	int i;
	int state;
	int wc;

	wc = 0;
	i = 0;
	state = 0;
	while (str[i])
	{
		if (str[i] == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			wc++;
		}
		i++;
	}
	return (wc);
}

static int		wl(char const *str, int start, char c)
{
	int i;

	i = 0;
	while (str[start + i] && str[start + i] != c)
		i++;
	return (i);
}

static char		*f_strcpy(char *dest, char const *str, int start, char c)
{
	int		i;

	i = 0;
	while (str[start + i] && str[start + i] != c)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**ar;
	int		i;
	int		word;

	if (!str || !(ar = (char**)malloc(sizeof(char*) * (cw(str, c) + 1))))
		return (NULL);
	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			if (!(ar[word] = (char*)malloc(sizeof(char) * (wl(str, i, c) + 1))))
				return (NULL);
			f_strcpy(ar[word], str, i, c);
			i += wl(str, i, c);
			word++;
		}
	}
	ar[word] = 0;
	return (ar);
}
