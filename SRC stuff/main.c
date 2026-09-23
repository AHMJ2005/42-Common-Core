#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

/* --- Utility Assertions --- */

static void print_res(const char *name, int condition)
{
	if (condition)
		printf("  [OK] %s\n", name);
	else
		printf("  [FAIL] %s\n", name);
}

static void capture_fd(void (*f)(int, int), int val, char *buf, size_t max)
{
	int pipefd[2];
	if (pipe(pipefd) == -1) return;
	f(val, pipefd[1]);
	close(pipefd[1]);
	ssize_t r = read(pipefd[0], buf, max - 1);
	close(pipefd[0]);
	buf[r >= 0 ? r : 0] = '\0';
}

static void capture_str_fd(void (*f)(char *, int), char *str, char *buf, size_t max)
{
	int pipefd[2];
	if (pipe(pipefd) == -1) return;
	f(str, pipefd[1]);
	close(pipefd[1]);
	ssize_t r = read(pipefd[0], buf, max - 1);
	close(pipefd[0]);
	buf[r >= 0 ? r : 0] = '\0';
}

static void capture_char_fd(void (*f)(char, int), char c, char *buf, size_t max)
{
	int pipefd[2];
	if (pipe(pipefd) == -1) return;
	f(c, pipefd[1]);
	close(pipefd[1]);
	ssize_t r = read(pipefd[0], buf, max - 1);
	close(pipefd[0]);
	buf[r >= 0 ? r : 0] = '\0';
}

static char mapi_shift(unsigned int i, char c)
{
	return (c + (char)i);
}

static void del_content(void *content)
{
	free(content);
}

static void to_upper_iter(void *content)
{
	char *s = (char *)content;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}

static void *duplicate_map(void *content)
{
	char *src = (char *)content;
	char *new_str = ft_strjoin("mapped_", src);
	return ((void *)new_str);
}

/* ========================================================================= */
/*                               TEST SUITES                                 */
/* ========================================================================= */

void test_ctype(void)
{
	printf("\n--- 1. CTYPE & CONVERSIONS ---\n");
	print_res("ft_isalpha", ft_isalpha('A') && ft_isalpha('z') && !ft_isalpha('3'));
	print_res("ft_isdigit", ft_isdigit('0') && ft_isdigit('9') && !ft_isdigit('x'));
	print_res("ft_isalnum", ft_isalnum('A') && ft_isalnum('4') && !ft_isalnum('#'));
	print_res("ft_isascii", ft_isascii(0) && ft_isascii(127) && !ft_isascii(128));
	print_res("ft_isprint", ft_isprint(' ') && ft_isprint('~') && !ft_isprint('\t'));
	print_res("ft_toupper", ft_toupper('a') == 'A' && ft_toupper('Z') == 'Z');
	print_res("ft_tolower", ft_tolower('A') == 'a' && ft_tolower('z') == 'z');
}

void test_memory(void)
{
	printf("\n--- 2. MEMORY FUNCTIONS ---\n");
	char b1[20], b2[20];

	ft_memset(b1, 'A', 10);
	memset(b2, 'A', 10);
	print_res("ft_memset", memcmp(b1, b2, 10) == 0);

	ft_bzero(b1, 5);
	bzero(b2, 5);
	print_res("ft_bzero", memcmp(b1, b2, 10) == 0);

	ft_memcpy(b1, "123456789", 9);
	print_res("ft_memcpy", memcmp(b1, "123456789", 9) == 0);

	char mv[20] = "abcdefghij";
	ft_memmove(mv + 2, mv, 5);
	print_res("ft_memmove (overlap)", memcmp(mv, "ababcdehij", 10) == 0);

	char arr[] = {10, 20, 30, 40, 50};
	print_res("ft_memchr", ft_memchr(arr, 30, 5) == (arr + 2) && ft_memchr(arr, 99, 5) == NULL);
	print_res("ft_memcmp", ft_memcmp("abc", "abd", 3) < 0 && ft_memcmp("abc", "abc", 3) == 0);
}

void test_string_basics(void)
{
	printf("\n--- 3. STRING BASICS ---\n");
	print_res("ft_strlen", ft_strlen("42 Amman") == 8 && ft_strlen("") == 0);

	const char *s = "tripouille";
	print_res("ft_strchr", ft_strchr(s, 't') == s && ft_strchr(s, '\0') == (s + 10) && !ft_strchr(s, 'x'));
	print_res("ft_strrchr", ft_strrchr(s, 'l') == (s + 8) && ft_strrchr(s, '\0') == (s + 10));

	print_res("ft_strncmp", ft_strncmp("abc", "abd", 2) == 0 && ft_strncmp("abc", "abd", 3) < 0);

	const char *haystack = "needle in haystack";
	print_res("ft_strnstr", ft_strnstr(haystack, "needle", 10) == haystack &&
							ft_strnstr(haystack, "stack", 10) == NULL &&
							ft_strnstr(haystack, "", 5) == haystack);

	char dst[20];
	size_t r1 = ft_strlcpy(dst, "hello", 4);
	print_res("ft_strlcpy", r1 == 5 && strcmp(dst, "hel") == 0);

	strcpy(dst, "hi ");
	size_t r2 = ft_strlcat(dst, "world", 7);
	print_res("ft_strlcat", r2 == 8 && strcmp(dst, "hi wor") == 0);
}

