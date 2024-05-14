//
// Created by jlibyvali on 24-5-14.
//

#ifndef C_FROMK_R_PRAC6_H
#define C_FROMK_R_PRAC6_H

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


// Prac6-2

struct key{
    char *word;
    int cnt;
};

struct key* binsearch(char *,struct key*,int );




// Prac 6 - 4
struct tnode{
    char *word;
    int cnt;

    struct tnode* left;
    struct tnode* right;
};


struct tnode* addTree(struct tnode*, char *);
void treeprint(struct tnode*);
int getword(char *,int );








///////////////////////Prac6-2

struct key*
binsearch(char *word,struct key* tab ,int n){

    int cond;
    struct key* low = &tab[0];
    struct key* high = &tab[n];
    struct key* mid;

    while (low < high){ // yes it's two pointer
        mid  = low + (high - low) / 2;  // two same array pointer can subtraction, calculate the length and divided 2.

        if((cond = strcmp(word,mid->word)) < 0 )
            high = mid;
        else if (cond > 0)
            low = ++mid;
        else
            return mid;
    }

    return NULL;
}








#endif //C_FROMK_R_PRAC6_H
