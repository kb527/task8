#include <stdio.h>
#include <string.h>

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int countAnagrams(char *word) {
    int length = strlen(word);
    int counts[26] = {0};

    for (int i = 0; i < length; ++i) {
        counts[word[i] - 'A']++;
    }

    int anagrams = factorial(length);
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 1) {
            anagrams /= factorial(counts[i]);
        }
    }

    return anagrams;
}

int main() {
    char word[15];
    printf("Enter a word: ");
    scanf("%s", word);

    printf("The number of possible anagrams is: %d\n", countAnagrams(word));

    return 0;
}
