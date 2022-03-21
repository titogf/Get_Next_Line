/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:53:36 by gfernand          #+#    #+#             */
/*   Updated: 2022/03/10 17:22:05 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define MAX_FD_COUNT 1024

char	*get_next_line(int fd);
char	*ft_export_line(char *str, char *s);
char	*ft_leftover(char *str, char *s);
int		ft_strlen(const char *s);
char	*ft_stuff(void);
int		ft_enter(char *str);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char const *s1, char const *s2, int i);
char	*ft_read(char *str, int fd);
void	*ft_free(char *aux, char *s);

#endif
