/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:11 by falmeida          #+#    #+#             */
/*   Updated: 2021/11/19 16:11:13 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	screening(char **argv)
{
	char	*cmd;

	cmd = *argv;
	if (!cmd)
		return (1);
	if (!ft_strcmp(cmd, "exit"))
	{
		g_mini.exit = true;
		return (0);
	}
	if (!ft_strcmp(cmd, "pwd"))
		return (ft_pwd(argv));
	if (!ft_strcmp(cmd, "echo"))
		return (ft_echo(argv));
	if (!ft_strcmp(cmd, "cd"))
		return (ft_cd(argv));
	if(!ft_strcmp(cmd, "env"))
		return (ft_env(argv));
	if(!ft_strcmp(cmd, "export"))
		return (ft_export(argv));
	if (!ft_strcmp(cmd, "unset"))
		return (ft_unset(argv));
	return (ft_exec());
}

int main(int argc, char **argv, char **envp)
{
	char	*input;
	bool	input_empty;

	(void) argc;
	(void) argv;
	g_mini.pid = getpid();
	g_mini.env = map_from_str_array(envp, '=');
	g_mini.exit = false;

	printf("Hello World\n");
	//signal(SIGINT , get_signal);
	//signal(SIGQUIT , get_signal);
	while (42)
	{
		input = readline("minishell: ");
		input_empty = ft_strwc(input, ' ') == 0;
		if (input && !input_empty)
		{
			add_history(input);
			g_mini.argv = ft_split(input, ' ');
			g_mini.status = screening(g_mini.argv);
			free_argv();
		}
		if (input)
			free(input);
		if (g_mini.exit)
		{
			ft_putstr("exit\n");
			break ;
		}
	}
	free_struct();
	return (EXIT_SUCCESS);
}
