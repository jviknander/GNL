/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:19:11 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/04 13:31:48 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*god_save_the_line(char *storage)
{
	char	*ret;
	char	*line;
	int		i;

	line = NULL;	
	i = 0;
	while (storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
	{
		line = ft_substr(storage, 0, i);
		ret = ft_substr(storage, i + 1, ft_strlen(storage));	
		free (storage);
		storage = ret;
	}
	else
	{
		ret = ft_strdup(storage);
		free(storage);
		storage = NULL;
	}
	return (line);
}

char	*reading_is_good(int fd, char *storage)
{
	char	buf[BUFFER_SIZE + 1];
	int		r;
	
	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0 && !ft_strchr(storage, '\n'))
	{
		buf[r] = '\0';
		if (storage == NULL)
			storage = ft_strdup("");
		storage = ft_strjoin(storage, buf);
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd > 1024 || fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	storage = reading_is_good(fd, storage);
	line = god_save_the_line(storage);
	return (line);
}
