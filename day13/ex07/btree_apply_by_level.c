/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 14:42:23 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/18 14:43:13 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_lubisi(int left, int right)
{
	if (left > right)
		return (left);
	else
		return (right);
}

int		btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_lubisi(btree_level_count(root->left),
				btree_level_count(root->right)) + 1);
}

void	by_level2(t_btree *root, int current_level,
		int level,
		void (*applyf)(void *item, int current_level,
			int is_first_elem))
{
	if (!root)
		return ;
	if (level == current_level)
		(*applyf)(root->item, current_level, 0);
	else
	{
		by_level2(root->left, current_level + 1, level, applyf);
		by_level2(root->right, current_level + 1, level, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level,
			int is_first_elem))
{
	int i;
	int a;

	i = btree_level_count(root);
	a = 0;
	while (a < i)
	{
		by_level2(root, 0, j, applyf);
		a++;
	}
}
