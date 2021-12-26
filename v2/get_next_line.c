/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:19:11 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/26 21:15:32 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
void	free_this(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}
*/
char	*come_together(int nl_position, char **storage)
{
	char	*ret;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0 )
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
	tmp = ft_substr(*storage, nl_position, BUFFER_SIZE);
	ret = *storage;
	ret[nl_position] = 0;
	*storage = tmp;
	return (ret);
}

char	*read_this(int fd, char **storage, char *buf)
{
	int		r;;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*storage, '\n');
	tmp = NULL;
	r  = 1;
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
	static char	*storage;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	line = read_this(fd, &storage, buffer);
	free(buffer);
	buffer = 0;
	return (line);
}
