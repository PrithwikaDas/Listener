#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

void ToLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void ProcessInput(const char *input) {
    char lowercaseInput[MAX_INPUT_LENGTH];
    strcpy(lowercaseInput, input);
    ToLowercase(lowercaseInput);

    if (strstr(lowercaseInput, "help") != NULL || strstr(lowercaseInput, "emergency") != NULL) {
        printf("Chatbot: I'm here to help! If you're in immediate danger, please call emergency services.\n");
    } else if (strstr(lowercaseInput, "safe") != NULL || strstr(lowercaseInput, "okay") != NULL) {
        printf("Chatbot: I'm glad to hear that you're safe.\n");
    } else if (strstr(lowercaseInput, "check") != NULL && strstr(lowercaseInput, "safety") != NULL) {
        printf("Chatbot: Remember to stay in well-lit areas and be cautious.\n");
    } else {
        printf("Chatbot: I'm here to assist you with safety-related concerns.\n");
    }
}

int main() {
    printf("Life Assistance Chatbot: Listening...\n");
    printf("You can type your message here. Enter 'quit' to exit.\n");

    while (1) {
        char input[MAX_INPUT_LENGTH];
        printf("You: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            printf("Chatbot: Goodbye!\n");
            break;
        }

        ProcessInput(input);
    }

    return 0;
}
