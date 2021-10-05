# ft_printf: int   ft_printf(format, ...);

## Table of Contents
- [ft_printf: int   ft_printf(format, ...);](#ft_printf-int---ft_printfformat-)
	- [Table of Contents](#table-of-contents)
	- [Project outline](#project-outline)
	- [Printf Format Placeholder](#printf-format-placeholder)
		- [Printf Format Placeholder Syntax](#printf-format-placeholder-syntax)
		- [Conversion](#conversion)
		- [Flags](#flags)
		- [Variable Argument](#variable-argument)
			- [What is Variable Argument?](#what-is-variable-argument)
			- [Variadic Function Format](#variadic-function-format)
			- [C Variadic Macros](#c-variadic-macros)
		- [Code of Willian](#code-of-willian)
		- [Reference](#reference)
		- [Tester](#tester)


## Project outline
This project is to directly implement some functions of the printf function included in the stdio.h basic library .
The f in printf stands for formatted , meaning that formatted output is supported.
printf from many fields of the flag of the field - , 0 ,   . , * and only the width and .precision fields, c , s , p , d , i , u , x , X , % of the type field need to be implemented.
It is implemented while comparing it with the actual printf function.

## Printf Format Placeholder

### Printf Format Placeholder Syntax

printf function Format Placeholder Syntax (syntax notation format) is % beginning with the formatting tags are referred to as its syntax is as follows:

%[parameter][flags][width][.precision][length]type

The format specifier that appears after % is a form that receives various options for fields such as parameter and flags and receives a type . See the description of the options for the fields below.

### Conversion

| Conversion | Type of argument | Effect |
|:----------:|:----------------:|:------:|
| d / i | int | Prints an int in decimal form |
| u | unsigned int | Prints an unsigned int in decimal form |
| x | unsigned int | Prints an int in hexadecimal form (lowercase) |
| X | unsigned int | Prints an int in hexadecimal form (uppercase) |
| c | char | Prints a char |
| s | char * | Prints a string |
| p | void * | Prints a pointer's address |

### Flags

| Flag | Effect |
|:----:|:------:|
| - | Left-justify within the field width |
| + | Forces positive numbers to be preceded with a '+' sign |
| ' ' (space) | If no sign is going to be written, a blank space is inserted before the value |
| # | o, x and X conversions are preceded with 0, 0x or 0X respectively |
| 0 | Pads with zeros instead of the default spaces

### Variable Argument

#### What is Variable Argument?

#### Variadic Function Format

#### C Variadic Macros

### Code of Willian

- [`Makefile`](Makefile)
- [`libft functions`](libft/)
- [`header file`](includes/ft_printf.h)

Main functions

- [`ft_printf.c`](source/ft_printf.c)
- [`ft_fill.c`](source/ft_fill.c)
- [`ft_placeholder.c`](source/ft_placeholder.c)
- [`reset_option.c`](source/reset_option.c)

Conversion functions

- [`screen_c.c`](source/screen_c.c)
- [`screen_d.c`](source/screen_d.c)
- [`screen_p.c`](source/screen_p.c)
- [`screen_percent.c`](source/screen_percent.c)
- [`screen_s.c`](source/screen_s.c)
- [`screen_u.c`](source/screen_u.c)
- [`screen_x.c`](source/screen_x.c)

### Reference
<h4>printf</h4>

[Format specification syntax](https://docs.microsoft.com/pt-br/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160)

[printf](http://www.cplusplus.com/reference/cstdio/printf/)

[What's the difference btween %i and]

<h4>Variable Argument</h4>

[va_arg, va_copy, va_end, va_start](https://docs.microsoft.com/pt-br/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-160)

[What is the format of the va_list structure?](https://stackoverflow.com/questions/4958384/what-is-the-format-of-the-x86-64-va-list-structure)

[System V Application Binary Interface](https://web.archive.org/web/20160801075139/http://www.x86-64.org/documentation/abi.pdf)

[python tutor](https://pythontutor.com/visualize.html#mode=edit)

### Tester
[ft_printf tester Paulo](https://github.com/paulo-santana/ft_printf_tester)

[ft_printf tester Tripouille](https://github.com/Tripouille/printfTester)
