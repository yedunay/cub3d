/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:24:51 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:26:47 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

// LIBFT
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**free_malloc(char **tab, size_t i);
int			word_count(char const *s, char c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char const *str, char const *set);

// GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*get_next_line_bonus(int fd);

#endif
