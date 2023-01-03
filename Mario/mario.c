#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        // take user input
        n = get_int("Height: ");

    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++ )
    {
        // blankspaces
        for (int j = n - 1; j > i; j--)

            printf(" ");


        // hashes #
        for (int j = 0; j <= i; j++)

            printf("#");


       printf("\n");

    }



}
