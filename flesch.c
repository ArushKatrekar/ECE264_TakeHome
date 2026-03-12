// flesch.c - Student Implementation File
// Implement the Flesch Reading Ease algorithm
//
// DO NOT modify the function signatures

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "flesch.h"

int countSentences(const char* text) {
    int count = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c == '.' || c == '!' || c == '?'|| c == ';' || c == ':') {
            count++;
        }
    }
    // TODO: Implement this function
    return count==0 ? 1 : count;
}

int countSyllables(const char* text) {
    int count = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        char c = tolower(text[i]);
        int isVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        char prevChar = (i > 0) ? tolower(text[i - 1]) : '\0';
        int isPrevVowel = (prevChar == 'a' || prevChar == 'e' || prevChar == 'i' || prevChar == 'o' || prevChar == 'u');
        if (!isPrevVowel && isVowel) {
            count++;
        }
    }
    return count;
}

double calculateFleschScore(TextStats stats) {
    if(stats.words == 0) return 0.0;
    return 206.835 - (1.015 * ((double)stats.words / stats.sentences)) - (84.6 * ((double)stats.syllables / stats.words));
}

TextStats analyzeText(const char* text) {
    TextStats stats;
    stats.sentences = countSentences(text);
    stats.words = countWords(text);
    stats.syllables = countSyllables(text);
    return stats;
}
