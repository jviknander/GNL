/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:33:59 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/27 14:46:44 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*one_by_one(char **storage)
{
	int		n;
	char	*str;
	char	*ret;

	if (!*storage)
		return (0);
	n = ft_strchr(*storage, '\n');
	if (n >= 0)
	{
		ret = ft_substr(*storage, 0, n + 1);
		str = ft_substr(*storage, n + 1, ft_strlen(*storage) - n);
		free (*storage);
		*storage = str;
		if (**storage != '\0')
			return (ret);
	}
	else
		ret = ft_strdup(*storage);
	free(*storage);
	*storage = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	r = read (fd, buf, BUFFER_SIZE);
	if (r == -1)
		return (NULL);
	while (r != -1 && r != 0)
	{
		buf[r] = '\0';
		if (storage[fd] == NULL)
			storage[fd] = ft_strdup("");
		line = ft_strjoin(storage[fd], buf);
		free (storage[fd]);
		storage[fd] = line;
		if (ft_strchr(storage[fd], '\n') != -1)
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (one_by_one(&storage[fd]));
}
