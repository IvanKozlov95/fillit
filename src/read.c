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

int		valid_piece(char *str)
{
	/*
	an edge connects two adjacent hexes.
	a valid piece is defined as having a total of 3/4 distinct edges
	*/
	int		i;
	int		hex;

	i = -1;
	hex = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if ()
		}
	}
}

int		valid_block(char *str)
{
	//check symbols, and nl
	int		i;
	int		hex;

	i = -1;
	hex = 0;
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] == '#')
				hex++;
			else if (str[i] != '.')
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
	}
	if (!(str[20] == '\n' && valid_piece(str)))
		return (0);
	return (1);
}
// main read function
int		read_tetris(const int fd, t_piece *t)
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
		if (size != 21 || !valid_block(buf))
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
