/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:14:37 by rili              #+#    #+#             */
/*   Updated: 2017/04/25 17:14:35 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		neg;
	int		result;

	neg = 0;
	s = (char*)str;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
			s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		neg = ((s[i] == '-') ? 1 : 0);
		i++;
	}
	result = 0;
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
		result = 10 * result + s[i++] - '0';
	if (i > 19)
		return (neg ? 0 : -1);
	return (neg ? (-1) * result : result);
}
