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
	static char	*storage;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int		r;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0 || storage == NULL)
		return (NULL);
	buf = ft_strchr(storage, '\n');
	
	if (!buf ou storage)
		buf = malloc(BUFFER_SIZE + 1); 
		// se buf nao existir, terá que alocar memoria e 
	
	r = read(fd, &buf, BUFFER_SIZE);
	if (r == -1)
		return (NULL);
	
	while ()

	return (line);	

}
