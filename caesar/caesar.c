#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Takes input in the terminal.
int main(int argc, string argv[])
{
    // Input validation. Check if too many arguments are entered.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Stores the entered number in the terminal into a string.
    string keyString = argv[1];
    int key = 0;

    // Loop once for every digit in the string.
    for (int z = 0, num = strlen(keyString); z < num; z++)
    {
        // Input validation. Check if the argument is a number.
        if (keyString[z] > 57 || keyString[z] < 48)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        // Convert the string of digits to an int.
        key *= 10;
        key += keyString[z] - 48;
    }

    // Input validation. Check if the input is a positive number.
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string code = get_string("plaintext:  ");

    // Run for every character in the user's plaintext.
    for (int i = 0, l = strlen(code); i < l; i++)
    {
        // Cipher only the letters.
        if (!(code[i] < 65 || (code[i] > 90 && code[i] < 97) || code[i] > 122))
        {
            // Cipher.
            for (int j = 0; j < key; j++)
            {
                code[i]++;

                // Looping back to 'A'/'a' when 'Z'/'z' is passed.
                if (code[i] == 91 || code[i] == 123)
                    code[i] = code[i] - 26;
            }
        }
    }

    // Print ciphered text.
    printf("ciphertext: %s\n", code);
}
