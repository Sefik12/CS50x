#include <cs50.h>
#include <stdio.h>
#include <string.h>

int checkPoints(string word); // Declare checkPoints function before main, so main can access it.
int main(void)
{
    string p1 = get_string("Player 1: "); // Get the words of the players
    string p2 = get_string("Player 2: ");
    int score1 = checkPoints(p1); // Use the checkPoints function to give the points to the words.
    int score2 = checkPoints(p2);
    if (score1 > score2) // Check and display who the winner is.
        printf("Player 1 wins!\n");
    else if (score2 > score1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}

int checkPoints(string word) // Make checkPoints function that calculates words' points.
{
    string oneP = "AEILNORSTU"; // Input letters, that is worth equal points, to single strings.
    string twoP = "DG";
    string threeP = "BCMP";
    string fourP = "FHVWY";
    string fiveP = "K";
    string eightP = "JX";
    string tenP = "QZ";
    int sum = 0;
    for (int i = 0, I = strlen(word); i < I; i++) // Loop runs through every letter in the word.
    {
        if (word[i] > 96 && word[i] < 123) // Capitalize all letters of the word.
            word[i] = word[i] - 32;
        if (word[i] < 65 || word[i] > 90) // Skip characters that aren't letters.
        {
            continue;
        }
        for (int j = 0, J = strlen(oneP); j < J; j++) // Add points to sum for every letter.
        {
            if (word[i] == oneP[j])
            {
                sum += 1;
            }
        }
        for (int k = 0, K = strlen(twoP); k < K; k++)
        {
            if (word[i] == twoP[k])
            {
                sum += 2;
            }
        }
        for (int o = 0, O = strlen(threeP); o < O; o++)
        {
            if (word[i] == threeP[o])
            {
                sum += 3;
            }
        }
        for (int p = 0, P = strlen(fourP); p < P; p++)
        {
            if (word[i] == fourP[p])
            {
                sum += 4;
            }
        }
        for (int l = 0, L = strlen(fiveP); l < L; l++)
        {
            if (word[i] == fiveP[l])
            {
                sum += 5;
            }
        }
        for (int m = 0, M = strlen(eightP); m < M; m++)
        {
            if (word[i] == eightP[m])
            {
                sum += 8;
            }
        }
        for (int n = 0, N = strlen(tenP); n < N; n++)
        {
            if (word[i] == tenP[n])
            {
                sum += 10;
            }
        }
    }
    return sum; // Returns the sum of points for every letter in the word.
}
