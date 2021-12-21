/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:19:11 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/21 18:40:09 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char **storage)
{
	int		n;
	char	*str;
	char	*ret;

	if (!*storage || **storage == '\0')
		return (0);
	n = ft_strchr(*storage, '\n');
	if (n >= 0)
	{
		ret = ft_substr(*storage, 0, n + 1);
		str = ft_substr(*storage, n + 1, ft_strlen(*storage));
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
	static char	*storage;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	r = 1;
	while (r >  0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		if (storage == NULL)
			storage = ft_strdup("");
		temp = ft_strjoin(storage, buf);
		free (storage);
		storage = temp;
		if (ft_strchr(storage, '\n') != -1)
			break ;
	}
	return (read_line(&storage));
}
