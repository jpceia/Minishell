/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:36:04 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/13 12:11:55 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	infile_heredoc_setup(t_infile *infile, char *eof)
{
	char	*holder;
	char	*line;

	infile->data = ft_strdup("");
	while (42)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (!ft_strcmp(line, eof))
		{
			free(line);
			break ;
		}
		holder = infile->data;
		line = ft_expander_heredoc(line);
		infile->data = ft_strjoin(holder, line);
		infile->data = ft_straddc(infile->data, '\n');
		free(holder);
		free(line);
	}
	infile->heredoc = true;
}

t_infile	*infile_new(char *value, bool heredoc)
{
	t_infile	*infile;

	infile = malloc(sizeof(*infile));
	if (!infile)
		return (NULL);
	if (heredoc)
		infile_heredoc_setup(infile, value);
	else
	{
		infile->data = ft_strdup(value);
		infile->heredoc = false;
	}
	return (infile);
}

void	infile_free(void *ptr)
{
	t_infile	*infile;

	infile = (t_infile *)ptr;
	free(infile->data);
	free(infile);
}

void	infile_print(t_infile *infile)
{
	if (infile->heredoc)
		ft_putstr("heredoc:\n");
	else
		ft_putstr("infile: ");
	ft_putstr(infile->data);
	ft_putchar('\n');
}
