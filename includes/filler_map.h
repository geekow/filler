/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:12:22 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/16 03:24:45 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_MAP_H
# define FILLER_MAP_H

typedef struct  s_piece
{
  int x;
  int y;
}               t_piece;

typedef	struct	s_map
{
  int     mHeight;
  int     mWidth;
  int     pHeight;
  int     pWidth;
  char    *map;
  char    **piece;
  t_piece *pCoord;
}               t_map;

#endif
