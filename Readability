#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
// index = 0.0588 * L - 0.296 * S - 15.8
// L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in the text.
int main(void)
{
    int letters = 0, sentences = 0, words = 1; // Set word to 1, to count the first word.
    string text = get_string("Enter text:  ");
    int textLength = strlen(text); // Make a new variable to assign length of text.

    for (int i = 0; i < textLength; i++)
    {
        letters++;          // Count letters.
        if (text[i] == ' ') // For every space detected, increase amount of words.
        {
            words++;
            letters--; // Substract 1 from letters count for anything other than letters.
        }
        else if (text[i] == ',' || text[i] == '"' || text[i] == '(' || text[i] == ')' ||
                 text[i] == ';' || text[i] == ':' || text[i] == '\'')
            letters--; // Make sure to not count special signs as letters.
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!') // Count sentences.
        {
            sentences++;
            letters--;
        }
    }

    double L = (float) letters / (float) words * 100;   // Calculate L.
    double S = (float) sentences / (float) words * 100; // Calculate S.
    int index = round(0.0588 * L - 0.296 * S - 15.8);   // Calculate index.

    if (index < 1) // Print the results.
        printf("Before Grade 1\n");
    else if (index >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", index);
}
