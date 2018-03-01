/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:39:11 by ikozlov           #+#    #+#             */
/*   Updated: 2018/02/28 22:24:32 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_PIECES (26)
# define MAX_MAP (16)

# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_piece
{
	u_int64_t		value;
	char			id;
	unsigned char	x;
	unsigned char	y;
	unsigned char	height;
	unsigned char	width;
}					t_piece;

int					read_pieces(const int fd, t_piece *t);
int					read_tetris(const int fd, t_piece *t);
int					solve(t_piece *tetris, const int count);

#endif
