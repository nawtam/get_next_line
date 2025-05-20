/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:39:33 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/20 14:39:12 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (s1 && s1[i])
		i++;
	new = malloc(i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	free(s1);
	return (new);
}
