/*
** EPITECH PROJECT, 2023
** src
** File description:
** mysh
*/

#pragma once

#include "include.h"

#include "../src/command/command.h"
#include "../src/environment/env.h"
#include "../src/builtin/builtin.h"
#include "../src/redirect/redirect.h"
#include "../src/utils/utils.h"

typedef enum error_e{
    ERR_OK = 0,
    ERR_CMD_NOT_FOUND,
    ERR_PERM_DENIED,
    ERR_NULL_CMD,
    ERR_AMBIG_OUT_REDIRECT,
    ERR_AMBIG_IN_REDIRECT,
    ERR_MISSING_NAME_FOR_REDIRECT,
    ERR_TOO_MANY_OPEN_PARENS,
    ERR_TOO_MANY_CLOSE_PARENS,
    ERR_BADLY_PLACED_PARENS,
    ERR_CMD_LINE_TOO_LONG,
    ERR_ILLEGAL_VAR_NAME,
    ERR_CMD_ARG_SYNTAX_ERROR,
    ERR_ALIAS_LOOP_DETECTED,
    ERR_ILLEGAL_VAR_REFERENCE,
    ERR_HISTORY_EXPANSION_ERROR,
    ERR_EXPR_SYNTAX_ERROR,
    ERR_BADLY_FORMED_NUMBER,
    ERR_BADLY_FORMED_GLOB,
    ERR_NO_MATCH,
    ERR_UNTERMINATED_QUOTED_STRING,
    ERR_UNEXPECTED_EOF,
    ERR_UNDEFINED_VARIABLE,
    ERR_NO_HOME_DIRECTORY,
    ERR_NOT_A_DIRECTORY,
    ERR_NO_SUCH_FILE_OR_DIRECTORY,
    ERR_VARIABLE_NAME_BEGIN_WITH_LETTER,
    ERR_VARIABLE_NAME_CONTAIN_ALPHANUMERIC_CHARS,
    ERR_TOO_MANY_ARGUMENTS,
    ERR_TOO_FEW_ARGUMENTS,
    NUM_ERRORS // Always last, used to count the number of errors
} error_m;

typedef struct mysh_s {
    env_list_t *env_list;
    char **env;
    char *oldpwd;
    char *home;
    char **path;
    int error;
    bool exit;
}mysh_t;

mysh_t *setup(char **env);
void loop(mysh_t *mysh);
