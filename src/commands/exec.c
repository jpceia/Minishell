/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:54:06 by falmeida          #+#    #+#             */
/*   Updated: 2021/11/18 02:37:03 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(void)
{
	g_mini.str = NULL;
	char *path = "/bin/";
	char *command = g_mini.argv[0];
	char *total;
	char* argv[3];

	if (!g_mini.argv[0])
		return ;
	argv[0] = g_mini.argv[0];
	argv[1] = g_mini.argv[1];
	argv[2] = NULL;

	if (ft_strcmp(g_mini.argv[0], "ls") == 0)
		argv[1] = getcwd(g_mini.str, PATH_MAX);
	total = ft_strjoin(path, command);
	if (fork() == 0)
	{
		if ((execve(total, argv, NULL) == -1))
			error_output('c');
		kill(getpid(), SIGINT);
	}
	else
		wait(NULL);
	free(total);
}
