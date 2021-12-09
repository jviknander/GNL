/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:19:11 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/09 21:51:51 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *storage, char	*line)
{
	int		i;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
	{
		line = ft_substr(storage, 0, i);
		free(storage);
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		buf[BUFFER_SIZE + 1];
	int			r;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	r = 1;
	if (storage)
	{
		if (ft_strchr(storage, '\n') != -1)
			return (get_line(storage, line));
		else
		{
			line = ft_strdup(storage);
			free (storage);
			storage = NULL;
			return (NULL);
		}
	}
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		if (storage == NULL)
			storage = ft_strdup("");
		line = ft_strjoin(storage, buf);
		free (storage);
		storage = line;
		if (ft_strchr(line, '\n') != -1)
			break ;
	}
	return (get_line(storage, line));
}
