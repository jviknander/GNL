/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:24:44 by jde-melo          #+#    #+#             */
/*   Updated: 2021/11/30 17:16:32 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

char *get_next_line(int fd)
{
	static char *storage;
	char *line;
	char buf[1024];
	int ret;

	ret = read(fd, buf, 42);
	while (ret > 0)
	{
		// Alocar memoria para o storage
		// Se o storage for igual a NULL, aloca se memoria
		if (storage == NULL)
			storage = ft_strdup("");
		buf[ret] = '\0';

		// Meter coisas para o storage
		// Ver se o storage ou buf tem \n
		// Quando o buf tiver o \n, break
		read(fd, buf, 42);
	}
	// Quando e que ele sai do loop?
	// Nao tiver nada para ler (storage tem um '\0')
	// Quando encontra o '\n'
	// tamanho da string
	// O conteudo -> storage (Que vai ter o \n)
}	

*/

#include "get_next_line.h"
#include <stdio.h>

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
	static char	*storage;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	r = read (fd, buf, BUFFER_SIZE);
	//if (r == -1)
	//	return (NULL);
	while (r != -1 && r != 0)
	{
		buf[r] = '\0';
		if (storage == NULL)
			storage = ft_strdup("");
		line = ft_strjoin(storage, buf);
		free (storage);
		storage = line;
		if (ft_strchr(storage, '\n') != -1)
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (one_by_one(&storage));
}
