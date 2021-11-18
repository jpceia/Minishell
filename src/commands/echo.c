/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:35:15 by falmeida          #+#    #+#             */
/*   Updated: 2021/11/18 02:36:53 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Output the args, separated by spaces, followed by a newline.
 * If -n is specified, the trailing newline is suppressed.
 * The return status is 0 unless a write error occurs. 
 */

/*
void	print_env_content(t_env *lst, char *name)
{
	char *content;

	content = NULL;
	if (return_env_content(lst, name))
	{
		content = return_env_content(lst, name);
		printf("%s",content);
	}
	free(name);
}

char	*return_env_content(t_env *lst, char *name)
{
	while (lst)
	{
		if (str_cmp_both_len(lst->name, name))
			break ;
		lst = lst->next;
	}
	return (lst->content);
}

char	*env_flag_check(int i)
{
	char	*env_name;
	int j;

	j = 0;
	env_name = NULL;
	while (g_mini.argv[i][j])
		j++;
	if (j > 0 && g_mini.argv[i][0] == '$')
	{
		env_name = ft_substr(g_mini.argv[i], 1, j);
		return (env_name);
	}
	return (NULL);
}
*/

void	echo_n_flag(void)
{
	int	index;

	index = 1;
	if (g_mini.argv[index] == NULL)
		return ;
	while (g_mini.argv[index + 1])
	{
		ft_putstr(g_mini.argv[index]);
		ft_putchar(' ');
		++index;
	}
	ft_putstr(g_mini.argv[index]);
}

void	ft_echo()
{
	if (g_mini.argv[1] && ft_strcmp(g_mini.argv[1], "-n") == 0)
		echo_n_flag();
	else
	{
		echo_n_flag();
		ft_putchar('\n');
	}
	// return 0
}
