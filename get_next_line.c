/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:14:38 by jde-melo          #+#    #+#             */
/*   Updated: 2021/11/18 19:41:40 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*read_line;
	char		buf[BUFFER_SIZE + 1];
	static char	*storage;
	int			i; //valor que vai receber do read

	read_line = malloc(BUFFER_SIZE);
	i = read(fd, buf, BUFFER_SIZE);
	storage = read_line;
	if (fd < 0 || fd > 1024)
		return (NULL);
/*	while (i > 0)
	{
		storage = mall  
			ft_strchr(read_line, '\n');
		
	}*/
	return (read_line);	

}
