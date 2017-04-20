/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:12:22 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/20 21:00:55 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_MAP_H
# define FILLER_MAP_H

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef	struct	s_map
{
	int		mheight;
	int		mwidth;
	int		pheight;
	int		pwidth;
	int		max_dist;
	char	**map;
	char	**piece;
	t_coord	*pcoords;
}				t_map;

#endif
