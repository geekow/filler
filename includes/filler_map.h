/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:12:22 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/09 21:12:34 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_MAP_H
# define FILLER_MAP_H

typedef	struct	s_map
{
  int   mHeight;
  int   mWidth;
  int   pHeight;
  int   pWidth;
  char  **map;
  char  **piece;
}               t_map;

#endif
