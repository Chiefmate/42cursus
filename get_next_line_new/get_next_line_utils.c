/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:40:48 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/22 18:03:59 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*trim_keep(char *backup, ssize_t r_size)


/*
 * if n == 0, functions like strlen
 */
size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (s[len] && len < n && n)
		len++;
	while (s[len] && !n)
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			idx;

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

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*s;
	size_t			k;

	s = (unsigned char *)b;
	k = 0;
	while (k < n)
	{
		s[k] = c;
		k++;
	}
	return (b);
}

//  ft_strlen used
char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	idx;
	size_t	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	ret = (char *)malloc(sizeof(char) * (s_len + 1));
	if (ret == (void *)0)
		return (ret);
	idx = 0;
	while (idx < s_len)
	{
		ret[idx] = s[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
