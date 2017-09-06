/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:45:49 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/06 15:45:06 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct	s_flr
{
	int		p_num;
	int		m_h;
	int		m_w;
	char	**map;
	int		i_h;
	int		i_w;
	/*--------*/
	int		p_h;
	int		p_w;
}				t_flr;

#endif
