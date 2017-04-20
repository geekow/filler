/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:11:59 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/20 21:03:09 by jjacobi          ###   ########.fr       */
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

int		main(void)
{
	t_map	map;
	char	player;
	t_coord	*start;
	t_coord result;

	if ((player = get_player_info()) < 0)
		return (-1);
	result.x = 0;
	result.y = 0;
	start = (t_coord*)malloc(sizeof(t_coord*) * 1);
	while (get_map(&map) > -1 && get_piece(&map) > -1)
	{
		map.max_dist = ft_sqrt(ft_power(map.mwidth, 2) +
			ft_power(map.mheight, 2));
		start->x = -1;
		start->y = 0;
		if (place_piece(&map, player, start, &result) == -2147483648)
			ft_printf("0 0\n");
		else
			ft_printf("%d %d\n", result.y, result.x);
	}
	return (0);
}
