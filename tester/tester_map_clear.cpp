	ft_map	map;

	map.clear();
	ut::fillMap<ft_map, ft_pair>(map, 20, RANDOM);
	ut::displayDataMap<ft_map>(map);
	map.clear();
	ut::displayDataMap<ft_map>(map);

	return (SUCCESS);