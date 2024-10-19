#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare all variables.
    int digit, inc, totalSum, firstDigit, secondDigit, extraDigit;
    int sum1 = 0, sum2 = 0, digits = 0;
    // Declare a long variable and ask for the card number.
    long creditNum = get_long("Enter your credit card number: ");

    // Add all the digits into the right sums, also find first and second digit.
    while (creditNum > 0)
    {
        inc = 0;
        digit = creditNum % 10;
        secondDigit = digit;
        sum1 += digit;
        creditNum = creditNum / 10;
        digits++;

        if (creditNum > 0)
        {
            digit = creditNum % 10;
            extraDigit = digit;
            firstDigit = digit;
            digit = digit * 2;
            if (digit >= 10)
            {
                inc = digit % 10;
                digit = 1;
            }
            sum2 += digit;
            sum2 += inc;
            digits++;
            creditNum = creditNum / 10;
        }
        else
        {
            firstDigit = secondDigit;
            secondDigit = extraDigit;
        }
    }

    // Add the sums.
    totalSum = sum1 + sum2;

    // Check if the card is valid and which company it's from.
    if (totalSum % 10 == 0)
    {
        if (digits == 15 && firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
        {
            printf("AMEX\n");
        }
        else if (firstDigit == 4 && (digits == 13 || digits == 16))
        {
            printf("VISA\n");
        }
        else if (firstDigit == 5 && secondDigit >= 1 && secondDigit <= 5 && digits == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
