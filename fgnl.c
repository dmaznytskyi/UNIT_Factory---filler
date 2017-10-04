/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fgnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 19:33:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/04 14:59:51 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	fgnl(char **line, int st)
{
	char	*b;
	char	*r;
	char	*tmp;

	r = ft_strnew(0);
	while (!ft_strchr(r, '\n') && st != 0)
	{
		b = ft_strnew(1);
		st = read(0, b, 1);
		tmp = r;
		r = ft_strjoin(r, b);
		ft_strdel(&tmp);
		ft_strdel(&b);
	}
	*line = r;
	return (st);
}
