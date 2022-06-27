/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:18:07 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/22 15:17:01 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_psort
{
	int	*a;
	int	*b;
	int	*s;
	int	sizea;
	int	sizeb;
	int	sizes;
	int	chunk;
	int	chunksize;
}				t_psort;

int		error_check(int nb, char **list);
char	**ft_free_list(char **list, int size);
int		ft_check_dupes(int *a, int nb);
char	**ft_parse_group(char **argv, int *size);
char	**ft_parse_sep(char **argv, int argc, int *size);
int		ft_error(int *a, int *b, char **list, int size);
void	ft_sa(t_psort *data);
void	ft_sb(t_psort *data);
void	ft_ss(t_psort *data);
void	ft_pa(t_psort *data);
void	ft_pb(t_psort *data);
void	ft_ra(t_psort *data);
void	ft_rb(t_psort *data);
void	ft_rs(t_psort *data);
void	ft_rra(t_psort *data);
void	ft_rrb(t_psort *data);
void	ft_rrs(t_psort *data);
void	ft_sort(t_psort *data);
void	ft_sort_small(t_psort *data);
void	ft_and_conquer(t_psort *data);
int		ft_check_sort(t_psort *data);
void	ft_divide(t_psort *data);

#endif
