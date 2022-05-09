/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #define ATOD(x)     (x - '@')
    #define DTOA(x)     (x + '0')
    #define ADTOD(x)    (x - '0')
    #define EXIT_ERR    84
    #define FALSE       0
    #define TRUE        1
    #define SUCC        0
    #define ERR         -1

// Print functions:

int my_isneg(int);

void my_put_nbr(int);

void my_putchar(char);

void my_putcherr(char);

void my_putarray(char **);

void my_putstr(const char *);

void my_putsterr(const char *);

// Character check functions;

int my_char_isnum(const char);

int my_char_islower(const char);

int my_char_isalpha(const char);

int my_char_isprintable(const char);

int my_char_in_str(const char *, const char);

// String check functions:

int my_str_isnum(const char *);

int my_str_isalpha(const char *);

int my_str_islower(const char *);

int my_str_isupper(const char *);

int my_str_isprintable(const char *);

int my_strcmp(const char *, const char *);

char *my_strstr(char const *, char const *);

int my_strncmp(const char *, const char *, int);

// String manipulation functions:

char *my_revstr(char *);

char *my_strupcase(char *);

char *my_strlowcase(char *);

char *my_strdup(const char *);

char *my_strcapitalize(char *);

char *my_strcat(char *, const char *);

char * my_strcpy(char *, const char *);

char *my_strncpy(char *, const char *, int);

char *my_strncat(char *, const char *, int);

char *my_strrchr(const char *string, int c);

// Memory manipulations functions:

void my_memset(void *s, int c, int n);

void my_memcpy(void *, const void *, int);

//  Allocation functions:

void *my_realloc(void *, int, int, int);

void *my_reallocarray(void *, int, int, int);

// Tokenise and stwa functions:

char *my_strtok(char *, const char *);

char **my_str_to_word_array(char *, const char *);

// Calcul functions:

int my_is_prime(int);

int my_find_prime_sup(int);

int my_compute_square_root(int);

int my_compute_power_rec(int, int);

// String array manipulation functions:

char **my_malloc_tab(int);

void my_free_array(char **);

char **my_tab_copy(char *[]);

// Find len and manipulate it functions:

int my_getnbr(char *);

int my_tablen(char *[]);

int len_cmp(char *, char *);

int my_strlen(const char *);

// 

int my_bswap(int);

void my_swap(int *, int *);

char *my_file_in_str(const char *);

#endif /* MY_H_ */
