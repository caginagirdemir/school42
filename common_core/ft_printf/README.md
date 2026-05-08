# ft_printf 

%s string

%c char

%p address

%d decimal

%i integer

%x hexdecimal lowercase

%X hexdecimal uppercase 

%% % character

from va_arg.h library

| Function  | Explanation |
| ------------- | ------------- |
| va_start | enables access to variadic function arguments |
| va_arg | accesses the next variadic function argument |
| va_copy | makes a copy of the variadic function arguments |
| va_end | ends traversal of the variadic function argumenst |
| va_list(type) | holds the information needed by va_start, va_arg, va_end, and va_copy |

<details>
  <summary>Project Instructions</summary>

**Project Objectives** : to understand va_arg structure and when are they used. to understand to handle string, hex and decimal variables and how to use them with write command. to understand basics of printf command. 

| Specs  | Explanation |
| ------------- | ------------- |
| Program name | libftprintf.a |
| Turn in files | Makefile, *.h, */*.h, *.c, */*.c |
| Makefile | NAME, all, clean, fclean, re |
| External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end |
| Libft authorized | Yes |
| Description | Write a library that contains ft_printf(), a function that will mimic the original printf() |
  
  You have to recode the printf() function from libc.

  The prototype of ft_printf() is:

  ```
  int  ft_printf(const char *, ...);
  ```

  Here are the requirements:
  - Don't implement the buffer management of the original printf().
  - Your function has to handle the following conversions: cspdiuxX%
  - Your function will be compared against the original printf().
  - You must use the command ar to create your library. <br/> Using the libtool command is forbidden.
  - Your libftprintf.a has to be created at the root of your repository.

</details>
