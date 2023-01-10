/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:43:57 by aikram            #+#    #+#             */
/*   Updated: 2023/01/10 08:46:02 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_var
{
	char	**v;
	char	**e;

	char	*tmp;
	char	*pth;
	char	**pths;
	char	**cmdarg;

	int		in;
	int		out;

	int		fd[2];
	int		pid1;
	int		pid2;
}	t_var;

void	pipex(t_var *var);
void	pathz(t_var *var);

void	pcmd(t_var *var);
void	first_born(t_var *var);
void	second_born(t_var *var);

int		errs(int i);
void	err1(int e);

size_t	ft_strlen(char *str);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	ft_spit(char *s, char c, char **strr, int *i);

int		ft_strncmp(char *s1, char *s2, size_t n);

#endif