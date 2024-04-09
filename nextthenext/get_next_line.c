/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:02:57 by rherraiz          #+#    #+#             */
/*   Updated: 2024/04/08 18:11:31 by rherraiz         ###   ########.fr       */
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


char	*read_and_append(int fd, char *read_content, char *read_buffer)
{
	int	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_content, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		read_content[bytes_read] = '\0';
		if (!read_buffer)
			read_buffer = ft_strdup("");
		temp = read_buffer;
		read_buffer = ft_strjoin(temp, read_content);
		free(temp);
		if (ft_strchr(read_content, '\n'))
			bytes_read = 0;
	}
	return (read_buffer);
}

char	*get_next_line(int fd)
{
	static char	*read_buffer;
	char		*read_content;
	int		*read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_content)
		return (NULL);
	read_buffer = read_and_append(fd, read_content, read_buffer);
	free(read_content);
	if (!read_buffer)
		return (NULL);
	return (0);

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
