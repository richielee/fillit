/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:10:17 by rili              #+#    #+#             */
/*   Updated: 2017/04/21 18:09:03 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_strrev(char *s, int len)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < (len / 2))
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
		i++;
	}
	return (s);
}

static char	*stupid_norm(int n, int neg)
{
	char	*num;
	int		i;
	int		rem;

	if (!(num = (char*)malloc(sizeof(char) * (length(n) + 1 + neg))))
		return (NULL);
	i = 0;
	if (n == 0)
	{
		num[i++] = '0';
		num[i] = '\0';
	}
	while (n)
	{
		rem = n % 10;
		num[i++] = rem + '0';
		n /= 10;
	}
	if (neg)
		num[i++] = '-';
	num[i] = '\0';
	return (ft_strrev(num, (int)ft_strlen(num)));
}

char		*ft_itoa(int n)
{
	int		neg;
	int		i;

	neg = 0;
	i = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (stupid_norm(n, neg));
}
