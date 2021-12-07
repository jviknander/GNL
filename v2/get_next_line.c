/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:19:11 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/07 17:38:47 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char	*get_n_save_line(char	*storage)
{
	int		i;
	char	*str;

	i = 0;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	while (storage[i] && storage[i] != '\n')
		i++;
	str = ft_strdup(storage);
	while (storage[i] && storage[i] != '\n')
	{
		str[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		str[i] = storage[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
*/

char	*lk(char *storage)
{
	int		i;
	char	*str;
	char	*line;
	
	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
	{
		str = ft_substr(storage, 0, i + 1);
		line = ft_strdup(&storage[i + 1]);
		free(storage);
		storage = line;
		if (*storage != '\0')
			return (str);
		i++;
	}
	else
		str = ft_strdup(storage);
	free (storage);
	storage = NULL;
	return (str);
}

char	*reading_is_good(int fd, char *storage)
{
	char	buf[BUFFER_SIZE + 1];
	int		r;
	char	*temp;

	r = read(fd, buf, BUFFER_SIZE);
	while (r != -1 && r != 0)
	{
		buf[r] = '\0';
		if (storage == NULL)
			storage = ft_strdup("");
		temp = ft_strjoin(storage, buf);
		free (storage);
		storage = temp;
		if (ft_strchr(storage, '\n') != -1)
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*storage;

	if (fd > 1024 || fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	storage = reading_is_good(fd, storage);
	return (lk(storage));
}
