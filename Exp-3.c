#include <stdio.h>
#include <string.h>
void removeDuplicates(char *str) {
    int len = strlen(str);
    int index = 0;

    for (int i = 0; i < len; i++) {
  
      int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
          if (j == i) {
            str[index++] = str[i];
        }
    }
       str[index] = '\0';
}

void constructMatrix(char *key, char matrix[5][5]) {
    removeDuplicates(key);

    int len = strlen(key);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (key[i] == 'j') {
  
            key[i] = 'i';
        }
 
        matrix[index / 5][index % 5] = key[i];
        index++;
    }

  
for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'j') {
    
            continue;
        }
        int i, j;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (matrix[i][j] == c) {
                    break;
                }
            }
            if (matrix[i][j] == c) {
                break;
            }
        }
        if (i == 5 && j == 5) {

            matrix[index / 5][index % 5] = c;
            index++;
        }
    }
}

void findPosition(char matrix[5][5], char letter, int *row, int *col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptMessage(char matrix[5][5], char *message, char *encrypted) {
    int len = strlen(message);

    int index = 0;
    for (int i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[index++] = message[i];
        } else if (message
