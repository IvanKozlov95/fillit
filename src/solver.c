int			solve(t_etris *tetris, const int count)
{
	uint16_t	map[16];
	int			size;

	size = 2;
	ft_bzero(map)
	while (size * size < count * 4)
		size++;
	while (!solve_map(tetris, size, map) && size <= 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	return (size == 17 ? 0 : size);
}
