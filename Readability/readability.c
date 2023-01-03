#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int get_index(string text);

int main()
{
    // taking user input
    string text = get_string("Text: ");

    // introducing a function to get index
    int index = get_index(text);

    // assigning appropriate outputs to indexes



    return 0;



}

// defining the get_index function here :
int get_index(string text)
{
    int letters = 0, words = 0, sentences = 0;

    // for counting letters, words and sentences one by one :

    for (int i = 0; i < strlen(text); i++)
    {
        char ch = text[i];

        // letters
        if (isalpha(ch))
        {
            letters++;
        }

        // words
        if (isspace(ch))
        {
            words++;
        }

        // sentences
        if (ch == '.' || ch == '!' || ch == '?')
        {
            sentences++;
        }

    }
    words++;  // to make sure that even the last word is counted (before punctuations)

    // to return index value, basically defining the variable 'index'

    float L = (letters * 100.0f) / words ;     // L = average number of letters per 100 words
    float S = (sentences * 100.0f) / words ;   // S = average number of sentences per 100 words

    return round (0.0588 * L - 0.296 * S - 15.8);   // using round from math library to get an integer nearest to the solution


}

