/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:39:39 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/26 16:43:44 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*tmp = NULL;
	int				bytes;
	char			buf[BUFFER_SIZE + 1];
	int 			i;

	if (tmp)
	{
		line = tmp;
		tmp = NULL;
	}
	while (1)
	{
		i = 0;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		while (i <= (bytes - 1) && bytes > 0)
		{
			line = ft_strjoin(line, buf[i]);
			if (buf[i] == '\n')
			{
				while (i++ <= (bytes - 1))
					tmp = ft_strjoin(tmp, buf[i++]);
				return (line);
			}
			i++;
		}

}

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int	fd = open("text.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
	return (0);
}