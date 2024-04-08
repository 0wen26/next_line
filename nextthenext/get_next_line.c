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


char	*ridbuff(int fd, char *read_buffer)
{
	
}

char	*get_next_line(int fd)
{
	static char	*read_buffer;
	char		*read_content;
	int			read_bytes;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_content)
		return (NULL);
	while (!(ft_strchr(read_buffer, '\n') && read_bytes != 0))
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			return (NULL);
		}
		read_content[read_bytes] = '\0';
		read_buffer = ft_strjoin(read_buffer, read_content);
	}
	
	return(read_content);

}

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
}
