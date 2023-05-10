/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:38:28 by pineau            #+#    #+#             */
/*   Updated: 2023/05/10 14:27:53 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BUFFER_SIZE 5

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

/*----------MANDATORY---------*/

/*main.c*/
void	child1(char **argv, int *pipe_fd, char **env);
void	child2(char **argv, int *pipe_fd, char **env);

/*utils.c*/
char	**ft_split(char const *s, char c);
void	free_all(char **tab);

/*utils2.c*/
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
void	error(int i, char **cmd);

/*path.c*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_brut_path(char **env);
char	**get_paths(char **env);
char	*make_path(char **env, char **argv, int i);

/*---------BONUS---------*/

/*main_bonus.c*/
void	child(int *pipe_fd, char **argv, char **env, int i);
void	execute(char **argv, char **env, int i);
void	last_exec(char **env, char **argv, int argc);
int		main(int argc, char **argv, char **env);
void	process(int argc, char **argv, char **env);

/*here_doc.c*/
void	here_doc(char **argv, char **env, int argc);
void	process_here_doc(int argc, char **argv, char **env);

/*get_next_line.c*/
int		*get_next_line(int fd, char **buf);
char	*ft_fill_line(char *line, char *keep);
char	*ft_fill_keep(char *keep, char *buf, int fd);
char	*ft_re_fill_keep(char *keep);
void	end_gnl(char *keep, char *line);

/*get_next_line_utils.c*/
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr(const char *str, char c);
int		ft_strlen3(char *str);
int		ft_strlen2(char *str);

/*utils.c*/
void	free_all(char **tab);
char	**ft_split(char const *s, char c);

/*utils2_bonus.c*/
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(char *s1, char *s2);
void	error(int i, char **cmd);
void	end_process(int i, int *pipe_fd);

/*path_bonus.c*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_brut_path(char **env);
char	**get_paths(char **env);
char	*make_path(char **env, char **argv, int i);



void	ft_putstr(char *s);
#endif