/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:53:42 by adenord           #+#    #+#             */
/*   Updated: 2023/10/23 16:09:25 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	void	*ret;

	ret = b;
	while (len > 0)
	{
		*(char *)b = c;
		b += 1;
		len--;
	}
	return (ret);
}

static char	*find_line(int fd, char **storage)
{
	size_t	i;
	char	*ret;
	char	*tmp;

	i = 0;
	if (!storage[fd])
		return (NULL);
	while (storage[fd][i] && storage[fd][i] != '\n')
		i++;
	if (storage[fd][i] == '\n')
		i++;
	ret = ft_substr(storage[fd], 0, i);
	tmp = ft_substr(storage[fd], i, ft_strlen(&storage[fd][i]));
	free(storage[fd]);
	storage[fd] = tmp;
	if (ft_strlen(ret) == 0)
	{
		free(storage[fd]);
		free(ret);
		storage[fd] = NULL;
		return (NULL);
	}
	return (ret);
}

static char	*reading_fd(int fd, char **storage, char *tmp)
{
	ssize_t	bytes_read;
	char	*tmp2;

	bytes_read = 1;
	while (bytes_read >= 0)
	{
		ft_memset(tmp, 0, sizeof(tmp));
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		tmp[bytes_read] = 0;
		if (bytes_read < 0)
			return (NULL);
		if (!storage[fd])
			storage[fd] = ft_strdup(tmp);
		else
		{
			tmp2 = ft_strjoin(storage[fd], tmp);
			free(storage[fd]);
			storage[fd] = tmp2;
		}
		if (ft_strchr(storage[fd], '\n') || bytes_read == 0)
			return (storage[fd]);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*ret;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	storage[fd] = reading_fd(fd, storage, tmp);
	free(tmp);
	ret = find_line(fd, storage);
	return (ret);
}
