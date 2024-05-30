#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void split_file(const char *filename, const char *separator) {
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int part_number = 1;
    char output_filename[256];
    FILE *output_file = NULL;
    int inside_part = 0;

    while (fgets(line, sizeof(line), input_file)) {
        // Remove newline character from the end of the line if it exists
        line[strcspn(line, "\n")] = 0;

        // Check if the current line is the separator
        if (strcmp(line, separator) == 0) {
            if (inside_part) {
                // Close the current output file if we are inside a part
                if (output_file != NULL) {
                    fclose(output_file);
                    output_file = NULL;
                }
                inside_part = 0;
            } else {
                // Open a new output file if we are starting a new part
                inside_part = 1;
                snprintf(output_filename, sizeof(output_filename), "%s.part%d", filename, part_number++);
                output_file = fopen(output_filename, "w");
                if (output_file == NULL) {
                    perror("Error opening output file");
                    fclose(input_file);
                    exit(EXIT_FAILURE);
                }
            }
        } else {
            // Write line to the current output file if we are inside a part
            if (inside_part && output_file != NULL) {
                fputs(line, output_file);
                fputs("\n", output_file);
            }
        }
    }

    // Close the last output file if it was open
    if (output_file != NULL) {
        fclose(output_file);
    }

    fclose(input_file);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s -f <filename> -s <separator>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = NULL;
    const char *separator = NULL;

    for (int i = 1; i < argc; i += 2) {
        if (strcmp(argv[i], "-f") == 0) {
            filename = argv[i + 1];
        } else if (strcmp(argv[i], "-s") == 0) {
            separator = argv[i + 1];
        } else {
            fprintf(stderr, "Unknown option %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }

    if (filename == NULL || separator == NULL) {
        fprintf(stderr, "Both filename and separator must be specified\n");
        exit(EXIT_FAILURE);
    }

    split_file(filename, separator);

    return 0;
}