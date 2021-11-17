/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:14:38 by jde-melo          #+#    #+#             */
/*   Updated: 2021/11/17 14:23:01 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*read_line;
	char		buf[BUFFER_SIZE + 1];
	static char	*storage;
	int			i; //valor que vai receber do read

	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		ft_strchr()

	}
	if (fd < 0 || fd > 1024)
		return (NULL);
	
	return (read_line);	

}
