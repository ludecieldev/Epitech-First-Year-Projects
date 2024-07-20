/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** macros.h
*/

#ifndef MACROS_H
    #define MACROS_H
    #define P1_VOID 0
    #define P1_REG 0b01000000
    #define P1_DIR 0b10000000
    #define P1_IND 0b11000000
    #define P2_VOID 0
    #define P2_REG 0b00010000
    #define P2_DIR 0b00100000
    #define P2_IND 0b00110000
    #define P3_VOID 0
    #define P3_REG 0b00000100
    #define P3_DIR 0b00001000
    #define P3_IND 0b00001100
    #define REG_T 1
    #define DIR_T 2
    #define IND_T 3
    #define IS_2BYTES_DIR(x) x == 15 || x == 14 || (x < 13 && x > 8)
    #define IS_4BYTES_DIR(x) !(IS_2BYTES_DIR(x))
    #define HAS_SPEC(x) x != 1 && x != 9 && x != 12 && x != 15
    #define SIZE_DIR(x) (2 * (IS_2BYTES_DIR(x)) + 4 * (IS_4BYTES_DIR(x)))
    #define PARAM_SIZE(x) (2 * (x == T_DIR2) + 1 * (x == T_REG) + 2 * \
        (x == T_IND) + 4 * (x == T_DIR))

#endif
