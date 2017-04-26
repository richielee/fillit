/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:22:57 by rili              #+#    #+#             */
/*   Updated: 2017/04/26 19:44:31 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "../lib/libft.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;
char			*ft_read(char *file);
int				ft_check(char *s);
void			error_msg(void);
char	**str_truncate(char *str);
void	ft_print_words_tables(char **tab);
#endif
