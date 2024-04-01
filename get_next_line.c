/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:02:57 by rherraiz          #+#    #+#             */
/*   Updated: 2024/04/01 19:35:40 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char	*line;
	int i;

	i =0;
	line = malloc(sizeof(char) +1);
	if (fd < 0)
		return (NULL);
	
	while (!ft_strchr(line,'\n'))
	{
		read(fd, line, 10);
		storage = ft_strjoin(storage, line);
	}
	while (storage[i] != '\n')
		i++;
	ft_substr(storage,0,i +1);
	return (storage);
}

int main()
{
	int fd;
	fd =open("file.txt", O_RDWR);
	printf("%s",get_next_line(fd));

	return 0;
}
