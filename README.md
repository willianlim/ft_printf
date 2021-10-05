# ft_printf: int   ft_printf(format, ...);

## Table of Contents
1. [Project outline](#Projeto-outline)
2. [Printf Format Placeholder](#Printf-Format-Placeholder)
	- [Printf Format Placeholder Syntax](#Printf-Format-Placeholder-Syntax)
	- [Conversion](#Conversion)
	- [Flags](#step-3-running-root-privileged-commands)
3. [Variable Argument](#Variable-Argument)
	- [What is Variable Argument?](#What-is-Variable-Argument?)
	- [Variadic Function Format](#Variadic-Function-Format)
	- [C Variadic Macros](#C-Variadic-Macros)
4. [Format Specifier Rules](#Format-Specifier-Rules)
	- [Rule summary form](#Rule-summary-form)
	- [](#)
	   - [](#)
	- [](#)
	- [](#)
5. [See diagrams for each format specifier](#See-diagrams-for-each-format-specifier)
	- [General workflow](#General-workflow)
	- [Format Specifier - Char](#Format-Specifier---Char)
	- [Format Specifier - String](#Format-Specifier---String)
	- [Format Specifier - Interger](#Format-Specifier---Interger)
	- [Format Specifier - Pointer](#Format-Specifier---Pointer)
	- [Format Specifier - Unsigned](#Format-Specifier---Unsigned)
6. [Reference](#Reference)
	- [printf](#1-printf)
	- [Variable Argument](#Variable-Argument)
	   - [](#)
	   - [](#)
7. [Tester](#Tester)


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
