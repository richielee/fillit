/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_reader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:25:48 by rili              #+#    #+#             */
/*   Updated: 2017/05/05 13:23:52 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_read(char *file)
{
	t_read	readstr;
	char	*buf;
	char	*receivedstring;
	char	*tmp;
	int		fd;

	buf = ft_memalloc(sizeof(char) * 2);
	receivedstring = ft_memalloc(sizeof(char));
	receivedstring[0] = '\0';
	readstr.i = 1;
	fd = open(file, O_RDONLY);
	while ((readstr.ret = read(fd, buf, 1)) != 0)
	{
		buf[readstr.ret] = '\0';
		tmp = ft_memalloc(sizeof(char) * readstr.i + 1);
		ft_strcpy(tmp, receivedstring);
		receivedstring = ft_memalloc(sizeof(char) * (ft_strlen(tmp) + 2));
		receivedstring = ft_strcat(tmp, buf);
		readstr.i++;
	}
	free(buf);
	return (receivedstring);
}
