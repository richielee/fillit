/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_reader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:25:48 by rili              #+#    #+#             */
/*   Updated: 2017/05/03 15:07:13 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"

char	*ft_read(char *file)
{
	int		ret;
	int		i;
	char	*buf;
	char	*receivedstring;
	char	*tmp;
	int		fd;

	if (!(buf = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	if (!(receivedstring = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	receivedstring[0] = '\0';
	i = 1;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, 1)) != 0)
	{
		buf[ret] = '\0';
		if (!(tmp = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		ft_strcpy(tmp, receivedstring);
		if (!(receivedstring = (char*)malloc(sizeof(char) *
						(ft_strlen(tmp) + 2))))
			return (NULL);
		receivedstring = ft_strcat(tmp, buf);
		i++;
	}
	return (receivedstring);
}
