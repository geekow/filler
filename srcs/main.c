/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:11:59 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/16 14:31:34 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "filler.h"
#include "ft_printf.h"

char	get_player_info(void)
{
	int		i;
	char	*input;

	i = -1;
	if (1 != get_next_line(0, &input) || (ft_strlen(input) < 15))
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

#include "fcntl.h"

int		main(void)
{
	t_map	map;
	char	player;
	t_coord	*result;
	t_coord	overlap;

	int	fd;
	fd = open("/nfs/2017/j/jjacobi/Projects/filler_ressources/log", O_RDWR|O_CREAT, 0777);

	if ((player = get_player_info()) < 0)
		return (-1);
	result = (t_coord*)malloc(sizeof(t_coord*) * 1);
	result->x = 0;
	result->y = 0;
	ft_putendl_fd("log", fd);
	while (get_map(&map) > -1 && get_piece(&map) > -1)
	{
		result = find_next_possible_pos(result, &map, player, &overlap);
		ft_printf("%d %d\n", result->x, result->y);
	}
	close(fd);
	return (0);
}
