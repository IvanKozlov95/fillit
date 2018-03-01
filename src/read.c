/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:02:48 by mtan              #+#    #+#             */
/*   Updated: 2018/02/28 22:23:23 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_dimensions(char *dim, const char *str)
{
	int i;

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
	int		x;
	int		y;
	printf("%c", id);
	get_dimensions(dim, str);
	tmp.id = id;
	tmp.width = dim[1] - dim[0] + 1;
	tmp.height = dim[3] - dim[2] + 1;

	y = -1;
	while (++y < tmp.height)
	{
		x = -1;
		while (++x < tmp.width)
		{
			if (str[(dim[0] + x) + (dim[2] + y) * 5] == '#')
				tmp.value |= (1L << (16 * (y + 1) - 1 - x));
		}
	}
	return (tmp);
}

/*
** an edge connects two adjacent hexes.
** a valid piece is defined as having a total of 3/4 distinct edges
*/

int		valid_piece(const char *str)
{
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

int		valid_block(const char *str, int size)
{
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
	if (size == 21 && str[20] != '\n')
		return (0);
	if (!valid_piece(str))
		return (0);
	return (1);
}

int		read_pieces(const int fd, t_piece *t)
{
	char	buf[22];
	char	id;
	int		size;
	int		i;
	id = 'A';
	i = 0;
	while ((size = read(fd, buf, 21)) >= 20)
	{
		if (!valid_block(buf, size))
			return (0);
		t[i++] = store_piece(buf, id++);
	}
	return (id - 'A');
}
