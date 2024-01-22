#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

void preprocess_pattern(char pattern[], int m, int shift_table[]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        shift_table[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        shift_table[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

void horspool_search(char dna_sequence[], char pattern[]) {
    int n = strlen(dna_sequence);
    int m = strlen(pattern);

    if (m > n) {
        printf("Pattern not found.\n");
        return;
    }

    int shift_table[ALPHABET_SIZE];
    preprocess_pattern(pattern, m, shift_table);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == dna_sequence[i - k]) {
            k++;
        }
        if (k == m) {
            printf("Pattern found at index %d.\n", i - m + 1);
        }
        i += shift_table[(unsigned char)dna_sequence[i]];
    }
}

int main() {
    char dna_sequence[100];
    char pattern[20];

    printf("Enter the DNA sequence: ");
    scanf("%s", dna_sequence);

    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    horspool_search(dna_sequence, pattern);

    return 0;
}