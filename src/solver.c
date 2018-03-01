/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:57:25 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/01 14:20:15 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks if piece can be placed on the map
*/

static int	check_piece(t_piece piece, uint16_t *map)
{
	return (!((*(uint64_t *)(map + piece.y) & (piece.value >> piece.x))));
}

/*
** Puts piece on the map
*/

static void	place_piece(t_piece piece, uint16_t *map)
{
	*(uint64_t *)(map + piece.y) ^= piece.value >> piece.x;
}

/*
** Recursive solve fucntion
*/

int			solve_map(t_piece *tetris, const int size, uint16_t *map)
{
	if (tetris->id == 0)
		return (1);
	tetris->y = 0;
	while (tetris->y <= size - tetris->height)
	{
		tetris->x = 0;
		while (tetris->x <= size - tetris->width)
		{
			if (check_piece(*tetris, map))
			{
				place_piece(*tetris, map);
				if (solve_map(tetris + 1, size, map))
					return (1);
				place_piece(*tetris, map);
			}
			tetris->x++;
		}
		tetris->y++;
	}
	tetris->x = 0;
	tetris->y = 0;
	return (0);
}

int			solve(t_piece *tetris, const int count)
{
	uint16_t	map[MAX_MAP];
	int			size;

	size = 2;
	printf("asdasdAsd");
	ft_bzero(map, sizeof(uint16_t) * MAX_MAP);
	while (size * size < count * 4)
		size++;
	while (!solve_map(tetris, size, map) && size <= MAX_MAP)
	{
		ft_bzero(map, sizeof(uint16_t) * MAX_MAP);
		size++;
	}
	return (size == MAX_MAP + 1 ? 0 : size);
}
