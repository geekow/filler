/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:11:59 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/09 21:12:00 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "filler_map.h"
#include "filler.h"

#include <fcntl.h>

int		logstr(char *str) {
	static int	fd = 0;

	if (fd == 0)
		fd = open("/nfs/2017/j/jjacobi/Projects/filler/log.txt", O_RDWR|O_CREAT, 0644) ;
	ft_putendl_fd(str, fd);
	return (0);
}

void printMapInfos(t_map *map)
{
	int	i;

	i = 0;
	logstr("Height : ");
	logstr(ft_itoa(map->mHeight));
	logstr("Width : ");
	logstr(ft_itoa(map->mWidth));
	logstr("---MAP---");
	while (map->map[i])
		logstr(map->map[i]);
}

char	get_player_info()
{
	int		i;
	char	*input;

	i = -1;
	if (!get_next_line(0, &input) || (ft_strlen(input) < 15))
		return (-1);
	if (ft_memcmp("$$$ exec p", input, 10 * sizeof(char)) != 0)
		return (-1);
	i = ft_atoi(input + 10);
	if (i == 1)
		return ('o');
	else if (i == 2)
		return ('x');
	return (-1);
}

int		main(int ac, char **av)
{
	t_map	map;
	char	playerChar;

	if ((playerChar = get_player_info()) < 0)
		return (-1);
	logstr("DUMBIE");
	while (get_map(&map) > -1) {
		logstr("DUMBIE");
		// if (solve(playerChar, map) == -1)
		// 	return (-1);
		printMapInfos(&map);
	}
	return (0);
}
