/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:39:39 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/20 14:42:09 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		bytes;
	char	buf;

	line = NULL;
	bytes = read(fd, &buf, 1);
	while (bytes > 0)
	{
		line = ft_strjoin(line, buf);
		if (!line || buf == '\n')
			break ;
		bytes = read(fd, &buf, 1);
	}
	if (bytes <= 0 && !line)
		return (NULL);
	return (line);
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// int main()
// {
// 	int	fd = open("text.txt", O_RDONLY);
// 	char *line;

// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	close(fd);
// 	return (0);
// }