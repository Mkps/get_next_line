/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:49:16 by aloubier          #+#    #+#             */
/*   Updated: 2022/12/15 16:27:53 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	if (!str)
		return ;
	i = 0;
	while (i < n)
	{
		*str++ = 0;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ret;
	int		ret_len;

	if (!s1 || !s2)
		return (NULL);
	ret_len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc((ret_len + 1) * sizeof (char));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ret[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		ret[i] = *s2++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ret;
	long long	total;

	total = nmemb * size;
	if (!total)
		return (malloc(0));
	if (size && nmemb != total / size)
		return (NULL);
	ret = malloc(total);
	if (!ret)
		return (NULL);
	ft_bzero(ret, total);
	return (ret);
}
