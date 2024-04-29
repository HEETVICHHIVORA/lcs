#include <stdio.h>

#include <string.h>


void printLCS(char dir[][7], int i, int j, char *b) {

    if (dir[i][j] == '.') {

        return;

    }


    if (dir[i][j] == '*') {

        printLCS(dir, i - 1, j - 1, b);

        printf("%c ", b[j - 1]);

    }

    if (dir[i][j] == '<') {

        printLCS(dir, i, j - 1, b);

    }

    if (dir[i][j] == '^') {

        printLCS(dir, i - 1, j, b);

    }

}


int main() {

    char a[] = "ABCDEF";

    char b[] = "ABCXYF";


    int n = strlen(a);

    int m = strlen(b);

    int it1 = 0;


    int c[n + 1][m + 1];

    char dir[n + 1][m + 1];


    memset(c, 0, sizeof(c));

    memset(dir, '.', sizeof(dir));


    for (int i = 1; i < n + 1; i++) {

        int it2 = 0;

        for (int j = 1; j < m + 1; j++) {

            if (a[it1] == b[it2]) {

                c[i][j] = c[i - 1][j - 1] + 1;

                dir[i][j] = '*';

            } else if (c[i][j - 1] > c[i - 1][j]) {

                c[i][j] = c[i][j - 1];

                dir[i][j] = '<';

            } else {

                c[i][j] = c[i - 1][j];

                dir[i][j] = '^';

            }

            it2++;

        }

        it1++;

    }


    for (int i = 0; i < n + 1; i++) {

        for (int j = 0; j < m + 1; j++) {

            printf("%d ", c[i][j]);

        }

        printf("\n");

    }

    printf("\n");

    for (int i = 0; i < n + 1; i++) {

        for (int j = 0; j < m + 1; j++) {

            printf("%c ", dir[i][j]);

        }

        printf("\n");

    }


    printf("\nLongest common subsequence :- ");

    printLCS(dir, n, m, b);


    printf("\nSize :- %d\n", c[n][m]);


    return 0;

}

