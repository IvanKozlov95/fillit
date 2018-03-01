/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:39:11 by ikozlov           #+#    #+#             */
/*   Updated: 2018/02/28 17:30:17 by ikozlov          ###   ########.fr       */
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

typedef struct	s_piece
{
	// struct s_piece			*last;
	u_int64_t		value;
	char			id;
	unsigned char	x;
	unsigned char	y;
	unsigned char	height;
	unsigned char	width;
}				t_piece;

int				read_tetris(const int fd, t_piece *t);

#endif
