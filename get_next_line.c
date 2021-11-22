/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:14:38 by jde-melo          #+#    #+#             */
/*   Updated: 2021/11/22 17:17:12 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			size;
	size_t			i;

	sub = NULL;
	if (s)
	{
		if (ft_strlen(s) <= len)
			size = ft_strlen(s);
		else
			size = len;
		if (start >= ft_strlen(s))
			size = 0;
		sub = malloc(size + 1);
		if (!sub)
			return (NULL);
		i = 0;
		while (i < size)
			sub[i++] = s[start++];
		sub[i] = '\0';
	}
	return (sub);
}

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
	if (fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	storage = malloc(sizeof(char *) * (BUFFER_SIZE + 1)); 
	if (!storage)	
		return (NULL);
	r = read(fd, buf, BUFFER_SIZE);
	if (r == -1)
		return (NULL); 
	buf = ft_strchr(storage, '\n');
	while (!ft_strchr(storage, '\n') && r > 0)
	{
		line = ft_substr();
		buf[r] = '\0';
		printf("%s\n", line);
	}
	
	
	return (line);	

}
