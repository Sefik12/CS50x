#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask the user for their name.
    string answer = get_string("What's your name? ");
    // Print the user's name, with the message hello.
    printf("hello, %s\n", answer);
}
