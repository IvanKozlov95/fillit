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

// creates empty map
char	*empty_map(int size)
{
	char	*tmp;
	int		x;
	int		y;

	tmp = ft_strnew((size + 1) * size);
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			tmp[y * (size + 1) + x] = '.';
		}
		tmp[y * (size + 1) + x] = '\n';
	}
	return (tmp);
}

void	print(t_piece t, int count, int size)
{
	char	*map;
	int		x;
	int		y;

	map = empty_map(size);
	while (count--)
	{
		y = -1;
		while (++y < t->height)
		{
			x = -1;
			while (++x < t->width)
			{
				x /= 2;
				x = x >> 1;
				if ((t->value >> (16 * (y + 1) - 1 - x)) & 1)
					map[] = t->id;
			}
		}
	}
	ft_putstr(map);
	ft_strdel(&map);
}
// error catch
int		ft_exit(char *str) {
	ft_putendl(str);
	return (1);
}

int		main(int ac, char **av)
{
	t_etris		tetris[MAX_TETRIS + 1];
	uint16_t	map[16];
	int			count;
	int			size;

	av[0] = NULL;
	// args error
	if (ac != 2)
		return (ft_exit("usage: ./fillit [input_file]"));

	// empty map test
	printf("%s", empty_map(5));

	// initialization for structure
	ft_bzero(tetris, sizeof(t_etris) * (MAX_TETRI + 1));

	// read all tetris into structure
	if (!(count = read_tetris(open(av[1], O_RDONLY), tetris))
		return (ft_exit("error"));

	// solve tetris by map
	if (!(size = solve_tetris(tetris, count))
		return (ft_exit("error"));
	print(tetris, count, size);
	return (0);
}
