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

void	get_dimensions(char *dim, const char *str)
{
	// unsigned char?
	int i;

	// initialize xMin, xMax, yMin, yMax for i = 0, 1, 2, 3
	dim[0] = 3;
	dim[1] = 0;
	dim[2] = 3;
	dim[3] = 0;
	i = -1;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < dim[0])
				dim[0] = i % 5;
			if (i % 5 > dim[1])
				dim[1] = i % 5;
			if (i / 5 < dim[2])
				dim[2] = i / 5;
			if (i / 5 > dim[3])
				dim[3] = i / 5;
		}
	}

}

t_piece	store_piece(const char *str, char id)
{
	t_piece	tmp;
	char	dim[4];

	get_dimensions(dim, str);
	tmp.id = id;

	// tmp.last = NULL;
	return (tmp);
}

int		valid_piece(const char *str)
{
	/*
	an edge connects two adjacent hexes.
	a valid piece is defined as having a total of 3/4 distinct edges
	*/
	int		i;
	int		edge;

	i = -1;
 	edge = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			// top
			if (i > 4 && str[i - 5] == '#')
				edge++;
			// bottom
			if (i < 14 && str[i + 5] == '#')
				edge++;
			// left
			if (i % 5 > 0 && str[i - 1] == '#')
				edge++;
			// right
			if (i % 5 < 3 && str[i + 1] == '#')
				edge++;
		}
	}
	return (edge == 6 || edge == 8);
}

int		valid_block(const char *str)
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
	char	buf[22];
	char	id;
	int		size;
	int		i;
	// int		j;

	id = 'A';
	i = 0;
	while ((size = read(fd, buf, 21)))
	{
		// check valid file
		if (size != 21 || !valid_block(buf))
			return (0);
		// stores each piece with character
		t[i++] = store_piece(buf, id++);
		// set linkage for ptr to
		// j = i - 1;
		// while ()
	}
	// returns count of pieces if valid
	return (id - 'A');
}
