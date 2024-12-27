/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:52:50 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/27 23:45:55 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"
#include "pipex_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

void	usage(void)
{
	ft_printf("Error: Bad argument");
	ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n");
	ft_printf("    ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n");
	exit(1);
}

void	error(void)
{
	perror("Error");
	exit(126);
}
