#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAPE_SIZE 100

// Define tape symbols
typedef enum {
    BLANK,
    ZERO,
    ONE,
    MARK
} Symbol;

// Define states
typedef enum {
    START,
    Q1,
    Q2,
    ACCEPT,
    REJECT
} State;

// Function to simulate Turing Machine for 0^n 1^n
void simulate_turing_machine(Symbol *tape) {
    int head = 0; // Initial head position
    State state = START;

    while (state != ACCEPT && state != REJECT) {
        switch (state) {
            case START:
                if (tape[head] == ZERO) {
                    tape[head] = MARK;
                    state = Q1;
                    head++;
                } else if (tape[head] == BLANK) {
                    state = ACCEPT; // Accept empty string
                } else {
                    state = REJECT;
                }
                break;

            case Q1:
                if (tape[head] == ZERO) {
                    tape[head] = MARK;
                    head++;
                    state = Q1;
                } else if (tape[head] == ONE) {
                    state = Q2;
                    head++;
                } else {
                    state = REJECT;
                }
                break;

            case Q2:
                if (tape[head] == ONE) {
                    tape[head] = MARK;
                    head++;
                    state = Q2;
                } else if (tape[head] == BLANK) {
                    state = ACCEPT;
                } else {
                    state = REJECT;
                }
                break;
        }
    }

    if (state == ACCEPT) {
        printf("Accepted!\n");
    } else {
        printf("Rejected!\n");
    }
}

int main() {
    Symbol tape[MAX_TAPE_SIZE];
    char input[MAX_TAPE_SIZE];

    printf("Enter input string: ");
    scanf("%s", input);

    // Convert input string to Symbol array
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '0') {
            tape[i] = ZERO;
        } else if (input[i] == '1') {
            tape[i] = ONE;
        } else {
            printf("Invalid input!\n");
            return 1;
        }
    }

    simulate_turing_machine(tape);

    return 0;
}
