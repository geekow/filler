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
#include "filler_map.h"
#include "filler.h"

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

	if ((map.player = get_player_info()) < 0)
		return (-1);
	while (get_map(&map) > -1 && get_piece(&map) > -1)
	{
		// if (solve(playerChar, map) == -1)
		// 	return (-1);
	}
	return (0);
}
