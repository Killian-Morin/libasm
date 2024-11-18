/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:05:40 by kmorin            #+#    #+#             */
/*   Updated: 2024/11/18 15:29:51 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"

size_t	ft_strlen(const char *str);
// int		ft_strcmp(const char *s1, const char *s2);
// char	*ft_strcpy(char *dest, const char *src);
// ssize_t	ft_write(int fd, const void *buf, size_t count);
// ssize_t	ft_read(int fd, void *buf, size_t count);
// char	*ft_strdup(const char *s);

void strlen_test() {

	const char	*long_string = "This is a long long long long long long string. I wonder it's length ?";
	const char	*small_string = "Hello World !";
	const char	*empty_string = "";
	// char	*correction_string = "";
	size_t	res_offical, res_mine;

	printf(BLUE "Test string in use:\n\t" CYAN "%s\n" RESET, long_string);
	res_offical = strlen(long_string);
	printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	res_mine = ft_strlen(long_string);
	printf("Result from ft_strlen: " YELLOW "%zu\n\n" RESET, res_mine);

	printf(BLUE "Test string in use:\n\t" CYAN "%s\n" RESET, small_string);
	res_offical = strlen(small_string);
	printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	res_mine = ft_strlen(small_string);
	printf("Result from ft_strlen: " YELLOW "%zu\n\n" RESET, res_mine);

	printf(BLUE "Test string in use:\n\t" CYAN"%s\n" RESET, empty_string);
	res_offical = strlen(empty_string);
	printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	res_mine = ft_strlen(empty_string);
	printf("Result from ft_strlen: " YELLOW "%zu\n" RESET, res_mine);


	// printf(BLUE "Test string in use:\n%s" RESET, correction_string);
	// res_offical = strlen(correction_string);
	// printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	// res_mine = ft_strlen(correction_string);
	// printf("Result from ft_strlen: " YELLOW "%d" RESET, res_mine);
}

void strcmp_test() {

}

void strcpy_test() {

}

void write_test() {

}

void read_test() {

}

void strdup_test() {

}

int main(void) {

	strlen_test();

	return 0;
}
