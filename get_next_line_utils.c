/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:33 by ldevy             #+#    #+#             */
/*   Updated: 2022/01/20 16:27:08 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	buff_check(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_trim(char *buff)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	new = malloc(sizeof(*new) * (ft_strlen(buff) - i) + 1);
	if (!new)
		return (NULL);
	if (buff[i] == '\n')
		i++;
	j = 0;
	while (buff[i])
		new[j++] = buff[i++];
	new[j] = '\0';
	free(buff);
	return (new);
}

char	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}
