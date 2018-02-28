/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:02:48 by mtan              #+#    #+#             */
/*   Updated: 2018/02/28 15:03:02 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


// main read function
int		read_tetris(const int fd, t_etris *t)
{
	char	*buf[22];
	char	id;
	int		size;
	int		i;
	int		j;

	id = 'A';

	while ((size = read(fd, buf, 21)))
	{
		// check valid file
		if (!valid_block(buf) || size != 21)
			return (0);
		// stores each piece with character
		tetris = store_piece(buf, id++);
		// set linkage for ptr to
		j = i - 1;
		// while ()
	}
	// returns count of pieces if valid
	return (id - 'A');
}
