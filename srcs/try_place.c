/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:58:18 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/17 10:12:52 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_map.h"
#include "libft.h"

int try_on_pos(t_map *map, t_coord *coord, char player, t_coord *overlap)
{
    int     i;
    char    c;

    c = 0;
    i = 0;
    while (map->pcoords[i].x != -1)
    {
        if (coord->y + map->pcoords[i].y >= map->mheight ||
            coord->x + map->pcoords[i].x >= map->mwidth)
            return (-1);
        else if (player == map->map[coord->y + map->pcoords[i].y]
            [coord->x + map->pcoords[i].x] || player - 32 ==
            map->map[coord->y + map->pcoords[i].y][coord->x +
            map->pcoords[i].x])
        {
            overlap->y = coord->y + map->pcoords[i].y;
            overlap->x = coord->x + map->pcoords[i].x;
            c++;
        }
        else if (map->map[coord->y + map->pcoords[i].y]
            [coord->x + map->pcoords[i].x] != '.')
            return (-1);
        i++;
    }
    return (c == 1 ? 0 : -1);
}

t_coord *find_next_possible_pos(t_coord *startcoord, t_map *map, char player,
            t_coord *overlap)
{
    t_coord coord;
    t_coord tmp;

    coord = *startcoord;
    while (coord.y < map->mheight)
    {
        while (coord.x < map->mwidth)
        {
            tmp.x = coord.x - map->pcoords[0].x;
            tmp.y = coord.y - map->pcoords[0].y;
            if (try_on_pos(map, &tmp, player, overlap) == 0)
            {
                *startcoord = tmp;
                return (startcoord);
            }
            coord.x += 1;
        }
        coord.x = 0;
        coord.y += 1;
    }
    return (startcoord);
}

// int main()
// {
//     t_map   map;
//     t_coord *piece;
//     t_coord coord;
//     t_coord *result;
//     t_coord overlap;
//
//     map.mheight = 5;
//     map.mwidth = 5;
//     map.map = malloc(sizeof(char *) * (map.mheight + 1));
//     piece = malloc(sizeof(t_coord*) * 5);
//     map.map[5] = NULL;
//         map.map[0] = ft_strdup("X.xx.");
//         map.map[1] = ft_strdup(".....");
//         map.map[2] = ft_strdup(".....");
//         map.map[3] = ft_strdup(".....");
//         map.map[4] = ft_strdup("...x.");
//
//     piece[0].x = 4;
//     piece[0].y = 0;
//     piece[1].x = 5;
//     piece[1].y = 0;
//     piece[2].x = 6;     //  ....***
//     piece[2].y = 0;     //  .....*.
//     piece[3].x = 5;
//     piece[3].y = 1;
//     piece[4].x = -1;
//     piece[4].y = -1;
//
//     coord.x = 0;
//     coord.y = 0;
//
//     map.pcoords = piece;
//     result = find_next_possible_pos(&coord, &map, 'x', &overlap);
//     if (result == NULL)
//     {
//       ft_printf("NO solution");
//       return (0);
//     }
//     ft_printf("Result pos x : %d\n", result->x);
//     ft_printf("Result pos y : %d\n", result->y);
//
//     //ft_printf("Function result: %d\n", try_on_pos(&map, piece, &coord, 'x'));
//
//     return (0);
// }
