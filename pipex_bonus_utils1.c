/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:15:00 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/28 11:01:55 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex_bonus.h"

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
