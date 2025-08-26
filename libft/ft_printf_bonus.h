/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:13:36 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/11 11:02:17 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <unistd.h>

# define ASCII_SIZE 127
# define ADDR_LEN 18
# define HEX_LEN 18

typedef struct s_flags
{
	int		plus;
	int		minus;
	int		precision;
	long	width;
	int		zero;
	int		dot;
	int		space;
	int		hashtag;
	int		dot_zero;
	char	spec;
}			t_flags;

typedef struct s_node
{
	char			*str;
	char			flag;
	struct s_node	*next;
	struct s_node	*bonus;
}					t_node;

typedef struct s_sentinel
{
	size_t			size;
	struct s_node	*nodes;
}					t_sentinel;

typedef void				(*t_func)(va_list, t_sentinel*, char*);
typedef unsigned long long	t_ull;

int			ft_printf(const char *str, ...);

void		aux_char(va_list args, t_sentinel *sentinel, char *spec);
void		aux_str(va_list args, t_sentinel *sentinel, char *spec);
void		aux_point(va_list args, t_sentinel *sentinel, char *spec);
void		aux_dec(va_list args, t_sentinel *sentinel, char *spec);
void		aux_int(va_list args, t_sentinel *sentinel, char *spec);
void		aux_unsingned_dec(va_list args, t_sentinel *sentinel, char *spec);
void		aux_hex(va_list args, t_sentinel *sentinel, char *spec);
void		aux_hex_cap(va_list args, t_sentinel *sentinel, char *spec);
void		aux_percent(va_list args, t_sentinel *sentinel, char *spec);
void		aux_nothing(va_list args, t_sentinel *sentinel, char *spec);
void		reverse_str(char *str);
char		*ft_uitoa(unsigned int n);
void		cpy_func(char *dst, const char *src, size_t index, char flag);
void		make_hex_str(char *str, char *hex, t_ull nbr);

void		new_node(char *str, t_sentinel *sentinel, char flag);
t_sentinel	*init_sentinel(void);
void		fill_sentinel(const char *str, t_func *func, va_list a,
				t_sentinel *s);
void		clean_nodes(t_sentinel *lst);

int			b_atoi(t_flags *flags, const char *str);
void		b_aux_bonus(va_list args, t_sentinel *sentinel, char *str);
int			b_aux_nextchr(const char *str);
int			b_aux_isspec(char c);
void		b_aux_init_flags(t_flags *flags);
void		b_aux_make_str(va_list args, t_sentinel *sentinel, t_flags flags);
void		b_hex_node(t_sentinel *sentinel, t_flags flags, va_list args);
void		b_iud_integer(t_sentinel *sentinel, t_flags flags, va_list args);
void		b_iud_uinteger(t_sentinel *sentinel, t_flags flags, va_list args);
char		*b_iud_make_zero_str(char *str, int precision);
char		*b_iud_free_and_join(char *start, char *end);
void		b_iud_make_width_str(t_flags flags, char *str,
				t_sentinel *sentinel);
void		b_node_free(t_node *node);
void		b_node_add_bonus(t_sentinel *sentinel, char *str, char op);
t_node		*b_node_last(t_sentinel *sentinel);
void		make_gen_node(int c, char *str, t_sentinel *sentinel, char op);
void		b2_aux_char(t_sentinel *sentinel, t_flags flags, va_list args);
void		b2_aux_str(t_sentinel *sentinel, t_flags flags, va_list args);
void		b2_aux_width(char **width, char c, ssize_t size);
void		b2_aux_lst(char *str, char *flag_str, t_sentinel *sen, long i);
void		b_pointer(t_sentinel *sentinel, t_flags flags, va_list args);
char		*address_prefix(char spec, char *str);
void		b_point_minusstr(char *str, char *width);
ssize_t		ssize_t_atoi(const char *nptr);
void		b_pointer_nothing(t_flags flags, t_sentinel *sentinel);

#endif
