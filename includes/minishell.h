#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <signal.h>
#include <stdbool.h>

typedef struct	s_mini {
	char	**argv;
	char	*str;
	int		pid;
	bool	exit;
	t_list	*env;
} t_mini;

//error management
void	error_output(t_mini *mini, char type);
//error management

//free utility
void	free_lst(t_list *lst);
void	free_struct(t_mini *mini, char *input);
void	free_argv(t_mini *mini);
//free utility

//utility functions
int find_char(char *s1, char c);
void	node_free_machine(t_mini *mini);
void	ft_lstnode_print(t_list *lst, char *name);
char	*get_name(char *str, char c);
t_list	*ft_lstnew_pp(char **content);
t_list	*get_env(char **env, t_mini *mini);
void	env_add_names(t_list *lst);
bool	check_env_names(t_mini *mini, char *name, char *content);
bool	lst_str_check(t_list *lst, char *str);
bool	str_len_check(char *s1, char *s2);
bool	str_cmp_both_len(char *s1, char *s2);
//utility functions

//commands.c
void	ft_pwd(void);
void	ft_exit(t_mini *mini, char *input);
void	ft_echo(char **argv);
void	echo_n_flag(char **argv, int i, int j);
void	echo_no_flag(char **argv, int i, int j);
void	ft_cd(t_mini *mini);
void	ft_ls(t_mini *mini);
void	ft_env(t_mini *mini);
void	ft_export(t_mini *mini);
void	ft_unset(t_mini *mini);
//commands.c

//main.c
char    *pwd(void);
//main.c

#endif
