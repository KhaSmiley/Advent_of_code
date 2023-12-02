/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:53:35 by kboulkri          #+#    #+#             */
/*   Updated: 2023/07/04 21:59:08 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	return (l);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (!size)
		return (s_len);
	d_len = ft_strlen(dst);
	i = 0;
	if (d_len < size - 1 && size > 0)
	{
		while (src[i] && d_len + i < size - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = 0;
	}
	if (d_len >= size)
		d_len = size;
	return (d_len + s_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copy;

	i = ft_strlen(s);
	copy = (char *)malloc(i + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, (i + 1));
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s_len;
	char	*str;

	if (!s1 && s2)
		return (ft_strdup(s2));
	s_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * ((s_len + 1)));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, (char *)s2, s_len + 1);
	free(s1);
	return (str);
}
