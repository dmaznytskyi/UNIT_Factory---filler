/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:45:49 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/07 17:20:01 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
#include <stdio.h>////////////////////////
#include <fcntl.h>////////////////////////

typedef struct	s_flr
{
	int		p_num;		//player num
	char	p_char;		//player char
	char	e_char;		//enemy char
	int		m_h;		//map height
	int		m_w;		//map width
	char	**map;		//map
	int		i_h;		//initial height coord
	int		i_w;		//initial width coord
	int		p_h;		//piece height
	int		p_w;		//piece width
	char	**piece;	//piece
	int		**kmap;		//map of koeff's
}				t_flr;

void			init_struct(t_flr *s);
void			read_map(t_flr *s);
void			game(t_flr *s);
void			read_piece(t_flr *s);
void			place_piece(t_flr *s);

#endif
