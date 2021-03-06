/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:23:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/10 14:53:16 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "fillit.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_fillit fillit;
	char	**map;

	fillit.lst = 0;
	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > 0)
	{
		get_pieces(fd, &fillit.lst);
		fillit.len = ft_lstcount(fillit.lst);
		map_crt(&fillit);
		printf("La taille de la liste vaut %d", fillit.len);
	}
}
