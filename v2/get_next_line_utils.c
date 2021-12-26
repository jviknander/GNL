/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:27:45 by jde-melo          #+#    #+#             */
/*   Updated: 2021/12/26 15:57:32 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		size;
	int		i;

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
		while (i < size && s[start] != '\0')
			sub[i++] = s[start++];
		sub[i] = '\0';
	}
	return (sub);
}

char	*ft_strdup(char *str)
{
	char	*m;
	int		size;
	int		i;

	size = ft_strlen(str);
	m = malloc(sizeof(char) * size + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (str[i])
	{
		m[i] = str[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_strchr(char *str, int c)
{
	char	*temp;

	temp = (char *)str;
	while (*temp != (char)c)
	{
		if (*temp == 0)
			return (NULL);
		temp++;
	}
	return ((char *)temp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
