/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:14:38 by jde-melo          #+#    #+#             */
/*   Updated: 2021/11/20 14:39:58 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	line = NULL;
	
	
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0 || storage == NULL)
		return (NULL);
	
	
	r = read(fd, &buf, BUFFER_SIZE);
	if (r == -1)
		return (NULL); //errno is set to indicate error
	
	while (!ft_strchr(storage, '\n') && r > 0)
	{
		line = malloc(sizeof(char *) * (BUFFER_SIZE + 1)); 
	}
	
	
	return (line);	

}
