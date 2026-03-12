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
        if (c == '.' || c == '!' || c == '?') {
            count++;
        }
    }
    // TODO: Implement this function
    return count==0 ? 1 : count; // Ensure at least one sentence to avoid division by zero
}

int countWords(const char* text) {
    int count = 0;
    int inWord = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        int isDelimiter = isspace(c) || c == '.' || c == ':' || c == ';'|| c == '?' || c == '!';
        if (isDelimiter) {
            inWord = 0;
        } else if (!inWord) {
            count++;
        }
        inWord = 1;
        }
    // TODO: Implement this function
    return count==0 ? 1 : count; // Ensure at least one word to avoid division by zero
}

int countSyllables(const char* text) {
    int count = 0;
    int prevWasVowel = 0;
    int isVowel = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        isVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
        if (isVowel){
            count++;
            prevWasVowel = 1;
        } else {
            prevWasVowel = 0;
        }
    }
    // TODO: Implement this function
    return count;
}

double calculateFleschScore(TextStats stats) {
    if(stats.words == 0) return 0.0; // Avoid division by zero 
    return 206.835 - (1.015 * ((double)stats.words / stats.sentences)) - (84.6 * ((double)stats.syllables / stats.words));
}

TextStats analyzeText(const char* text) {
    TextStats stats;
    stats.sentences = countSentences(text);
    stats.words = countWords(text);
    stats.syllables = countSyllables(text);
    return stats;
}
