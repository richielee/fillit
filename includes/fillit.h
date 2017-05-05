/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:22:57 by rili              #+#    #+#             */
/*   Updated: 2017/05/04 14:30:23 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../lib/libft.h"
# include "stdio.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;
typedef struct	s_board
{
	int		size;
	char	**arr;
}				t_board;
typedef struct	s_tetri
{
	t_point		*min;
	t_point		*max;
	char		**graph;
	char		seq;
}				t_tetri;
typedef struct	s_read
{
	int			i;
	int			ret;
}				t_read;
char			*ft_read(char *file);
int				ft_check(char *s, int block);
char			**str_truncate(char *str);
t_board			*new_board(int size);
t_board			*solve(t_tetri **tetris, int block);
t_tetri			**change_data_structure(char **arr, int block);
void			print_tetri(t_tetri **input, int block);
void			free_board(t_board *board);
void			ft_print_words_tables(char **tab, int size);
t_point			*new_point(int x, int y);
int				ft_abs(int n);
#endif
