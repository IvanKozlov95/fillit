/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:47:52 by mtan              #+#    #+#             */
/*   Updated: 2018/02/28 13:47:53 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

// error catch
void ft_catch(char *str) {
	ft_putendl(str);
}

int		main(int ac, char **av)
{
	// t_etris		tetris[MAX_TETRIS + 1];
	// uint16_t	map[16];
	// int			count;
	// int			size;

	av[0] = NULL;
	// args error
	if (ac != 2)
		ft_catch("error");
	// read error
	// if ()
	// 	ft_catch("error");
	// solve
	// if ()
	// 	ft_catch("error");
	return (0);
}
