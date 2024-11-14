/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:27:54 by risattou          #+#    #+#             */
/*   Updated: 2024/11/14 22:24:56 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
#include "get_next_line.h"

char	*ft_help(char **all)
{
	char	*buff;
	char	*line;
	size_t	i;

	i = ft_strchr(*all, '\n');
	line = ft_substr(*all, 0, i + 1);
	if (!line)
	{
		free(all);
		*all = NULL;
		return (NULL);
	}
	buff = ft_substr(*all, i + 1, (ft_strlen(*all) - i));
	if (!buff)
	{
		free(line);
		free(*all);
		*all = NULL;
		return (NULL);
	}
	free(*all);
	*all = buff;
	return (line);
}

size_t	ft_home(char **all, char *buff)
{
	char	*line;

	if (*all == NULL)
	{
		*all = ft_strdup(buff);
		if (!*all)
		{
			free(buff);
			return (0);
		}
	}
	else
	{
		line = ft_strjoin(*all, buff);
		if (!line)
		{
			free(buff);
			return (0);
		}
		free(*all);
		*all = line;
	}
	return (1);
}

char	*ft_zero(char **all, char **buff)
{
	char	*line;

	free(*buff);
	if (!*all || !all)
		return (NULL);
	if (ft_strchr(*all, '\n') >= 0)
		return (ft_help(all));
	if (*all[0] != '\0')
	{
		line = *all;
		*all = NULL;
		return (line);
	}
	free(*all);
	*all = NULL;
	return (NULL);
}

char	*read_line(int fd, char **all, char *buff)
{
	size_t	nb;

	nb = read(fd, buff, BUFFER_SIZE);
	if (nb == 0)
		return (ft_zero(all, &buff));
	while (nb > 0)
	{
		buff[nb] = '\0';
		if (ft_home(all, buff) == 0)
			return (NULL);
		if (ft_strchr(*all, '\n') >= 0)
			break ;
		nb = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (ft_strchr(*all, '\n') < 0)
	{
		buff = *all;
		*all = NULL;
		return (buff);
	}
	return (ft_help(all));
}

char	*get_next_line(int fd)
{
	static char	*all;
	char		*buff;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		free(all);
		all = NULL;
		return (NULL);
	}
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	return (read_line(fd, &all, buff));
}
// char	*get_next_line(int fd)
// {
// 	static char	*all;
// 	char		*buff;
// 	size_t		nb;
// 	char		*line;

// 	if (fd < 0 || read(fd, 0, 0) < 0)
// 	{
// 		free(all);
// 		all = NULL;
// 		return (NULL);
// 	}
// 	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buff)
// 		return (NULL);
// 	nb = read(fd, buff, BUFFER_SIZE);
// 	if (nb == 0)
// 		return (ft_zero(&all, &buff));
//     while (nb > 0)
//     {
//         buff[nb] = '\0';
//         if (ft_home(&all, buff) == 0)
//             return (NULL);
//         if (ft_strchr(all, '\n') >= 0)
//             break ;
//         nb = read(fd, buff, BUFFER_SIZE);
//     }
// 	free(buff);
// 	if (ft_strchr(all, '\n') < 0)
// 	{
// 		line = all;
// 		all = NULL;
// 		return (line);
// 	}
// 	return (ft_help(&all));
// }
// .
// char *ft_zero(char **all, char **buff)
// {
//     char *line;

//     free(*buff);
//     if (!all || !*all)
//         return (NULL);
//     if (ft_strchr(*all, '\n') >= 0)
//         return (ft_help(all));
//     if (*all[0])
//     {
//         line = *all;
//         *all = NULL;
//         return (line);
//     }
//     free(*all);
//     *all = NULL;
//     return (NULL);
// }

// char    *get_next_line(int fd)
// {
//     static char    *all;
//     char        *buff;
//     size_t        nb;

//     if (fd < 0 || read(fd, 0, 0) < 0)
//     {
//         free(all);
//         all = NULL;
//         return (NULL);
//     }
//     if (!(buff = malloc((BUFFER_SIZE + 1) * sizeof(char))))
//         return (NULL);
//     if ((nb = read(fd, buff, BUFFER_SIZE)) == 0)
//         return (ft_zero(&all, &buff));
//     while (nb > 0)
//     {
//         buff[nb] = '\0';
//         if (!ft_home(&all, buff))
//             return (NULL);
//         if (ft_strchr(all, '\n') >= 0)
//             break ;
//         nb = read(fd, buff, BUFFER_SIZE);
//     }
//     free(buff);
//     if (ft_strchr(all, '\n') < 0)
//     {
//         buff = all;
//         all = NULL;
//         return (buff);
//     }
//     return (ft_help(&all));
// }
// if(all == NULL)
// {
// 	all = ft_strdup(buff);
// 	if(all == NULL)
// 	{
// 		free(buff);
// 		return (NULL);
// 	}
// }
// else
// {
// 	line= ft_strjoin(all,buff);
// 	if(line == NULL)
// 		{
// 			free(buff);
// 			free(all);
// 			all = NULL;
// 			return (NULL);
// 		}
// 		free(all);
// 		all = line;
// }