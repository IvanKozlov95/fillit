/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:57:25 by ikozlov           #+#    #+#             */
/*   Updated: 2018/02/28 17:32:31 by ikozlov          ###   ########.fr       */
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

{
	uint16_t	map[MAX_MAP]];
	int			size;

	size = 2;
	ft_bzero(map)
	while (size * size < count * 4)
		size++;
	while (!solve_map(tetris, size, map) && size <= MAX_MAP)
	{
		ft_bzero(map, sizeof(uint16_t) * MAX_MAP);
		size++;
	}
	return (size == MAX_MAP ? 0 : size);
}
