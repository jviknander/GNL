/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:47:56 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/27 14:22:22 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*come_together(int n, char **storage)
{
	char	*ret;
	char	*tmp;

	tmp = NULL;
	if (n <= 0)
	{
		if (**storage == '\0')
		{
			free(*storage);
			*storage = NULL;
			return (NULL);
		}
		ret = *storage;
		*storage = NULL;
		return (ret);
	}
	tmp = ft_substr(*storage, n, BUFFER_SIZE);
	ret = *storage;
	ret[n] = 0;
	*storage = tmp;
	return (ret);
}

char	*read_this(int fd, char **storage, char *buf)
{
	int		r;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*storage, '\n');
	tmp = NULL;
	r = 1;
	while (!nl && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
			return (come_together(r, storage));
		buf[r] = 0;
		tmp = ft_strjoin(*storage, buf);
		free(*storage);
		*storage = 0;
		*storage = tmp;
		nl = ft_strchr(*storage, '\n');
	}
	return (come_together(nl - *storage + 1, storage));
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_strdup("");
	line = read_this(fd, &storage[fd], buffer);
	free(buffer);
	buffer = 0;
	return (line);
}
