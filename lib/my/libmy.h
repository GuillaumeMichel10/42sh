/*
** EPITECH PROJECT, 2023
** my
** File description:
** lib_my
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>

void my_putchar(const char c);
void my_puterr(const char *str);
void my_putstr(char const *str);
void my_put_nbr(int nb);
int my_isneg(int nb);
void my_swap(char *a, char *b);
int my_strlen(char const *str);
int my_isdigit(const char c);
int my_atoi(const char *str);
char *my_strcpy(const char *str);
int my_strcmp(const char *str1, const char *str2);
int my_nbrlen(int nb);
int my_strclen(const char *str, const char *delimiters);
char *my_strccpy(const char *str, const char *delimiters);
char *my_strchr(const char c, const char *delimiters);
int count_words(const char *str, const char *delimiters);
char **my_str_to_word_array(char *str, const char *delimiters, size_t *n);
char *my_concat(int count, ...);
int my_isalpha(char c);
int my_str_isalpha(const char *str);
int my_str_isnum(char const *str);
char *my_strstr(char *str, const char *to_find);
char *my_itoa(int nb);
char *my_str_replace(char *input, char *replace, char *to_find);
int my_strncmp(const char *str1, const char *str2, const int n);
