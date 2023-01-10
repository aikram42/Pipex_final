/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:40:38 by aikram            #+#    #+#             */
/*   Updated: 2023/01/10 08:48:31 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pathz(t_var *var)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", var->e[i], 4) && var->e[i])
		i++;
	var->pths = ft_split(&var->e[i][5], ':');
}

void	pipex(t_var *var)
{
	if (pipe(var->fd) == -1)
		errs(3);
	pathz(var);
	var->pid1 = fork();
	if (var->pid1 == -1)
		errs(2);
	if (!var->pid1)
		first_born(var);
	var->pid2 = fork();
	if (var->pid2 == -1)
		errs(2);
	if (!var->pid2)
		second_born(var);
	close(var->fd[0]);
	close(var->fd[1]);
	waitpid(var->pid1, NULL, 0);
	waitpid(var->pid2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_var	var;

	var.v = argv;
	var.e = envp;
	if (argc != 5)
		errs(0);
	var.in = open(argv[1], O_RDONLY);
	if (var.in == -1)
		errs(1);
	var.out = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (var.out == -1)
		errs(1);
	pipex(&var);
}
