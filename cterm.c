#include <stdio.h>
#include <string.h>

#define MAX_ARG_LENGTH 128
#define MAX_ARG_COUNT 16

int choose_color(char *color);
int set_color(char *color);
void print_invalid();
void print_manual();

int main(int argc, char **argv) {
    // Checking for argument counts
    if (argc < 2 || argc > MAX_ARG_COUNT) {
        print_invalid();
        // Using 1 to symbolize an invalid call to the program
        return -1;
    }

    // Checking for argument lengths
    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) > MAX_ARG_LENGTH) {
            print_invalid();
            return -1;
        }
    }

    if (argc == 2 && ((strcmp(argv[1], "-h") == 0) || strcmp(argv[1], "--help") == 0)) {
        // Case of getting user manual
        print_manual();
        return 0;
    } else if (argc == 2) {
        // Changing color of terminal for the session
        if (set_color(argv[1])) {
            print_invalid();
            return -1;
        };

        return 0;
    } else {
        if (set_color(argv[1])) {
            print_invalid();
            return -1;
        };

        for (int i = 2; i < argc; i++) {
            printf("%s", argv[i]);
            if (i == argc - 1) {
                printf("\n");
            } else {
                printf(" ");
            }
        }

        // Reset the color afterwards
        set_color("-R");
    }

    return 0;
}

/* Helper function used to output an integer to signal
*  the color to change to
*/
int choose_color(char *color) {
    if (strcmp(color, "-b") == 0 || strcmp(color, "--black") == 0) {
        return 1;
    } else if (strcmp(color, "-r") == 0 || strcmp(color, "--red") == 0) {
        return 2;
    } else if (strcmp(color, "-g") == 0 || strcmp(color, "--green") == 0) {
        return 3;
    } else if (strcmp(color, "-y") == 0 || strcmp(color, "--yellow") == 0) {
        return 4;
    } else if (strcmp(color, "-B") == 0 || strcmp(color, "--blue") == 0) {
        return 5;
    } else if (strcmp(color, "-m") == 0 || strcmp(color, "--magenta") == 0) {
        return 6;
    } else if (strcmp(color, "-c") == 0 || strcmp(color, "--cyan") == 0) {
        return 7;
    } else if (strcmp(color, "-w") == 0 || strcmp(color, "--white") == 0) {
        return 8;
    } else if (strcmp(color, "-R") == 0 || strcmp(color, "--reset") == 0) {
        return 9;
    }

    return -1;
}

/* Helper function used to output the color change symbol
* Outputs -1 if the input color is invalid, 0 otherwise
*/
int set_color(char *color) {
    switch (choose_color(color)) {
        case -1:
            return -1;

        // Resetting the color first before changing again
        // It doesn't overwrite the previous color that we had
        printf("\033[1;0m");

        case 1:
            printf("\033[1;30m");
            break;
        case 2: 
            printf("\033[1;31m");
            break;
        case 3: 
            printf("\033[1;32m");
            break;
        case 4: 
            printf("\033[1;33m");
            break;
        case 5: 
            printf("\033[1;34m");
            break;
        case 6: 
            printf("\033[1;35m");
            break;
        case 7: 
            printf("\033[1;36m");
            break;
        case 8: 
            printf("\033[1;37m");
            break;
        case 9:
            printf("\033[1;0m");
            break;
    }

    return 0;
}

/* The message to be printed when a call to the program is invalid
*/
void print_invalid() {
    printf("ct: Invalid Usage\n");
    printf("Try 'ct --help' for more information.\n");
}

/* The message to be printed when we need the manual
*/
void print_manual() {
    printf("Usage: ct <OPTION> [ARGUMENTS]...\n");
    printf("Changes the current terminal session's output font color as specified\n");
    printf("Or print out a specific line with a specific color\n");

    printf("\nList of options:\n");
    printf("  -b, --black\tchanges color to Black\n");
    printf("  -r, --red\tchanges color to Red\n");
    printf("  -g, --green\tchanges color to Green\n");
    printf("  -y, --yellow\tchanges color to Yellow\n");
    printf("  -B, --blue\tchanges color to Blue\n");
    printf("  -m, --magenta\tchanges color to Magenta\n");
    printf("  -c, --cyan\tchanges color to Cyan\n");
    printf("  -w, --white\tchanges color to White\n");

    printf("\n  -R, --reset\tchanges color to the default color\n");

    printf("\nOne can also provide arguments to display the words in [ARGUMENTS] in a specific color\n");
    printf("Example\n");
    printf("ct -r I am red\n");

    printf("\nLimitations:\n");
    printf("You can only provide up to 16 total arguments\n");
    printf("Each argument can only length up to 128 characters\n");
}