/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:02:25 by ldevy             #+#    #+#             */
/*   Updated: 2022/01/20 16:38:04 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(*new) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*build_line(int fd, char *buff)
{
	int		count;
	char	*line;

	line = malloc(sizeof(*line) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	count = 1;
	while (!buff_check(line) && count > 0)
	{
		count = read(fd, line, BUFFER_SIZE);
		if (count < 0)
			break ;
		line[count] = '\0';
		buff = ft_join(buff, line);
	}
	free(line);
	return (buff);
}

char	*format_line(char *line)
{
	size_t	i;
	char	*new;

	i = 0;
	if (line[i] == 0)
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0')
		new = malloc(sizeof(*new) * i + 1);
	else
		new = malloc(sizeof(*new) * i + 2);
	i = 0;
	if (!new)
		return (ft_free(new));
	while (line[i] != '\n' && line[i])
	{
		new[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buff[fd])
	{
		buff[fd] = malloc(sizeof(*buff));
		if (!buff[fd])
			return (NULL);
		buff[fd][0] = '\0';
	}
	buff[fd] = build_line(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = format_line(buff[fd]);
	buff[fd] = ft_trim(buff[fd]);
	return (line);
}
