#ifndef getTime_H_INCLUDED
#define getTime_H_INCLUDED

#include <conio.h>   // C standard Console Input/Output library
#include <stdio.h>   // C standard IO library
#include <stdlib.h>  // standard library
#include <string.h>  // string manipulation utility
#include <time.h> 
void manageProduct();
void addProduct();
void restock();
void displayAllProduct();
struct Product findProduct(int);
void updateProduct(int, int);
char* getDate();
char* getTime();
char* getYear();
char* getMonth();
char* getDay();
#endif 
