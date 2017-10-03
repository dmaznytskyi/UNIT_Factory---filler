/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fgnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 19:33:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/03 21:03:11 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	fgnl(char **line, size_t size)
{
	char	*b;
	int		status;

	b = ft_strnew(size);
	status = read(0, b, size);
	b[status - 1] = '\0';
	*line = b;
//	printf("%s\n", b);
	return (status);
}
