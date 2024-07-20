# setting_up : Epitech Project

The main goal of this project was to find the biggest square in a map, generated or directly used as a parameter in the command line.
If ever there are several solutions, the printed square must be the upper left one.
With this program you won't be able to generate one.

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
### How to use it ?

To use this program simply get a map file and execute de program with it. 

The file is valid if it is respecting those constraints:
- its first line contains the number of lines on the board (and only that),
- ‘.’ (representing an empty place) and ‘o’ (representing an obstacle) are the only two characters for the other lines,
- all of the lines are of the same length (except the first one),
- it contains at least one line,
- each line is terminated by ‘\n’.

Since you can't generate a map with the program get yourself one !

Here is one map examples : 

```
5
.o...
o....
..oo.
.o.o.
....o
```
