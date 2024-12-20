#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>

int main() {
    char Input[100];
    char stack[100];
    int Top = -1;

    std::cout << "Enter string to be validated (a, b, with 'c' as separator):\n";
    fgets(Input, sizeof(Input), stdin);

   
    size_t len = strlen(Input);
    if (Input[len - 1] == '\n') Input[len - 1] = '\0';

    stack[++Top] = 'Z'; 
    int i = -1;

q0: 
    i++;
    if ((Input[i] == 'a' || Input[i] == 'b') && stack[Top] == 'Z') {
        stack[++Top] = Input[i];
        goto q0;
    } else if ((Input[i] == 'a' || Input[i] == 'b') && (stack[Top] == 'a' || stack[Top] == 'b')) {
        stack[++Top] = Input[i];
        goto q0;
    } else if (Input[i] == 'c' && (stack[Top] == 'a' || stack[Top] == 'b')) {
        goto q1;
    } else {
        goto Invalid;
    }

q1: 
    i++;
    if (Input[i] == 'a' && stack[Top] == 'a') {
        Top--;
        goto q1;
    } else if (Input[i] == 'b' && stack[Top] == 'b') {
        Top--;
        goto q1;
    } else if (Input[i] == '\0' && stack[Top] == 'Z') {
        goto Valid;
    } else {
        goto Invalid;
    }

Valid: 
    std::cout << "\nOutput: Valid String";
    goto exit;

Invalid: 
    std::cout << "\nOutput: Invalid String";
    goto exit;

exit:
    getch();
    return 0;
}

