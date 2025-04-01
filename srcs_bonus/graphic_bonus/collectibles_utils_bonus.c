/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:17:07 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/01 18:59:19 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

// static char    *replace(char *str, char old, char new)
// {
//     char    *new_str;
//     int     i;

//     new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
//     if (!new_str)
//         return (NULL);
//     i = 0;
//     while (str[i])
//     {
//         if (str[i] == old)
//             new_str[i] = new;
//         else
//             new_str[i] = str[i];
//         i++;
//     }
//     new_str[i] = '\0';
//     return (new_str);
// }

t_collectible   *create_node(t_vector pos, t_game *game)
{
    t_collectible   *new_node;

    new_node = malloc(sizeof(t_collectible));
    new_node->texture = game->texture.collectible_0;
    new_node->pos = pos;
    new_node->collected = 0;
    new_node->idx = game->items_collected;
    new_node->next = NULL;
    return (new_node);
}

void   add_node(t_collectible **head, t_vector pos, t_game *game)
{
    t_collectible   *new_node;
    t_collectible   *temp;

    new_node = create_node(pos, game);
    temp = *head;
    if (*head == NULL)
    {
        *head = malloc(sizeof(t_collectible));
        *head = new_node;
        return ;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = malloc(sizeof(t_collectible));
    temp->next = new_node;
    return ;
}

void    free_list(t_collectible **head)
{
    t_collectible   *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
