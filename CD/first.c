#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 100

void findFirst(char c);
void follow(char c);
void followFirst(char c, int productionIndex, int nextSymbolIndex);

char productions[MAX_PRODUCTIONS][MAX_SYMBOLS];
char firstSets[MAX_PRODUCTIONS][MAX_SYMBOLS];
char followSets[MAX_PRODUCTIONS][MAX_SYMBOLS];
int firstCount[MAX_PRODUCTIONS] = {0};
int followCount[MAX_PRODUCTIONS] = {0};
int productionCount = 0;

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &productionCount);
    printf("NOTE: Enter '#' for epsilon productions\n");

    for (int i = 0; i < productionCount; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", productions[i]);
    }

    // Calculate First sets
    for (int i = 0; i < productionCount; i++) {
        findFirst(productions[i][0]);
        printf("First(%c) = { ", productions[i][0]);
        for (int j = 0; j < firstCount[i]; j++) {
            printf("%c%s", firstSets[i][j], j < firstCount[i] - 1 ? ", " : "");
        }
        printf(" }\n");
    }

    printf("\n");

    // Calculate Follow sets
    for (int i = 0; i < productionCount; i++) {
        follow(productions[i][0]);
        printf("Follow(%c) = { ", productions[i][0]);
        for (int j = 0; j < followCount[i]; j++) {
            printf("%c%s", followSets[i][j], j < followCount[i] - 1 ? ", " : "");
        }
        printf(" }\n");
    }

    return 0;
}

void findFirst(char c) {
    for (int i = 0; i < productionCount; i++) {
        if (productions[i][0] == c) {
            if (productions[i][2] == '#') {
                firstSets[i][firstCount[i]++] = '#';
            } else if (!isupper(productions[i][2])) {
                firstSets[i][firstCount[i]++] = productions[i][2];
            } else {
                findFirst(productions[i][2]);
            }
        }
    }
}

void follow(char c) {
    if (productions[0][0] == c) {
        followSets[0][followCount[0]++] = '$';  // Adding end-of-input marker
    }

    for (int i = 0; i < productionCount; i++) {
        for (int j = 2; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == c) {
                if (productions[i][j + 1] != '\0') {
                    followFirst(productions[i][j + 1], i, j + 2);
                }
                if (productions[i][j + 1] == '\0' && c != productions[i][0]) {
                    follow(productions[i][0]);
                }
            }
        }
    }
}

void followFirst(char c, int productionIndex, int nextSymbolIndex) {
    if (!isupper(c)) {
        followSets[productionIndex][followCount[productionIndex]++] = c;  // Add terminal to Follow set
        return;
    }

    for (int i = 0; i < productionCount; i++) {
        if (productions[i][0] == c) {
            for (int j = 2; productions[i][j] != '\0'; j++) {
                if (productions[i][j] == '#') {
                    follow(productions[i][0]);
                } else {
                    followFirst(productions[i][j], productionIndex, j + 1);
                }
            }
        }
    }
}
