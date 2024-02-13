#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXBUFFERSIZE         20000000 

char buffer[MAXBUFFERSIZE];


void getAnInput();
int count_letters(char c[]);
int count_words(char c[]);
int count_sentences(char c[]);
void colemanLiau(char c[]);


void getAnInput() {
    char c;
    int char_count ;
    int valid_choice;
    do  {
        valid_choice = 0;
        c = getchar();
        char_count = 0;
        while (c != '\n')   {
            buffer[char_count++] = c;
            c = getchar();
        }
        buffer[char_count] = 0x00;
        valid_choice = 1;
    } while (valid_choice == 0);
    
}

int count_letters(char c[]) {
    int letters = 0;
    for (size_t i = 0; i < strlen(c); i++)  {
        if (isalpha(c[i]))
            letters++; 
    }
    return letters;
}

int count_words(char c[]) {
    int words = 0;
    for (size_t i = 0; c[i] != '\0'; i++)   {
        if ( c[i] == ' ')  {
            words++;
        } 
    }
    return words + 1;
}

int count_sentences(char c[]) {
    int sentences = 0;
    char punct[3] = ".!?";
    for (size_t i = 0; c[i] != '\0'; i++)  {
        for (size_t j = 0; j < 3; j++)  {
             if (c[i] == punct[j])  {
                sentences++;
            }
        }
    }
    return sentences;
}
void colemanLiau(char c[]) {
    int index = (int)round((0.0588 * ( (float)count_letters(c) * 100 / (float)count_words(c)) - 0.296 * ((float)count_sentences(c) * 100 / (float)count_words(c)) - 15.8));
    if (index < 2)  {
        printf("Before Grade 1\n");
    } else if (index > 15)  {
        printf("Grade 16+");
    } else {
        printf("Grade %i\n", index);
    }
}

int main(int argc, char *argv[]) {
    printf("Text : ");
    getAnInput();
    colemanLiau(buffer);
    return 0;
}
