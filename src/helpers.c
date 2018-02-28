/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:34:29 by ikozlov           #+#    #+#             */
/*   Updated: 2018/02/28 11:07:57 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Prints bit representation of piece in stdout using char c
*/

void	print_piece(uint16_t piece, char c)
{
	int			i;
	int			j;
	uint16_t	tmp;

	i = -1;
	while (++i < 4)
	{
		tmp = piece >> (4 * (3 - i));
		j = -1;
		while (++j < 4)
			write(1, (tmp >> (3 - j)) & 1 ? &c : ".", 1);
		write(1, "\n", 1);
	}
}
