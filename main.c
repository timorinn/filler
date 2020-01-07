/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:17 by bford             #+#    #+#             */
/*   Updated: 2020/01/07 18:13:03 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_map(struct s_filler *filler)
{
	int		y;
	int		i;
	char	*line;
	char	**array;

	line = NULL;
	y = filler->plateau_y;
	i = 0;
	while (i < y)
	{
		if (get_next_line(0, &line, 0) != 1 || 
		!(array = ft_strsplit(line, ' ')))
			exit (1);
		ft_strdel(&line);
		if (ft_array_size((void **)array) != 2 ||
		!ft_isint(array[0], 1, 1, 1) ||
		ft_atoi(array[0]) != i ||
		(int)ft_strlen(array[1]) != filler->plateau_x)
			exit(1);
		ft_delstr_arr(array);
		i++;
	}
	return (1);
}

int		ft_create_map(struct s_filler *filler)
{
	int		y;
	int		x;
	char	**map;

	map = filler->map;
	x = filler->plateau_x;
	y = filler->plateau_y;
	if (!(map = malloc(sizeof(char *) * (y + 1))))
		exit(0);
	map[y] = NULL;
	while (y--)
	{
		if (!(map[y] = malloc(sizeof(char) * (x + 1))))
			exit(0);
		map[y][x] = '\0';
	}
	return (1);
}

int		ft_check_num_line(struct s_filler *filler)
{
	char	*line;
	int		i;
	
	line = NULL;
	if (get_next_line(0, &line, 0) != 1 ||
	(int)ft_strlen(line) != filler->plateau_x)
		return (ft_strdel(&line));
	i = 0;
	while (line[i])
	{
		if (line[i] - '0' != i % 10)
			return (ft_strdel(&line));
		i++;
	}
	return (ft_strdel(&line) + 1);
}

int		ft_check_plateau(struct s_filler *filler)
{
	char	*line;
	char	**array;
	int		i;

	line = NULL;
	if (get_next_line(0, &line, 0) != 1 || !(array = ft_strsplit(line, ' ')))
		return (ft_strdel(&line));
	i = 0;
	while (array[i])
		i++;
	if (i != 3 || ft_strcmp(array[0], "Plateau") ||
	!ft_isint(array[1], 1, 1, 1) || !ft_isint(array[2], 1, 1, 0))
		return (ft_strdel(&line) + ft_delstr_arr(array));
	i = 0;
	while (array[2][i] && array[2][i] != ':')
		i++;
	if (array[2][i] != ':' || array[2][i + 1] != '\0')
		return (ft_strdel(&line) + ft_delstr_arr(array));
	filler->plateau_y = ft_atoi(array[1]);
	filler->plateau_x = ft_atoi(array[2]);
	ft_strdel(&line);
	ft_delstr_arr(array);
	filler->map == NULL ? printf("Create map!\n") && ft_create_map(filler) : 0;
	printf("Res Fil->x = %d\n", filler->plateau_x);
	printf("Res Fil->y = %d\n", filler->plateau_y);
	return (filler->plateau_y > 0 && filler->plateau_x > 0);
}

int		main(void)
{
	struct s_filler		filler;

	ft_bzero(&filler, sizeof(struct s_filler));
	// printf("%d %d %d %s\n", filler.play_num, filler.plateau_x, filler.plateau_y, filler.map); // check
	
	if (ft_check_exec(&filler) == 0 /* * */&& printf("NE OK\n")/* * */)
		return (0);
	printf("Filler->play_num = %d\n", filler.play_num);
	while (1)
	{
		if (ft_check_plateau(&filler) == 0 /* * */&& printf("NE OK\n")/* * */)
			return (0);
		else if (ft_check_num_line(&filler) == 0 /* * */&& printf("NE OK\n")/* * */)
			return (0);
		else if (ft_check_map(&filler) == 0 /* * */&& printf("NE OK\n")/* * */)
			return (0);
		else
			printf("OK\n");
	}
	return (0);
}
