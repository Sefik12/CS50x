#include <cs50.h>
#include <stdio.h>
// ^Header files^

int main(void)
{
    // Declaring variables.
    int i, j, z;
    int blocksHeight, space;
    // Ask the user for the height of the pyramid, and check for valid input.
    do
    {
        blocksHeight = get_int("Enter height: ");
    }
    while (blocksHeight < 1 || blocksHeight > 8);
    // Declare space variable one digit lower than the height of the pyramid
    // for the pyramid to be printed correctly.
    space = blocksHeight - 1;
    // Use for loops to display the pyramid.
    for (i = 1; i <= blocksHeight; i++)
    {
        for (z = space; z > 0; z--)
            printf(" ");
        for (j = 0; j < i; j++)
            printf("#");
        printf("  ");
        for (j = 0; j < i; j++)
            printf("#");
        printf("\n");
        space--;
    }
}
