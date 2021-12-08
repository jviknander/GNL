/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:19:11 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/08 16:23:58 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *storage)
{
	int		i;
	char	*ret;

	i = 0;
	while (storage[i] && storage[i] != '\n' &&  storage[i] != '\0')
		i++;
	ret = ft_substr(storage, 0, ft_strlen(storage) - i);
	free(storage);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			r;
	
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	r = 1;
	line = NULL;
	if (storage && ft_strchr(storage, '\n'))
		return (get_line(storage));
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		storage = ft_strjoin(storage, buf);
		if (ft_strchr(storage, '\n'))
			break;
	}
	if (storage)
		line = ft_strdup(storage);
	free (storage);
	storage = NULL;
	return (get_line(storage));
}
