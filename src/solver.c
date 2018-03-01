int			solve(t_etris *tetris, const int count)
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
