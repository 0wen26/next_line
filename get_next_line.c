/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:02:57 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/26 12:33:52 by rherraiz         ###   ########.fr       */
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
	//static char	*storage = {0};
	//char	*line;
	
	if (fd < 0)
		return (NULL);

	return (0);
}

int main()
{
	int fd;
	fd =open("file.txt", O_RDWR);
	printf("%s",get_next_line(fd));

	return 0;
}
