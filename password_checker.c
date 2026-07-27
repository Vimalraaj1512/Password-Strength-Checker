#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];

    int upper = 0, lower = 0;
    int digit = 0, special = 0;

    printf("====================================\n");
    printf("     PASSWORD STRENGTH CHECKER\n");
    printf("====================================\n");

    printf("Enter Password: ");
    scanf("%s", password);

    int length = strlen(password);

    for(int i = 0; i < length; i++)
    {
        if(isupper(password[i]))
            upper = 1;

        else if(islower(password[i]))
            lower = 1;

        else if(isdigit(password[i]))
            digit = 1;

        else
            special = 1;
    }

    printf("\nPassword Analysis\n");
    printf("-------------------------\n");

    if(length >= 8)
        printf("✔ Length        : Good\n");
    else
        printf("✘ Length        : Minimum 8 characters required\n");

    if(upper)
        printf("✔ Uppercase     : Present\n");
    else
        printf("✘ Uppercase     : Missing\n");

    if(lower)
        printf("✔ Lowercase     : Present\n");
    else
        printf("✘ Lowercase     : Missing\n");

    if(digit)
        printf("✔ Number        : Present\n");
    else
        printf("✘ Number        : Missing\n");

    if(special)
        printf("✔ Special Char  : Present\n");
    else
        printf("✘ Special Char  : Missing\n");

    if(length >= 8 && upper && lower && digit && special)
        printf("\nResult : STRONG PASSWORD\n");

    else if(length >= 6 && ((upper + lower + digit + special) >= 3))
        printf("\nResult : MEDIUM PASSWORD\n");

    else
        printf("\nResult : WEAK PASSWORD\n");

    return 0;
}