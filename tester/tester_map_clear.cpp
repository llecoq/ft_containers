	ft_map	map;

	map.clear();
	ft::fillMap<ft_map, ft_pair>(map, 20, RANDOM);
	ft::displayDataMap<ft_map>(map);
	map.clear();
	ft::displayDataMap<ft_map>(map);

	return (SUCCESS);