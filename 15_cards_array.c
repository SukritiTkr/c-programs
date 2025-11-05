#include <stdio.h>

int main() {
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int i, j;

    printf("Deck of 52 cards:\n");
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 13; j++) {
            printf("%s of %s\n", ranks[j], suits[i]);
        }
    }

    return 0;
}


/* 
to compile and run this program:

gcc 15_cards_array.c -o cards.exe
./cards.exe
*/
