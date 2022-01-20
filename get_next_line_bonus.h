/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:05:04 by ldevy             #+#    #+#             */
/*   Updated: 2022/01/20 16:38:57 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
int		buff_check(char *s);
char	*ft_strdup(char *s);
char	*ft_trim(char *buff);
char	*ft_free(char *ptr);

#endif