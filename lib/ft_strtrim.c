/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:03:13 by rili              #+#    #+#             */
/*   Updated: 2017/04/25 17:28:44 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	front_space(char const *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static int	back_space(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i -= 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	start = front_space(s);
	end = back_space(s);
	if (end < start)
		return (ft_strdup("\0"));
	if (!(fresh = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (i < end - start + 1)
	{
		fresh[i] = s[start + i];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
