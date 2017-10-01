/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:45:34 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/01 14:58:57 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>

//void	init_struct(t_flr *s); //read here player info, map size, init position
//void	game(t_flr *s); //main game loop with all func below
//char	**read_map(); //read next map
//char	**read_piece(); //read piece to place
//void	place_piece(); //send coordinates to stdout

int	main(void)
{
	t_flr	s;

	int fd = open("kek", O_RDONLY);
	init_struct(&s);
	game(&s);
	return (0);
}
