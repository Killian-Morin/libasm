/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:05:40 by kmorin            #+#    #+#             */
/*   Updated: 2024/11/19 17:26:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

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
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
// char	*ft_strdup(const char *s);

void strlen_test() {

	const char	*long_string = "This is a long long long long long long string. I wonder it's length ?";
	const char	*small_string = "Hello World !";
	const char	*empty_string = "";
	const char	*other_string = "abcde\n\0\0";
	// char	*correction_string = "";
	size_t	res_offical, res_mine;

	// Get the len of a long string
	printf(BLUE "Test string in use:\n\t" CYAN "%s\n" RESET, long_string);
	res_offical = strlen(long_string);
	printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	res_mine = ft_strlen(long_string);
	printf("Result from ft_strlen: " YELLOW "%zu\n\n" RESET, res_mine);

	// Get the len of a small string
	printf(BLUE "Test string in use:\n\t" CYAN "%s\n" RESET, small_string);
	res_offical = strlen(small_string);
	printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	res_mine = ft_strlen(small_string);
	printf("Result from ft_strlen: " YELLOW "%zu\n\n" RESET, res_mine);

	// Get the len of an empty string
	printf(BLUE "Test string in use:\n\t" CYAN"%s\n" RESET, empty_string);
	res_offical = strlen(empty_string);
	printf("Result from strlen:    " GREEN "%zu\n" RESET, res_offical);
	res_mine = ft_strlen(empty_string);
	printf("Result from ft_strlen: " YELLOW "%zu\n\n" RESET, res_mine);

	// Get the length of a string that has a '\0'
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

	// Compare two similar strings
	s1 = "Hello World";
	s2 = "Hello World";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	// Compare two similar long strings
	s1 = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World";
	s2 = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	// Compare two strings with s1 longer
	s1 = "Hello Worldd";
	s2 = "Hello World";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	// Compare two strings with s2 longer
	s1 = "Hello World";
	s2 = "Hello Worldd";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	// Compare s1 as a string and s2 as an empty string
	s1 = "Hello World";
	s2 = "";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	// Compare s1 as an empty string and s2 as a string
	s1 = "";
	s2 = "Hello World";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	// Compare two empty strings
	s1 = "";
	s2 = "";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	// Compare two characters with s1 > s2 (expect negative result)
	s1 = "A";
	s2 = "a";
	printf(BLUE "Compare '%s' with '%s'\n" RESET, s1, s2);
	res_official = strcmp(s1, s2);
	printf("Result from strcmp:    " GREEN "%d\n" RESET, res_official);
	res_mine = ft_strcmp(s1, s2);
	printf("Result from ft_strcmp: " YELLOW "%d\n\n" RESET, res_mine);

	// Compare two characters with s1 < s2 (expect positive result)
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

	// Copy a string to a dest with enough size
	src = "Hello World";
	printf(BLUE "Copy '%s' into dest\n" RESET, src);
	ret_offical = strcpy(dest, src);
	printf("Result from strcpy:    " GREEN "%s\n" RESET, ret_offical);
	ret_mine = ft_strcpy(dest, src);
	printf("Result from ft_strcpy: " YELLOW "%s\n\n" RESET, ret_mine);

	// Copy an empty string to a dest with enough size
	src = "";
	printf(BLUE "Copy '%s' into dest\n" RESET, src);
	ret_offical = strcpy(dest, src);
	printf("Result from strcpy:    " GREEN "%s\n" RESET, ret_offical);
	ret_mine = ft_strcpy(dest, src);
	printf("Result from ft_strcpy: " YELLOW "%s\n\n" RESET, ret_mine);

	// Copy a long string to a dest with not enough size (expect buffer overflow)
	src = "This is a long long long long long long string. I wonder if I can copy it ?";
	printf(BLUE "Copy '%s' into dest\n" RESET, src);
	ret_offical = strcpy(dest, src);
	printf("Result from strcpy:    " GREEN "%s\n" RESET, ret_offical);
	ret_mine = ft_strcpy(dest, src);
	printf("Result from ft_strcpy: " YELLOW "%s\n\n" RESET, ret_mine);

	// Copy a long string to a dest with enough size
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

	int		fd = 1;
	char	*buf;
	size_t	count;
	ssize_t	res_offical, res_mine;

	// Write to stdout with the size of the string
	buf = "Hello World";
	count = 12;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	fflush(stdout);
	printf("\nResult from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	res_mine = ft_write(fd, buf, count);
	fflush(stdout);
	printf("\nResult from ft_write: " YELLOW "%ld\n\n" RESET, res_mine);
	fflush(stdout);

	// Write to stdout with a size smaller than the string
	buf = "Hello World";
	count = 5;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	fflush(stdout);
	printf("\nResult from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	res_mine = ft_write(fd, buf, count);
	fflush(stdout);
	printf("\nResult from ft_write: " YELLOW "%ld\n\n" RESET, res_mine);
	fflush(stdout);

	// Write to stdout with a size greater than the string
	buf = "Hello World";
	count = 20;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	fflush(stdout);
	printf("\nResult from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	res_mine = ft_write(fd, buf, count);
	fflush(stdout);
	printf("\nResult from ft_write: " YELLOW "%ld\n\n" RESET, res_mine);
	fflush(stdout);

	// Write to stdout with an empty string
	buf = "";
	count = 20;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	fflush(stdout);
	printf("\nResult from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	res_mine = ft_write(fd, buf, count);
	fflush(stdout);
	printf("\nResult from ft_write: " YELLOW "%ld\n\n" RESET, res_mine);
	fflush(stdout);

	// Create 'file.txt' to write to a file
	fd = open("file.txt", O_CREAT | O_WRONLY, 00600);

	// Write to a file with the size of the string
	buf = "Hello World\n";
	count = 12;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	printf("Result from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	res_mine = ft_write(fd, buf, count);
	printf("Result from ft_write: " YELLOW "%ld\n\n" RESET, res_mine);
	fflush(stdout);

	write(fd, "\n\n", 2);

	// Write to a file with a size smaller than the string
	buf = "Hello World";
	count = 5;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	printf("Result from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	res_mine = ft_write(fd, buf, count);
	printf("Result from ft_write: " YELLOW "%ld\n\n" RESET, res_mine);
	fflush(stdout);

	write(fd, "\n\n", 2);

	// Write to a file with a size greater than the string
	buf = "Hello World";
	count = 20;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	printf("Result from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	res_mine = ft_write(fd, buf, count);
	printf("Result from ft_write: " YELLOW "%ld\n\n" RESET, res_mine);
	fflush(stdout);

	write(fd, "\n\n", 2);

	// Write to a file with an empty string
	buf = "";
	count = 20;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	printf("Result from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	res_mine = ft_write(fd, buf, count);
	printf("Result from ft_write: " YELLOW "%ld\n\n" RESET, res_mine);
	fflush(stdout);

	// Test the errno

	// Write to a fd that is not opened (EBADF)
	errno = 0;
	fd = 42;
	buf = "Hello World";
	count = 12;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	printf("Result from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	perror("errno after write");
	errno = 0;
	res_mine = ft_write(fd, buf, count);
	printf("\nResult from ft_write: " YELLOW "%ld\n" RESET, res_mine);
	fflush(stdout);
	perror("errno after ft_write");

	// Write to a fd that doesn't have the permissions to write on it (EBADF)
	errno = 0;
	fd = open("cant_open.txt", O_CREAT, 00000);
	buf = "Hello World";
	count = 12;
	printf(BLUE "Write '%ld' bytes of '%s' to fd '%d'\n" RESET, count, buf, fd);
	fflush(stdout);
	res_offical = write(fd, buf, count);
	printf("Result from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	perror("errno after write");
	errno = 0;
	res_mine = ft_write(fd, buf, count);
	printf("\nResult from ft_write: " YELLOW "%ld\n" RESET, res_mine);
	fflush(stdout);
	perror("errno after ft_write");

	// Write to stdout with an invalid buffer (EFAULT)
	errno = 0;
	fd = 1;
	char	*invalid_ptr = (char *)(-1);
	count = 42;
	printf(BLUE "Write '%ld' bytes of an invalid buffer to fd '%d'\n" RESET, count, fd);
	fflush(stdout);
	res_offical = write(fd, invalid_ptr, count);
	printf("Result from write:    " GREEN "%ld\n" RESET, res_offical);
	fflush(stdout);
	perror("errno after write");
	errno = 0;
	res_mine = ft_write(fd, invalid_ptr, count);
	printf("\nResult from ft_write: " YELLOW "%ld\n" RESET, res_mine);
	fflush(stdout);
	perror("errno after ft_write");
}

void read_test() {

	int		fd = 0;
	char	*buf;
	size_t	count;
	ssize_t	res_offical, res_mine;

	// Read 100 from stdin
	count = 100;
	printf(BLUE "Read '%ld' bytes from fd '%d'\n" RESET, count, fd);
	fflush(NULL);
	buf = malloc(100);
	res_offical = read(fd, buf, count);
	printf("\nResult from read:    " GREEN "%ld buf = '%s'\n" RESET, res_offical, buf);
	fflush(NULL);
	buf = malloc(100);
	res_mine = ft_read(fd, buf, count);
	printf("\nResult from ft_read: " YELLOW "%ld buf = '%s'\n\n" RESET, res_mine, buf);
	fflush(NULL);

	// Read 10 from a file
	fd = open("file.txt", O_CREAT | O_RDONLY, 00600);
	count = 10;
	printf(BLUE "Read '%ld' bytes from fd '%d'\n" RESET, count, fd);
	fflush(NULL);
	buf = malloc(100);
	res_offical = read(fd, buf, count);
	printf("\nResult from read:    " GREEN "%ld buf = '%s'\n" RESET, res_offical, buf);
	fflush(NULL);
	fd = open("file.txt", O_CREAT | O_RDONLY, 00600); // reopen it to reset the index in the file
	buf = malloc(100);
	res_mine = ft_read(fd, buf, count);
	printf("\nResult from ft_read: " YELLOW "%ld buf = '%s'\n\n" RESET, res_mine, buf);
	fflush(NULL);

	// Test the errno

	// Read from a fd that is not opened (EBADF)
	errno = 0;
	fd = -1;
	count = 10;
	printf(BLUE "Read '%ld' bytes from fd '%d'\n" RESET, count, fd);
	fflush(NULL);
	buf = malloc(100);
	res_offical = read(fd, buf, count);
	printf("\nResult from read:    " GREEN "%ld buf = '%s'\n" RESET, res_offical, buf);
	fflush(NULL);
	perror("errno after read");
	errno = 0;
	buf = malloc(100);
	res_mine = ft_read(fd, buf, count);
	printf("\nResult from ft_read: " YELLOW "%ld buf = '%s'\n" RESET, res_mine, buf);
	fflush(NULL);
	perror("errno after ft_read");

	// Read from a fd that doesn't have the permissions to read it (EBADF)
	errno = 0;
	fd = open("cant_open.txt", O_CREAT, 00000);
	count = 10;
	printf(BLUE "Read '%ld' bytes from fd '%d'\n" RESET, count, fd);
	fflush(NULL);
	buf = malloc(100);
	res_offical = read(fd, buf, count);
	printf("\nResult from read:    " GREEN "%ld buf = '%s'\n" RESET, res_offical, buf);
	fflush(NULL);
	perror("errno after read");
	errno = 0;
	buf = malloc(100);
	res_mine = ft_read(fd, buf, count);
	printf("\nResult from ft_read: " YELLOW "%ld buf = '%s'\n" RESET, res_mine, buf);
	fflush(NULL);
	perror("errno after ft_read");

	// Read from stdout with an invalid buffer (EFAULT)
	errno = 0;
	fd = 1;
	char	*invalid_ptr = (char *)(-1);
	count = 42;
	printf(BLUE "Read '%ld' bytes of an invalid buffer to fd '%d'\n" RESET, count, fd);
	fflush(stdout);
	buf = malloc(100);
	res_offical = read(fd, invalid_ptr, count);
	printf("Result from read:    " GREEN "%ld buf = '%s'\n" RESET, res_offical, buf);
	fflush(stdout);
	perror("errno after read");
	errno = 0;
	buf = malloc(100);
	res_mine = ft_read(fd, invalid_ptr, count);
	printf("\nResult from ft_read: " YELLOW "%ld buf = '%s'\n" RESET, res_mine, buf);
	fflush(stdout);
	perror("errno after ft_read");
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

	printf(MAGENTA "\n===============WRITE================\n" RESET);

	write_test();

	printf(MAGENTA "\n================READ================\n" RESET);

	read_test();

	// printf(MAGENTA "\n===============STRDUP===============\n" RESET);

	// strdup_test();

	// printf(MAGENTA "\n===============THE END==============\n" RESET);

	return 0;
}
