/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:12:22 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/16 14:25:06 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_MAP_H
# define FILLER_MAP_H

typedef struct	s_piece
{
	int		x;
	int		y;
}				t_piece;

typedef	struct	s_map
{
	int		mheight;
	int		mwidth;
	int		pheight;
	int		pwidth;
	char	**map;
	char	**piece;
	t_piece	*pcoord;
}				t_map;

#endif
