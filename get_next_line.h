/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:26:47 by risattou          #+#    #+#             */
/*   Updated: 2024/11/14 22:26:04 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif


char *get_next_line(int fd);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int	ft_strchr(const char *str, int c);
char	*ft_help(char **all);
size_t	ft_home(char **all, char *buff);
char	*ft_zero(char **all, char **buff);
char	*read_line(int fd, char **all, char *buff);

#endif