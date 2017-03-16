/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:11:59 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/16 03:03:08 by jjacobi          ###   ########.fr       */
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

int		main()
{
	t_map	map;
	char	playerChar;

	if ((playerChar = get_player_info()) < 0)
		return (-1);
	while (get_map(&map) > -1 && get_piece(&map) > -1)
	{
        // if (solve(playerChar, map) == -1)
		// 	return (-1);
	}
	return (0);
}
