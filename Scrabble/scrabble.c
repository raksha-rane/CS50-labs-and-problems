#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int get_index(char c);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!...\n");
    }

    else if (score2 > score1)
    {
        printf("Player 2 wins!...\n");
    }

    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int total_score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i];

        if (isalpha(c))
        {
            total_score += POINTS[get_index(c)];
        }
    }

    return total_score;
}

// this function will help to figure out the point of each letter
int get_index(char c)
{
    return tolower(c) - 'a';
    //as the index of every element in the POINTS array is equal to the difference between the ASCII code of that character and ASCII code of 'a' i.e. 97.
}
