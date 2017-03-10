
#include "filler_map.h"
#include "libft.h"
#include "ft_printf.h"
#include "stdio.h"

int parse_piece_header(t_map *map)
{
    char    *header;

    get_next_line(0, &header);
    if (ft_strlen(header) < 9)
        return (-1);
    if (ft_memcmp(header, "Piece ", 5 * sizeof(char)))
        return (-1);
    map->pHeight = ft_atoi(header + (5 * sizeof(char)));
    map->pWidth = ft_atoi(header + (6 + ft_strlen(ft_itoa(map->mHeight)))
                                   * sizeof(char));
    if (map->pHeight < 1 || map->pWidth < 1)
        return (-1);
    return (0);
}

int parse_piece_tab(t_map *map)
{
    int     count;
    char    *linePiece;

    count = 0;
    if ((map->piece = malloc(sizeof(char*) * (map->pHeight + 1))) == NULL)
        return (-1);
    map->piece[map->pHeight] = NULL;
    while(count < map->pHeight && get_next_line(0, &linePiece) > 0)
    {
        if ((int)ft_strlen(linePiece) != map->pWidth + 1)
            return (-1);
        printf("FILS DE PUTE");
        if((map->piece[count] = ft_strdup(linePiece)) == NULL)
            return (-1);
        free(linePiece);
        count++;
    }
    if (count != map->pHeight)
        return (-1);
    return (0);
}

int get_piece(t_map *map)
{
    if (parse_piece_header(map) == -1)
        return (-1);
    printf(("test"));
    if (parse_piece_tab(map) == -1)
        return (-1);

    return (0);
}
