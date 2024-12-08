/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:44:05 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/08 11:19:31 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int	l;
	int	k;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	k = i;
	while (src[j] != '\0')
		j++;
	l = j;
	j = 0;
	while (i < k + l)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
