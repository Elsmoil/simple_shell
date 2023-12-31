#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @nex: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *nex;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@er_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fnam: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_chang: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 *@comm: command
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int er_num;
	int linecount_flag;
	char *fnam;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_chang;
	char *comm;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/*execute function*/
void execute(char *comm);

/* atoi.c */
int interactive(info_ *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int _strlen(char *str);
/* shloop.c */
int hsh(info_ *, char **);
int find_builtin(info_ *);
void find_cmd(info_ *);
void fork_cmd(info_ *);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* parser.c */
int is_cmd(info_ *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_ *, char *, char *);

int loophsh(char **);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _erratoi(char *);
void print_error(info_ *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* cmd.c */
int _cd(info_ *);
int _help(info_ *);

/* built.c */
int _exit(info_ *);
int _cd(info_ *);
int _help(info_ *);

/* environ.c */
char *_getenv(info_ *, const char *);
int _env(info_ *);
int _setenv(info_ *);
int _unsetenv(info_ *);
int populate_env_list(info_ *);

/* getenv.c */
char **get_environ(info_ *);
int _unsetenv(info_ *, char *);
int _setenv(info_ *, char *, char *);

/* mems.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realoc(void *, unsigned int, unsigned int);
int pfre(void **);

/* token.c */
char **strto(char *, char *);
char **strto2(char *, char);

/* exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

#endif
