#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void split_file(const char *filename, const char *separator) 
{
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) 
    {
        return;
    }

    char line[MAX_LINE_LENGTH];
    int part_number = 1;
    char output_filename[256];
    FILE *output_file = NULL;
    int inside_part = 0;

    while (fgets(line, sizeof(line), input_file)) 
    {

        line[strcspn(line, "\n")] = 0;


        if (strcmp(line, separator) == 0) 
        {
            if (inside_part) 
            {

                if (output_file != NULL) 
                {
                    fclose(output_file);
                    output_file = NULL;
                }
                inside_part = 0;
            } else 
            {

                inside_part = 1;
                snprintf(output_filename, sizeof(output_filename), "%s.part%d", filename, part_number++);
                output_file = fopen(output_filename, "w");
                if (output_file == NULL) 
                {
                    return;
                }
            }
        } else 
        {

            if (inside_part && output_file != NULL) 
            {
                fputs(line, output_file);
                fputs("\n", output_file);
            }
        }
    }

    if (output_file != NULL) 
    {
        fclose(output_file);
    }

    fclose(input_file);
}

int main(int argc, char *argv[]) 
{
    if (argc != 5) 
    {
        return 1;
    }

    const char *filename = NULL;
    const char *separator = NULL;

    for (int i = 1; i < argc; i += 2) 
    {
        if (strcmp(argv[i], "-f") == 0) 
        {
            filename = argv[i + 1];
        } else if (strcmp(argv[i], "-s") == 0) 
        {
            separator = argv[i + 1];
        } else 
        {
            return 1;
        }
    }

    if (filename == NULL || separator == NULL)
    {
        return 1;
    }

    split_file(filename, separator);

    return 0;
}