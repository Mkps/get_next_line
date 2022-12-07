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

	if (!s)
		return;
	i = 0;
	while (i < n)
	{
		*(char *)(s+i) = 0;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	j;
	char	*ret;
	int	ret_len;

	ret_len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc((ret_len + 1) * sizeof (char));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

static int	ft_checkoverflow_int(int n1, int n2)
{
	long long	result;

	result = n1 * n2;
	if (n1 == result / n2)
		return (0);
	else
		return (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ret;
	long long	total;

	total = nmemb * size;
	if (!total)
		return (NULL);
	if (nmemb != total / size)
		return (NULL);
	ret = malloc(total);
	if (!ret)
		return (NULL);
	ft_bzero(ret, total);
	return (ret);
}
