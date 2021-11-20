/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:32:28 by hyunhole          #+#    #+#             */
/*   Updated: 2021/11/19 12:32:28 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t  ft_strlen(const char *s)
{
    char    *temp;
    size_t  len;

    len = 0;
    temp = s;
    while (temp[len])
    {
        len++;
    }
    return (len);
}

void    *ft_memset(void *b, int c, size_t n)
{
    unsigned char   *s = b;
    size_t          k;

    k = 0;
    while (k < n)
    {
        s[k] = c;
        k++;
    }
    return (b);
}

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
    return ;
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char   *d;
    unsigned char   *s;
    size_t          idx;

    d = (unsigned char *) dst;
    s = (unsigned char *) src;
    idx = 0;
    if (d < s)
    {
        while (idx < n)
        {
            d[idx] = s[idx];
            idx++;
        }
    }
    else if (d > s)
    {
        idx = n;
        while (idx > 0)
        {
            idx--;
            d[idx] = s[idx];
        }
    }
    return (dst);
}

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    return (ft_memcpy(dst, src, len));
}