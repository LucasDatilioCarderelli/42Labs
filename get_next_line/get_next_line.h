/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:37:19 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/23 20:09:39 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define BUFFER_SIZE 42

/**	@brief	Description Write a function which returns a line read from a
 *			file descriptor.
 *	@param	fd	File descriptor to read from.
 *	@return	Read line: correct behavior. NULL if there is nothing else to read
 *			or an error occurred */
char	*get_next_line(int fd);

/** @brief	Returns a pointer to the first occurrence
 * 			of the character c in the string s.
 * @param	s Pointer to the string memory area
 * @param	c Character to be searched inside the string s
 * @return	char* Return a pointer to the matched character
 * 			or NULL if the character is not found. */
char	*ft_strchr(const char *s, int c);

/**	@brief	Returns a pointer to a new string
 * 			which is a duplicate of the string s.
 *	@param	s1 Pointer to the start of the string do be copied
 *	@return	char* On success, returns a pointer to the
 * 			duplicated string. It returns NULL if insufficient memory was
 * 			available, with errno set to indicate the cause of the error.*/
char	*ft_strdup(const char *s1);

/**	@brief	Allocates (with malloc(3)) and returns a newstring,
 *			which is the result of the concatenation of ’s1’ and ’s2’.
 *	@param	s1 The prefix string
 *	@param	s2 The suffix string
 *	@return char* Returns the new string or NULL if the allocation fails. */
char	*ft_strjoin(char const *s1, char const *s2);

/**	@brief	Copies up to size - 1 characters from
 * 			the NUL-terminated string src to dest, NUL-terminating the result.
 * @param	dest	Pointer to the destination area of memory
 * @param	src		Pointer to the source area of memory
 * @param	size	Buffer size in bytes
 * @return	size_t Returns the length of src. */
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);

/**	@brief	calculates the length of the string pointed to by s,
 * 			excluding the terminating null byte ('\0').
 *	@param 	s Pointer to the initial area of the string
 *	@return	size_t Returns the number of bytes in the string pointed to by s.*/
size_t	ft_strlen(const char *s);

#endif
