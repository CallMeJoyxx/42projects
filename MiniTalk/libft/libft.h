/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:35:56 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/22 09:05:18 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(const char *str);
int				ft_isalnum(int character);
int				ft_isalpha(int character);
int				ft_isascii(int character);
int				ft_isdigit(int character);
int				ft_isprint(int character);
int				ft_memcmp(const char *s1, const char *s2, unsigned long n);
int				ft_strncmp(const char *s1, const char *s2, unsigned long n);
int				ft_strlen(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);

void			*ft_memcpy(void *dest, const void *src, unsigned long n);
void			ft_bzero(void *s, unsigned long n);
void			*ft_memchr(const void *s, int c, unsigned long n);
void			*ft_memmove(void *dest, const void *src, unsigned long len);
void			*ft_memset(void *b, int c, unsigned long len);
void			*ft_calloc(unsigned long count, unsigned long size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd); //??
void			ft_putendl_fd(char *s, int fd); // pk
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

unsigned int	ft_strlcat(char *dest, char *src, unsigned long size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned long size);

char			*ft_strchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					unsigned long len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start,
					unsigned long len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // ok
char			**ft_split(char const *s, char c);
#endif
