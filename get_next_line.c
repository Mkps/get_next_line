/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:48:55 by aloubier          #+#    #+#             */
/*   Updated: 2022/12/07 13:54:19 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

char	*ft_addstr(char *buffer, char *str)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, str);
	free(buffer);
	return (tmp);
}

char	*ft_getleftover(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof (char));
	++i;
	j = 0;
	while (buffer[i + j])
	{
		line[j] = buffer[i + j];
		++j;
	}
	free(buffer);
	return (line);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	line = ft_calloc(i + 2, sizeof (char));
	line[i] = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		++i;
	}
	//Removed eof condition buffer[i]
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		byte_read;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof (char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		str = ft_addstr(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_getleftover(buffer);
	return (line);
}
/*
int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		int	fd;
		int	i;

		i = 10;
		fd = open(argv[1], "r");
		while (--i)
		{
			printf("%i%s", i, get_next_line(fd));
		}
	}
}
*/
