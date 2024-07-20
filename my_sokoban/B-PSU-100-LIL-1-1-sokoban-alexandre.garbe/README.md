# my_sokoban : Epitech Project

The main goal of this project was to recreate the sokoban game (warehouse keeper in Japanese) using the ncurses library.

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

The map is not necessary square, it might have different shapes closed by a wall
Only usable characters : 
- '#' : Walls
- 'P' : Player (only one)
- 'X' : Boxes
- 'O' : Storage (must match the number of Boxes)
- ' ' : Spaces
- '\n' : Backlines

Since you can't generate a map with the program get yourself one !

Here is two map examples : 

```
############
#        O #
#   P   ####
#          #
#          #
#######    #
#  O ##    #
#    ##    #
#          #
#      XX  #
#      #   #
############
```
```
############
#   O    O #     #########
#     ######     #    X O#
#          #     #  X    #
#     #    ##### #  X    #
#######        ###     X #
#  O ##    ##   X  OOO X #
#  # ##    ##  ### OPO X #
#          #   # #########
# X#    XX #####
#     O #  #
############
```
