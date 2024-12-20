#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;

    printf("Enter a string: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (state == 0 && input[i] == 'a') state = 1;
        else if (state == 0 && input[i] == 'b') state = 2;
        else if (state == 1 && input[i] == 'a') state = 0;
        else if (state == 1 && input[i] == 'b') state = 3;
        else if (state == 2 && input[i] == 'a') state = 3;
        else if (state == 2 && input[i] == 'b') state = 0;
        else if (state == 3 && input[i] == 'a') state = 2;
        else if (state == 3 && input[i] == 'b') state = 1;
    }

    if (state == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}

