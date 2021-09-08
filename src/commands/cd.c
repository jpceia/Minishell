/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:36:18 by falmeida          #+#    #+#             */
/*   Updated: 2021/09/08 16:10:37 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*find_name(t_list *lst, char *str)
{
	while (lst)
	{
		if (!(ft_strncmp(lst->name, str, ft_strlen(lst->name))))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_cd(t_mini *mini)
{
	t_list *tmp;

	tmp = mini->env;
	if (ft_strlen(mini->argv[1]) == 0)
	{
		tmp = find_name(tmp, "HOME");
		chdir(tmp->content);
	}
	else
		tmp = find_name(tmp, mini->argv[1]);
}
