#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define FL_MINUS 1
#define FL_PLUS 2
#define FL_ZERO 4
#define FL_HASH 8
#define FL_SPACE 16

/* SIZES */
#define SI_LONG 2
#define SI_SHORT 1

/**
 * struct f - Struct op
 *
 * @f: The format.
 * @fa: The function associated.
 */
struct f
{
	char f;
	int (*fa)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct f f_t - Struct op
 *
 * @f: The format.
 * @f_t: The function associated.
 */
typedef struct f f_t;

int _printf(const char *format, ...);
int handle_print1(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_ch(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_per(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int1(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsign(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper1(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable1(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer1(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags1(const char *format, int *i);
int get_width1(const char *format, int *i, va_list list);
int get_precision1(const char *format, int *i, va_list list);
int get_size1(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse1(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_ch(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_num1(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num2(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer1(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd1(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable1(char);
int append_hexa_code1(char, char[], int);
int is_digit1(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsgnd1(unsigned long int num, int size);

#endif /* MAIN_H */

