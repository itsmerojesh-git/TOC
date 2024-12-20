#include <stdio.h>
#include <string.h>

void print_prefixes(char str[]) {
    int len = strlen(str);
    printf("\nAll prefixes of '%s':\n", str);
    for (int i = 1; i <= len; i++) {
        printf("First %d characters: ", i);
        for (int j = 0; j < i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void print_suffixes(char str[]) {
    int len = strlen(str);
    printf("\nAll suffixes of '%s':\n", str);
    for (int i = 0; i < len; i++) {
        printf("Last %d characters: ", len - i);
        for (int j = i; j < len; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void print_substrings(char str[]) {
    int len = strlen(str);
    printf("\nAll substrings of '%s':\n", str);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            printf("Substring from position %d to %d: ", i, j-1);
            for (int k = i; k < j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[] = "abcd";
    int choice;
    
    do {
        printf("\nString Operations Menu:\n");
        printf("1. Show all prefixes\n");
        printf("2. Show all suffixes\n");
        printf("3. Show all substrings\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                print_prefixes(str);
                break;
                
            case 2:
                print_suffixes(str);
                break;
                
            case 3:
                print_substrings(str);
                break;
                
            case 4:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    
    return 0;
}
