/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:05:40 by kmorin            #+#    #+#             */
/*   Updated: 2024/11/19 12:13:22 by kmorin           ###   ########.fr       */
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
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
// ssize_t	ft_write(int fd, const void *buf, size_t count);
// ssize_t	ft_read(int fd, void *buf, size_t count);
// char	*ft_strdup(const char *s);

void strlen_test() {

	const char	*long_string = "This is a long long long long long long string. I wonder it's length ?";
	const char	*small_string = "Hello World !";
	const char	*empty_string = "";
	const char	*other_string = "abcde\n\0\0";
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
	printf("Result from ft_strlen: " YELLOW "%zu\n\n" RESET, res_mine);

	printf(BLUE "Test string in use:\n\t" CYAN"%s\n" RESET, other_string);
	res_offical = strlen(other_string);
	printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	res_mine = ft_strlen(other_string);
	printf("Result from ft_strlen: " YELLOW "%zu\n" RESET, res_mine);

	// TEST with the correction_string given
	// printf(BLUE "Test string in use:\n%s" RESET, correction_string);
	// res_offical = strlen(correction_string);
	// printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	// res_mine = ft_strlen(correction_string);
	// printf("Result from ft_strlen: " YELLOW "%d" RESET, res_mine);
}

void strcmp_test() {

	char	*s1, *s2;
	int		res_official, res_mine;

	s1 = "Hello World";
	s2 = "Hello World";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	s1 = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World";
	s2 = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	s1 = "Hello Worldd";
	s2 = "Hello World";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	s1 = "Hello World";
	s2 = "Hello Worldd";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	s1 = "Hello World";
	s2 = "";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	s1 = "";
	s2 = "Hello World";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	s1 = "";
	s2 = "";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	s1 = "A";
	s2 = "a";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	s1 = "a";
	s2 = "A";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);
}

void strcpy_test() {

	char	*src;
	char	dest[20];
	char	*ret_offical, *ret_mine;

	src = "Hello World";
	printf(BLUE "Copy '%s' into dest\n" RESET, src);
	ret_offical = strcpy(dest, src);
	printf("Result from strcpy:    " GREEN "%s\n" RESET, ret_offical);
	ret_mine = ft_strcpy(dest, src);
	printf("Result from ft_strcpy: " YELLOW "%s\n\n" RESET, ret_mine);

	src = "";
	printf(BLUE "Copy '%s' into dest\n" RESET, src);
	ret_offical = strcpy(dest, src);
	printf("Result from strcpy:    " GREEN "%s\n" RESET, ret_offical);
	ret_mine = ft_strcpy(dest, src);
	printf("Result from ft_strcpy: " YELLOW "%s\n\n" RESET, ret_mine);

	src = "This is a long long long long long long string. I wonder if I can copy it ?";
	printf(BLUE "Copy '%s' into dest\n" RESET, src);
	ret_offical = strcpy(dest, src);
	printf("Result from strcpy:    " GREEN "%s\n" RESET, ret_offical);
	ret_mine = ft_strcpy(dest, src);
	printf("Result from ft_strcpy: " YELLOW "%s\n\n" RESET, ret_mine);

	char	dest_long[100];
	src = "This is a long long long long long long string. I wonder if I can copy it ?";
	printf(BLUE "Copy '%s' into dest_long\n" RESET, src);
	ret_offical = strcpy(dest_long, src);
	printf("Result from strcpy:    " GREEN "%s\n" RESET, ret_offical);
	ret_mine = ft_strcpy(dest_long, src);
	printf("Result from ft_strcpy: " YELLOW "%s\n\n" RESET, ret_mine);

	// TEST that segfault since dest already has content
	// src = "Hello World";
	// char	*dest_init = "";
	// printf(BLUE "Copy '%s' into dest\n" RESET, src);
	// ret_offical = strcpy(dest_init, src);
	// printf("Result from strcpy:    " GREEN "%s\n" RESET, ret_offical);
	// ret_mine = ft_strcpy(dest_init, src);
	// printf("Result from ft_strcpy: " YELLOW "%s\n\n" RESET, ret_mine);
}

void write_test() {

}

void read_test() {

}

void strdup_test() {

}

int main(void) {

	printf(MAGENTA "===============STRLEN===============\n" RESET);

	strlen_test();

	printf(MAGENTA "\n===============STRCMP===============\n" RESET);

	strcmp_test();

	printf(MAGENTA "\n===============STRCPY===============\n" RESET);

	strcpy_test();

	// printf(MAGENTA "\n===============WRITE================\n" RESET);

	// write_test();

	// printf(MAGENTA "\n================READ================\n" RESET);

	// read_test();

	// printf(MAGENTA "\n===============STRDUP===============\n" RESET);

	// strdup_test();

	// printf(MAGENTA "\n===============THE END==============\n" RESET);

	return 0;
}
