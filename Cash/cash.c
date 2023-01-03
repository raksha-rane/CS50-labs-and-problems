#include <stdio.h>
#include <cs50.h>
#include <math.h> //  as i will be using the round function from math library

int main(void)

{
    float change;
    int cents;
    int coins;

    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    cents = round(change * 100);
    coins = 0;

    // divide by 25 -- quarters, divide by 10 -- dime, divide by 5 -- nickel, divide by 1 -- cent

    while (cents != 0)
    {
        // for quarters
        coins += cents / 25;
        cents = cents % 25;

        // for dimes
        coins += cents / 10;
        cents %= 10;

        // for nickels
        coins += cents / 5;
        cents %= 5;

        // for cents
        coins += cents / 1;
        cents %= 1;
    }

    printf("%d\n", coins);
}
