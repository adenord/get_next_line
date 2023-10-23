/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:35:02 by adenord           #+#    #+#             */
/*   Updated: 2023/10/23 12:19:25 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	int				len;
	unsigned char	chr;

	chr = (unsigned char)c;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		src_len;
	char	*dest;
	int		i;

	i = 0;
	src_len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * src_len + 1);
	if (!dest)
		return (0);
	ft_memset(dest, 0, src_len + 1);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	size_t			str_len;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
	if (len > (str_len + 1))
		len = str_len + 1;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, len + 1);
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	while (i < len)
		ret[++i] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, len);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	y;

	i = ft_strlen(s1);
	y = 0;
	while (s2[y])
	{
		s1[i + y] = s2[y];
		y++;
	}
	s1[i + y] = '\0';
	return (s1);
}
