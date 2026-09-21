#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

static void check_int(const char *name, int got, int expected)
{
	if (got == expected)
		printf("  [OK] %s\n", name);
	else
		printf("  [FAIL] %s: got %d, expected %d\n", name, got, expected);
}

static void check_bool(const char *name, int cond)
{
	if (cond)
		printf("  [OK] %s\n", name);
	else
		printf("  [FAIL] %s\n", name);
}

static void check_str(const char *name, const char *got, const char *expected)
{
	if (!got && !expected)
		printf("  [OK] %s\n", name);
	else if (got && expected && strcmp(got, expected) == 0)
		printf("  [OK] %s\n", name);
	else
		printf("  [FAIL] %s: got \"%s\", expected \"%s\"\n",
			name, got ? got : "(null)", expected ? expected : "(null)");
}

/* ========================================================================= */

void test_is_group(void)
{
	printf("--- Testing Character Checks ---\n");
	check_bool("ft_isalpha", ft_isalpha('a') && ft_isalpha('Z') && !ft_isalpha('1'));
	check_bool("ft_isdigit", ft_isdigit('0') && ft_isdigit('9') && !ft_isdigit('a'));
	check_bool("ft_isalnum", ft_isalnum('a') && ft_isalnum('5') && !ft_isalnum(' '));
	check_bool("ft_isascii", ft_isascii(0) && ft_isascii(127) && !ft_isascii(128));
	check_bool("ft_isprint", ft_isprint(' ') && ft_isprint('~') && !ft_isprint('\t'));
	check_int("ft_toupper", ft_toupper('a'), 'A');
	check_int("ft_tolower", ft_tolower('A'), 'a');
}

void test_string_group(void)
{
	printf("\n--- Testing String Functions ---\n");
	check_int("ft_strlen", (int)ft_strlen("42 Amman"), 8);

	const char *s = "tripouille";
	check_bool("ft_strchr ('t')", ft_strchr(s, 't') == s);
	check_bool("ft_strchr ('\\0')", ft_strchr(s, '\0') == (s + 10));
	check_bool("ft_strchr (not found)", ft_strchr(s, 'z') == NULL);

	check_bool("ft_strrchr ('l')", ft_strrchr(s, 'l') == (s + 8));
	check_bool("ft_strrchr ('\\0')", ft_strrchr(s, '\0') == (s + 10));
	check_bool("ft_strrchr (not found)", ft_strrchr(s, 'z') == NULL);

	check_bool("ft_strncmp (equal)", ft_strncmp("abc", "abc", 3) == 0);
	check_bool("ft_strncmp (less)", ft_strncmp("abc", "abd", 3) < 0);
	check_bool("ft_strncmp (greater)", ft_strncmp("abd", "abc", 3) > 0);
	check_bool("ft_strncmp (limit n)", ft_strncmp("abc", "abd", 2) == 0);

	const char *haystack = "see the needle in haystack";
	check_bool("ft_strnstr (found)", ft_strnstr(haystack, "needle", 20) == (haystack + 8));
	check_bool("ft_strnstr (out of bound)", ft_strnstr(haystack, "needle", 10) == NULL);
	check_bool("ft_strnstr (empty needle)", ft_strnstr(haystack, "", 5) == haystack);
}

void test_strl_group(void)
{
	printf("\n--- Testing strlcpy & strlcat ---\n");
	char dst[30];

	memset(dst, 'A', sizeof(dst));
	size_t r1 = ft_strlcpy(dst, "hello", 4);
	dst[3] = '\0'; // ensure null-terminated for strcmp test
	check_bool("ft_strlcpy return value", r1 == 5);
	check_str("ft_strlcpy buffer content", dst, "hel");

	memset(dst, 0, sizeof(dst));
	strcpy(dst, "hi ");
	size_t r2 = ft_strlcat(dst, "world", 7);
	check_bool("ft_strlcat return value", r2 == 8);
	check_str("ft_strlcat buffer content", dst, "hi wo");
}

void test_atoi_group(void)
{
	printf("\n--- Testing ft_atoi ---\n");
	check_int("ft_atoi (\"0\")", ft_atoi("0"), 0);
	check_int("ft_atoi (\"42\")", ft_atoi("42"), 42);
	check_int("ft_atoi (\"   -42\")", ft_atoi("   -42"), -42);
	check_int("ft_atoi (\"+1337abc\")", ft_atoi("+1337abc"), 1337);
	check_int("ft_atoi (\"\\t\\n\\r 99\")", ft_atoi("\t\n\r 99"), 99);
	check_int("ft_atoi (INT_MAX)", ft_atoi("2147483647"), INT_MAX);
	check_int("ft_atoi (INT_MIN)", ft_atoi("-2147483648"), INT_MIN);
}

int main(void)
{
	test_is_group();
	test_string_group();
	test_strl_group();
	test_atoi_group();
	return (0);
}