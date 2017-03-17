/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:58:18 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/16 14:58:20 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_map.h"
#include "libft.h"
#include "ft_printf.h"

int check_valid_char(char player, char tocheck)
{
    if (tocheck == player || tocheck == player - 32)
        return (1);
    else if (tocheck == '.')
        return (1);
    else
        return (0);
}

int try_on_pos(t_map *map, t_coord *piece, t_coord *coord)
{
    int     i;
    char    c;

    c = 0;
    i = 0;
//     if (map->map[coord->y + piece[i].y][coord->x + piece[i].y] != map->player
// && map->map[coord->y + piece[i].y][coord->x + piece[i].y] != map->player - 32)
//         return (-1);
    while (piece[i].x != -1)
    {
        if (coord->y + piece[i].y >= map->mheight ||
            coord->x + piece[i].x >= map->mwidth)
            return (-1);
        if (map->player == map->map[coord->y + piece[i].y][coord->x + piece[i].y]
        || map->player - 32 == map->map[coord->y + piece[i].y][coord->x + piece[i].y])
            c++;
        else if (map->map[coord->y + piece[i].y][coord->x + piece[i].y] != '.')
            return (-1);
        i++;
    }
    if (c == 1)
        return (0);
    else
        return (-1);
}

t_coord *find_next_possible_pos(t_coord *startcoord, t_coord *piece, t_map *map)
{
    t_coord coord;
    t_coord tmp;

    coord = *startcoord;
    while (coord.y < map->mheight)
    {
        while (coord.x < map->mwidth)
        {
            tmp.x = coord.x - piece[0].x;
            tmp.y = coord.y - piece[0].y;
            if (try_on_pos(map, piece, &tmp) == 0)
            {
                *startcoord = tmp;
                return (startcoord);
            }
            coord.x += 1;
        }
        coord.x = 0;
        coord.y += 1;
    }
    return (NULL);
}

// int place_piece()
// {
//     t_coord currentPos;
//
//
//     while(find_next_possible_pos())
// }

int main()
{
    t_map   map;
    t_coord *piece;
    t_coord coord;
    t_coord *result;

    map.mheight = 5;
    map.mwidth = 5;
    map.map = malloc(sizeof(char *) * (map.mheight + 1));
    piece = malloc(sizeof(t_coord*) * 5);
    map.map[5] = NULL;
        map.map[0] = ft_strdup("X....");
        map.map[1] = ft_strdup(".OO..");
        map.map[2] = ft_strdup("..x..");
        map.map[3] = ft_strdup(".....");
        map.map[4] = ft_strdup(".....");

    piece[0].x = 0;
    piece[0].y = 0;
    piece[1].x = 1;
    piece[1].y = 0;
    piece[2].x = 2;     //  ***
    piece[2].y = 0;     //  .*.
    piece[3].x = 1;
    piece[3].y = 1;
    piece[4].x = -1;
    piece[4].y = -1;

    coord.x = 0;
    coord.y = 0;

    map.player = 'x';

    result = find_next_possible_pos(&coord, piece, &map);
    ft_printf("Result pos x : %d\n", result->x);
    ft_printf("Result pos y : %d\n", result->y);
    return (0);
}
