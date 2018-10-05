/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:39:53 by okuzniet          #+#    #+#             */
/*   Updated: 2018/09/25 17:53:58 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFLIB_H
# define FT_PRINTFLIB_H

# include <stdarg.h>

# include <string.h>
# include <inttypes.h>
# include <unistd.h>
# include "../libft/inc/libft.h"

# define BIN	2
# define OCT	8
# define DEC	10
# define HEX	16

# define ABS(X)					(X < 0)? -X : X
# define MAX(A, B)				(A > B)? A : B
# define MALLOC_ERROR(X)		if (!X) exit (0);
# define NULL_ERROR_BREAK(X)	if (!X) break ;

typedef struct		s_flag
{
	t_bool			hash;
	t_bool			zero;
	t_bool			minus;
	t_bool			plus;
	t_bool			space;
	t_bool			up;
}					t_flag;

typedef struct		s_length
{
	t_bool			l;
	t_bool			ll;
	t_bool			h;
	t_bool			hh;
	t_bool			j;
	t_bool			z;
}					t_length;

typedef struct		s_spec
{
	int				sltprint;
	t_flag			flag;
	int				width;
	int				precision;
	t_length		length;
	char			type;

}					t_spec;

typedef struct		s_color
{
	char			*color;
	char			*color_code;
}					t_color;

typedef struct		s_u_num
{
	uintmax_t		num;
	int				num_len;
	int				base;
}					t_u_num;

typedef struct		s_s_num
{
	intmax_t		num;
	int				num_len;
	int				base;
	char			sign;
}					t_s_num;

char				*ft_pr_s(t_spec *spec, va_list ap);
char				*ft_pr_c(t_spec *spec, va_list ap);
char				*ft_pr_us(t_spec *spec, va_list ap);
char				*ft_pr_uc(t_spec *spec, va_list ap);
char				*ft_pr_signed(t_spec *c, va_list ap);
char				*ft_pr_unsigned(t_spec *c, va_list ap);
char				*ft_pr_p(t_spec *spec, va_list ap);
char				*ft_pr_n(t_spec *spec, va_list ap);
char				*ft_pr_percent_sign(t_spec *spec, va_list ap);
char				*ft_pr_no_function(t_spec *ph);
void				ft_colour(char **format, char **p_str, int *size);
int					calculate_the_base(char c);
void				configure_length(t_spec *spec);
void				ft_next_spec(t_spec *spec, char **p_str, va_list ap);
void				ft_del_for_lst(void *content, size_t content_size);
void				ft_pr_lst(int size, t_list **top);
void				ft_str_append(char **dest, char *src);
void				ft_read(char **format, int *size, t_list **top);
void				identify_flag(char **p_str, t_flag *flag);
void				identify_width(char **pp_str, t_spec *spec, va_list ap);
void				identify_prec(char **pp_str, t_spec *spec, va_list ap);
void				get_length(char **pp_str, t_length *length);
int					identify_type(char type, t_spec *spec);
int					set_function(t_spec *p, va_list ap, t_list **top, \
						int *size);
void				ft_unicode_mask_for_str(wchar_t c, char **str);
char				*get_prefix(int base, t_flag flag);
void				make_false(t_spec *spec);
void				configure_length(t_spec *spec);
void				ft_colour(char **format, char **p_str, int *size);
void				ft_next_spec(t_spec *spec, char **p_str, va_list ap);
int					ft_len_uchar(wchar_t c);
int					inc_pointer(char **format);
char				sltp(int *number, int n_to_compare);
void				ft_u_num_to_str(t_u_num *u_num, t_bool up, char **p_str);
void				ft_s_num_to_str(t_s_num *s_num, t_bool up, char **p_str);
t_list				*ft_lst_new_elem(void *ct, size_t ct_size);
int					ft_len_unsigned(uintmax_t number, int base);
void				ft_lst_add_back(t_list **top, t_list *elem);
int					ft_pr_atoi(char **p_str);

#endif
