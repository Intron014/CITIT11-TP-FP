#include <stdio.h>
#include <string.h>
#define MAX_LINE_LEN 1024


int count_words(FILE *file) {
    int word_count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c != ' ' && c != '\n') {
            word_count++;

            while ((c = fgetc(file)) != EOF && c != ' ' && c != '\n') {}
        }
    }

    return word_count;
}

char largest_line(FILE *file) {
    char line[MAX_LINE_LEN] = "";
    int max_words = 0;
    char longest_line[MAX_LINE_LEN] = "";

    while (fgets(line, MAX_LINE_LEN, file)) {
        int words = 0;
        for (int i = 0; i <= strlen(line); i++) {
            if (line[i] == ' ' || line[i] == '\n') {
                words++;
            }
        }
        if (words > max_words) {
            max_words = words;
            strcpy(longest_line, line);
        }
    }
    printf("Line with the most words: %s\n", longest_line);
}
void remove_chars(FILE *infile, char *outfile_name, char *chars) {
    FILE *outfile = fopen(outfile_name, "w");
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, infile)) {
        char buffer[MAX_LINE_LEN];
        int buffer_index = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (strchr(chars, line[i]) == NULL) {
                buffer[buffer_index] = line[i];
                buffer_index++;
            }
        }

        buffer[buffer_index] = '\n';
        buffer_index++;

        fwrite(buffer, sizeof(char), buffer_index, outfile);
    }

    fclose(outfile);
}


    int main(){
    int word_count;
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Error: The file couldn't be opened.\n");
        return 1;
    }
    word_count=count_words(file);
    printf("The file contains %d words\n", word_count);
    rewind(file);
    largest_line(file);
    rewind(file);
    remove_chars(file, "salida.txt", "abc");
    fclose(file);
}


