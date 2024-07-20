# my_ls : Epitech Project

The main goal of this project was to recode de ls POSIX function with -l -a -R -r -d -t flags and error handling.

### Installation

To use this project clone the repository or download it to .zip file format.

## Usage

This project use Makefile so here's a little tutorial : 

To compile and get the binary executable use :
```
make 
```
To clear the repository from .o files use : 
```
make clean 
```
To fully clear the repository from any compiled files, .o and executable use :
```
make fclean
```
To recompile without clearing the repository use :
```
make re 
```
### Modify project

If you ever wonder to modify the projet by adding flags you can find in lib/my/my.h the structure used to it
```
typedef struct flags_s {
    char flag;
    int (*p)(char const *path);
}flags_s_t;
```
To add a flag simply add a line to this structure : 
```
static const flags_s_t flags[] = {
    {.flag = 'a', .p = &flag_a},
    {.flag = 'l', .p = &flag_l},
    {.flag = 'd', .p = &flag_d},
    {.flag = 'r', .p = &flag_r_min},
    {.flag = 'R', .p = &flag_r_maj},
    {.flag = 't', .p = &flag_t}
};
```
.flag is the character trigger to the .p function pointer.

## Additional Documentation and Acknowledgments

* ls documentation : https://man7.org/linux/man-pages/man1/ls.1.html
* ls wikipedia : https://en.wikipedia.org/wiki/Ls
