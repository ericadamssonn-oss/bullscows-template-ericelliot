#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TEST true
#define DEBUG false

void test();

// *********************************************************
// ----------- Declaration functions used in main ----------
// *********************************************************

// Returns true if one of the digits in number is equal to digit.
int digit_is_in(int number, int digit) {
    while (number > 0) {
        if (number % 10 == digit) return 1;
        number /= 10;
    }
    return 0;
}

// Generates an N-digit random number with no repeated digits
// (digits in range 1-9)
int get_random_4digit() {
    //sätter alla siffror till 0
    int d1=0;
    int d2=0;
    int d3=0;
    int d4=0;
    int number; // Deklarerad för att kunna användas nedan

    //slumpar första  siffran
    d1 = rand() % 9 + 1;

    //slumpar andra siffran, slumpar bara siffran då d2 = 0 eller om första
    //siffran är lika med andra siffran, vilket då gör att den kommer slumpa
    //tills siffran inte är den samma som första sa denb blir undik.
    while (d2 == 0 || d1 == d2) {
        d2 = rand() % 9 + 1;
    }

   // slumpar 3e siffran
   while (d3 == 0 || d3 == d1 || d3 == d2) {
        d3 = rand() % 9 + 1;
    }
    //slumpar fjärde siffran
    while (d4 == 0 || d4 == d1 || d4 == d2 || d4 == d3) {
        d4 = rand() % 9 + 1;
    }
    //bygger ihop talet med våra siffror. Multiplicerar med 10 potensen och adderar
    //till ett fullständigt tal
    number = ( (d1 * 1000) + (d2 * 100) + (d3 * 10) + (d4 * 1) );
    return number;
}

// Returns number of bulls in guessed number
int count_bulls(int guess, int answer) {
    int bulls = 0;
    for (int i=0; i<4; i++) {
        if (guess % 10 == answer % 10) { // Ändrat från = till == för jämförelse
            bulls++;
        }
        guess /= 10;
        answer /= 10;
    }
    return bulls;
}

// Returns number of bulls and cows in guessed number
int count_cows_and_bulls(int guess, int answer) {
    int total_matches = 0;
    int temp_guess = guess;
    for (int i = 0; i < 4; i++) {
        if (digit_is_in(answer, temp_guess % 10)) {
            total_matches++;
        }
        temp_guess /= 10;
    }
    return total_matches;
}

// Reads player input from console
int get_player_guess() {
    int guess = 0;
    printf("skriv din gisning:");
    scanf("%i", &guess);
    return guess;
}

// Test if player guess contain repetition and correct size. Returns guess back or -2 if input is wrong.
int check_guess_format(int guess) {

    int size = 0;
    int temp = guess;

    //abort game
    if (guess == -1) {
        return -1;
    }

    while (temp > 0 ) {
        temp /= 10;
        size++;
    }
    if (size == 4) {
        int digit4 =(gues) % 10;
        int digit3 = (guess/10) % 10;
        int digit2 = (guess/100) %10
        int digit1 = (guess/1000) %10
        // kollar så talen är mellan 1-9
        if (digit1>= 1 && digit1<=9 && digit2>= 1 && digit2<=9 && digit3>= 1 && digit3<=9 && digit4>= 1 && digit4<=9){
            // kolla efter dubbleter
            if (digit1 != digit2 && digit1 != digit3 && digit1 != digit4 && digit2 != digit3 && digit2 != digit4 && digit3 != digit4 &&) {
                return guess;
            }
        }
    }
    printf("error")// error fel inmatning
    return -2;

}

// Prints the game instructions for player
void print_instructions() {
    printf("Welcome to Bulls and Cows\n Try to guess a 4 digit number with digits from 1-9\n and no repeating digits (-1 to abort)");
    printf("\n\n"); // Lade till ett semikolon här
    printf("Bulls = Correct digits in correct posistions.\n Cows = Correct digits in wrong positions\n");
}

// *********************************************************
// -----------           Main                     ----------
// *********************************************************

int main(void) {
    setbuf(stdout, 0);
    srand(time(NULL));

    if (TEST) {
        test();
    }

    int answer = get_random_4digit();

    if (DEBUG) {
        printf("Answer is %d\n", answer);
    }

    print_instructions();

    bool aborted = false;
    bool guessed = false;
    int number_of_guesses = 0;
    int current_guess = 0;
    int bulls = 0;
    int cows = 0;

    do {
        current_guess = get_player_guess();

        if (current_guess == -1) {
            aborted = true;
        } else {
            number_of_guesses++;
            bulls = count_bulls(current_guess, answer);
            int total = count_cows_and_bulls(current_guess, answer);
            cows = total - bulls;

            printf("Bulls: %d, Cows: %d\n", bulls, cows);

            if (bulls == 4) {
                guessed = true;
            }
        }

    } while (!guessed && !aborted);

    if (aborted) {
        printf("Game aborted\n");
    } else {
        printf("Done, number was %d you needed %d guess(es)\n", answer, number_of_guesses);
    }
    return 0;
}

// --- Test-funktioner och implementationer behålls i slutet ---
void assert(bool v1, bool v2) {
    if (v1 == v2) printf("Test passed\n");
    else printf("Test failed\n");
}

void test() {
    printf("running tests\n");
    // Här kan du avkommentera dina tester när du vill köra dem
    exit(0);
}