void test_stdlib_allocations(void)
{
	printf("\n--- 4. STDLIB & ALLOCATIONS ---\n");
	print_res("ft_atoi", ft_atoi("   -42") == -42 &&
						 ft_atoi("+1337") == 1337 &&
						 ft_atoi("0") == 0 &&
						 ft_atoi("-2147483648") == INT_MIN);

	char *dup = ft_strdup("duplicate");
	print_res("ft_strdup", dup && strcmp(dup, "duplicate") == 0);
	free(dup);

	int *arr = (int *)ft_calloc(5, sizeof(int));
	int calloc_ok = arr != NULL;
	if (calloc_ok)
	{
		for (int i = 0; i < 5; i++)
			if (arr[i] != 0) calloc_ok = 0;
		free(arr);
	}
	print_res("ft_calloc", calloc_ok);

	char *it1 = ft_itoa(0);
	char *it2 = ft_itoa(-2147483648);
	char *it3 = ft_itoa(42);
	print_res("ft_itoa", strcmp(it1, "0") == 0 &&
						 strcmp(it2, "-2147483648") == 0 &&
						 strcmp(it3, "42") == 0);
	free(it1); free(it2); free(it3);
}

void test_additional_strings(void)
{
	printf("\n--- 5. ADDITIONAL STRING UTILITIES ---\n");

	char *sub = ft_substr("tripouille", 4, 3);
	print_res("ft_substr", sub && strcmp(sub, "oui") == 0);
	free(sub);

	char *joined = ft_strjoin("hello ", "world");
	print_res("ft_strjoin", joined && strcmp(joined, "hello world") == 0);
	free(joined);

	char *trimmed = ft_strtrim("  \t  hello 42 \n  ", " \t\n");
	print_res("ft_strtrim", trimmed && strcmp(trimmed, "hello 42") == 0);
	free(trimmed);

	char *mapped = ft_strmapi("aaaa", mapi_shift);
	print_res("ft_strmapi", mapped && strcmp(mapped, "abcd") == 0);
	free(mapped);

	char **tokens = ft_split("  lorem   ipsum  dolor  ", ' ');
	int split_ok = (tokens &&
					tokens[0] && strcmp(tokens[0], "lorem") == 0 &&
					tokens[1] && strcmp(tokens[1], "ipsum") == 0 &&
					tokens[2] && strcmp(tokens[2], "dolor") == 0 &&
					tokens[3] == NULL);
	print_res("ft_split", split_ok);
	if (tokens)
	{
		for (int i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);
	}
}

void test_fd(void)
{
	printf("\n--- 6. FILE DESCRIPTOR WRITES ---\n");
	char buf[50];

	capture_char_fd(ft_putchar_fd, 'Z', buf, sizeof(buf));
	print_res("ft_putchar_fd", strcmp(buf, "Z") == 0);

	capture_str_fd(ft_putstr_fd, "Hello", buf, sizeof(buf));
	print_res("ft_putstr_fd", strcmp(buf, "Hello") == 0);

	capture_str_fd(ft_putendl_fd, "Line", buf, sizeof(buf));
	print_res("ft_putendl_fd", strcmp(buf, "Line\n") == 0);

	capture_fd(ft_putnbr_fd, -2147483648, buf, sizeof(buf));
	print_res("ft_putnbr_fd", strcmp(buf, "-2147483648") == 0);
}

void test_lists(void)
{
	printf("\n--- 7. LINKED LISTS (BONUS) ---\n");

	t_list *head = ft_lstnew(ft_strdup("node 1"));
	print_res("ft_lstnew", head && strcmp((char *)head->content, "node 1") == 0 && head->next == NULL);

	t_list *front = ft_lstnew(ft_strdup("node 0"));
	ft_lstadd_front(&head, front);
	print_res("ft_lstadd_front", head == front && strcmp((char *)head->content, "node 0") == 0);

	print_res("ft_lstsize", ft_lstsize(head) == 2);

	t_list *back = ft_lstnew(ft_strdup("node 2"));
	ft_lstadd_back(&head, back);
	print_res("ft_lstadd_back", ft_lstsize(head) == 3);

	print_res("ft_lstlast", ft_lstlast(head) == back);

	/* ft_lstiter */
	ft_lstiter(head, to_upper_iter);
	int iter_ok = (strcmp((char *)head->content, "NODE 0") == 0 &&
				   strcmp((char *)head->next->content, "NODE 1") == 0 &&
				   strcmp((char *)head->next->next->content, "NODE 2") == 0);
	print_res("ft_lstiter", iter_ok);

	/* ft_lstmap */
	t_list *mapped = ft_lstmap(head, duplicate_map, del_content);
	int map_ok = (mapped != NULL &&
				  mapped != head &&
				  strcmp((char *)mapped->content, "mapped_NODE 0") == 0 &&
				  strcmp((char *)mapped->next->content, "mapped_NODE 1") == 0 &&
				  strcmp((char *)mapped->next->next->content, "mapped_NODE 2") == 0 &&
				  mapped->next->next->next == NULL);
	print_res("ft_lstmap", map_ok);

	/* ft_lstdelone */
	t_list *single = ft_lstnew(ft_strdup("delete me"));
	ft_lstdelone(single, del_content);
	print_res("ft_lstdelone", 1);

	/* ft_lstclear */
	ft_lstclear(&mapped, del_content);
	print_res("ft_lstclear (mapped)", mapped == NULL);

	ft_lstclear(&head, del_content);
	print_res("ft_lstclear (original)", head == NULL);
}

int main(void)
{
	printf("=========================================\n");
	printf("       COMPLETE LIBFT VERIFICATION       \n");
	printf("=========================================\n");

	test_ctype();
	test_memory();
	test_string_basics();
	test_stdlib_allocations();
	test_additional_strings();
	test_fd();
	test_lists();

	printf("\n=========================================\n");
	return (0);
}