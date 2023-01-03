#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> // for using atoi function

bool is_valid(string s);
void encrypt(string plaintext, string ciphertext, int k);

int main(int argc, string argv[]) // declaring the command-line argument
{
    if (argc != 2 || !is_valid(argv[1]))
    {
        printf("Usage: ./caesar key\n");    // prompting error
        return 1; // false
    }
    int k = atoi(argv[1]);
    string s = get_string("plaintext: ");    // getting the user input for encryption
    
    int n = strlen(s);
    char ciphertext[n + 1];         // we add 1 because strlen does not include the \0 character in the end of the string
    
    encrypt(s, ciphertext, k);     // defining function
    
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

void encrypt(string plaintext, string ciphertext, int k)   // this function enciphers the plaintext into ciphertext!
{   
    int i = 0;
    for (i = 0; i < strlen(plaintext); i++)
    {
        char ch = plaintext[i];
        
        if (isalpha(ch))
        {
            char temp = tolower(ch);   // creating a temporary variable for storing the lower case character
            
            int pi = temp - 'a';                // pi = i-th character of plaintext
            char ci = ((pi + k) % 26) + 'a';    // ci = i-th character of ciphertext
            
            ciphertext[i] = islower(ch) ? ci : toupper(ci);  // i used the conditional operator to avoid longer codes
        }
        else 
        {
            ciphertext[i] = ch;
        }
        
    }
    
    ciphertext[i] = '\0'; 
}

bool is_valid(string s)     // to check if the command-line (KEY) is valid or not
{
   
    for (int i = 0; i < strlen(s); i++)
    {
        char ch = s[i];
        if (!isdigit(ch))  // key should be a non-negative integer only
        {
            return false;
        }
    }
    return true;
}
