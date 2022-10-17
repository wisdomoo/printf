#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct Checkstr - Struct to check format
 *
 * @flag: character associated to flags
 * @flagnot: Flags that are not allowed per specifier
 */
typedef struct Checkstr
{
	char flag;
	char *flagnot;
} checkstr;

/**
 * struct Specs_t - struct to call specifier functions
 *
 * @s: character representing specifier
 * @f: The function associated
 */
typedef struct Specs_t
{
	char s;
	char *(*f)(const char *, int, va_list, int *);
} specs_t;
/* Custom printf function */
int _printf(const char *format, ...);

/* Auxiliar functions */
int _strlen(char *s);
int blen(unsigned long int n, unsigned long int base);
int blen10(long int n, long int base);
void rev_str(char *s);
char *hexS(int n);
char *rot13(char *s);
int check_format(const char *formspec, int j);
int check_specs(const char *s, int *p);
void _memcpy(char *buffer, const char *src, int *i_b, int *stock, int n);
void print_number_str(long int n, char *str);
void print_number_str_u(unsigned long int n, char *str);
int free_buffer(char *, int);
int effective_length(char *buffer);

/* Generate strings functions */
char *generate_malloc(const char *s, int len_p, va_list list, int *);
char *gen_c(const char *, int, va_list, int *);
char *gen_s(const char *, int, va_list, int *);
char *gen_d(const char *, int, va_list, int *);
char *gen_i(const char *, int, va_list, int *);
char *gen_o(const char *, int, va_list, int *);
char *gen_b(const char *, int, va_list, int *);
char *gen_x(const char *, int, va_list, int *);
char *gen_X(const char *, int, va_list, int *);
char *gen_p(const char *, int, va_list, int *);
char *gen_u(const char *, int, va_list, int *);
char *gen_S(const char *, int, va_list, int *);
char *gen_r(const char *, int, va_list, int *);
char *gen_R(const char *, int, va_list, int *);
char *gen_per(const char *, int, va_list, int *);
/* Flags functions */
unsigned int get_width(const char *pattern, int len_p, va_list list);
unsigned int get_precision(const char *pattern, int len_p, va_list list);
long int get_param(const char *pattern, int len_p, va_list list);
unsigned long int get_param_u(const char *pattern, int len_p, va_list list);
void app_flags(const char *, int, char *, int *, int, int);
int app_precision(const char *pattern, int len_p, char *buffer, int pr);
int app_width(char *buffer, int len_b, int wi);
int app_hash(const char *pattern, int len_p, char *buffer);
int app_plus_space(const char *pattern, int len_p, char *buffer);
int check_flag(const char *pattern, int len_p, char flag);
#endif

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list arguments, char *buf, unsigned int ibuf);
int print_str(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int print_bnr(va_list arguments, char *buf, unsigned int ibuf);
int print_unt(va_list arguments, char *buf, unsigned int ibuf);
int print_oct(va_list arguments, char *buf, unsigned int ibuf);
int print_hex(va_list arguments, char *buf, unsigned int ibuf);
int print_upx(va_list arguments, char *buf, unsigned int ibuf);
int print_usr(va_list arguments, char *buf, unsigned int ibuf);
int print_add(va_list arguments, char *buf, unsigned int ibuf);
int print_rev(va_list arguments, char *buf, unsigned int ibuf);
int print_rot(va_list arguments, char *buf, unsigned int ibuf);
int prinlint(va_list arguments, char *buf, unsigned int ibuf);
int prinlunt(va_list arguments, char *buf, unsigned int ibuf);
int prinloct(va_list arguments, char *buf, unsigned int ibuf);
int prinlhex(va_list arguments, char *buf, unsigned int ibuf);
int prinlupx(va_list arguments, char *buf, unsigned int ibuf);
int prinhint(va_list arguments, char *buf, unsigned int ibuf);
int prinhunt(va_list arguments, char *buf, unsigned int ibuf);
int prinhoct(va_list arguments, char *buf, unsigned int ibuf);
int prinhhex(va_list arguments, char *buf, unsigned int ibuf);
int prinhupx(va_list arguments, char *buf, unsigned int ibuf);
int prinpint(va_list arguments, char *buf, unsigned int ibuf);
int prinnoct(va_list arguments, char *buf, unsigned int ibuf);
int prinnhex(va_list arguments, char *buf, unsigned int ibuf);
int prinnupx(va_list arguments, char *buf, unsigned int ibuf);
int prinsint(va_list arguments, char *buf, unsigned int ibuf);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
int print_buf(char *buf, unsigned int nbuf);
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit);
char *fill_oct_array(char *bnr, char *oct);
char *fill_long_oct_array(char *bnr, char *oct);
char *fill_short_oct_array(char *bnr, char *oct);
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit);

#endif
