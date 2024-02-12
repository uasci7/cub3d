/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:37:14 by muyazici          #+#    #+#             */
/*   Updated: 2023/10/31 12:37:15 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_get_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && c != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_get_strjoin(char *mystr, char *buff)
{
	char	*newstr;
	int		i;
	int		j;

	if (!mystr)
	{
		mystr = malloc(1);
		mystr[0] = '\0';
	}
	newstr = malloc(sizeof(char) * ((ft_strlen(mystr) + ft_strlen(buff)) + 1));
	i = 0;
	j = 0;
	while (mystr[i] != '\0')
	{
		newstr[i] = mystr[i];
		i++;
	}
	while (buff[j] != '\0')
		newstr[i++] = buff[j++];
	newstr[ft_strlen(mystr) + ft_strlen(buff)] = '\0';
	free(mystr);
	return (newstr);
}
