#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Prac 5-7
#define  MAXLINE 1000

int readlines(char *lineptr[], int maxlines);    // read input lines, storage in 'lineptr[lineNum]'
void writelines(char *lineptr[], int nlines);    // output lines
void Qsort(char *v[], int left, int right);    // Quick sort
void swap(char *v[], int i, int j);

int Getline(char *s, int limit);   // read one line once, return length

// Prac 5-10
char *STACK2;
char  *HEAD;

void push2(char c);

void printStack(void);

char pop2(void);

int cal(char *s, int len);

///////////////////////////Prac 5-7
char *alloc(int len) {
    return ((char *) malloc(len));
}

int Getline(char *s, int limit) {

    int c, i;
    i = 0;

    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c; // read in '\n'
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;
    while ((len = Getline(line, MAXLINE)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; //delete new line
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {

    int i;
    printf("Output:\n");
    for (i = 0; i < nlines; i++) {
        printf("%s\n", *lineptr++);
    }

}

void swap(char *v[], int i, int j) {
    char *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}


void Qsort(char *v[], int left, int right) {

    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, right);
    last = left;

    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    swap(v, left, last);
    Qsort(v, left, last - 1);
    Qsort(v, last + 1, right);
}

/////////////////////////Prac 5-10

void push2(char c) {
    *STACK2++ = c;
}

char pop2(void) {
    if (*--STACK2 != '-')
        return (*STACK2);
    else
        return '?';
}

void printStack(void) {
    char *start = HEAD, *cur = STACK2;

    if (*--cur == '-') {
        printf("Stack is empty\n");
    } else {
        while (start != STACK2) {
            printf("%c\n", *start++);
        }
    }
}

int cal(char *s, int len) {
    STACK2 = (char *) malloc(2000 * sizeof(int));
    if (STACK2 == NULL) {
        printf("Malloc failed \n");
        return -1;
    }
    memset(STACK2, '-', 1000* sizeof(char));
    HEAD = STACK2;

    int i, tmp;
    for (i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            push2(s[i]);
            printStack();
        } else {
            switch (s[i]) {
                case '+':
                    push2(((pop2() - '0' )  + (pop2() - '0')) + '0');
                    printStack();
                    break;
                case '-':
                    tmp = pop2();
                    push2(pop2() - tmp);
                    break;
                case '*':
                    push2(((pop2() - '0' ) * (pop2() - '0')) + '0');
                    printStack();
                    break;
                case '/':
                    tmp = pop2();
                    if (tmp != 0) {
                        push2(pop2() / tmp);
                        break;
                    } else {
                        printf("Error: zero divisor\n");
                    }
                    break;
                default:
                    printf("Error: unknown command\n");
                    break;

            }
        }

    }
    int ans = (*--STACK2);
    free(HEAD);

    return ans;
}