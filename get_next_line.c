/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:02:57 by rherraiz          #+#    #+#             */
/*   Updated: 2024/04/08 18:04:34 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*next_line()
{


	return "";
}


char	*ridbuff(int fd, char *storage)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (rid != 0 && !(ft_strchr(buffer, '\n')))
	{
		rid = read(fd, buffer, BUFFER_SIZE);
		if (rid == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rid] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	if (rid == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	//if (!storage)
		//storage = ft_strdup("");
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = ridbuff(fd, storage);
	if (!storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	line = ft_substr(storage, 0, i + 1);
	if (!line)
		return (NULL);
	storage = ft_substr(storage, i + 1, (ft_strlen(storage)) - i);
	if (!storage)
		return (NULL);
	return (line);
}
/*
int main(void)
{
	int fd = open("multiple_nl.txt", O_RDONLY);
	char	*str;
	int		i = 0;
	
	while (i < 100)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	return (0);
}*/
