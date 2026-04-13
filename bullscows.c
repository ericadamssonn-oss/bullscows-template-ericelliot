/*
 *     The bulls and cows game
 *     See https://en.wikipedia.org/wiki/Bulls_and_Cows
 *     See bulls_and_cows.pdf for more instructions
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TEST true      // If true, only run the tests else run the main program
#define DEBUG false    // If true, print answer to the console at the beginning of the game



// Testing of functions, see implementation in the end of the file
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
    //slumpar första siffran
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
    number == ( (d1 * 1000) + (d2 * 100) + (d3 * 10) + (d4 * 1) );
    return number;
}
// Returns number of bulls in guessed number
int count_bulls(int guess, int answer);

// Returns number of bulls and cows in guessed number
int count_cows_and_bulls(int guess, int answer);

// Reads player input from console
int get_player_guess(){

int guess=0;
printf("skriv din gisning:");
scanf("%i", &guess);
return guess;
}
// Test if player guess contain repetition and correct size. Returns guess back or -2 if input is wrong.int check_guess_format(int guess);
int sizeofguess(int guess){

    int size= 0;
    while (guess > 0) {
        guess / 10;
        size++;
    }

}



for (int i=0; i<4; i++) {
    if (guess % 10 == answer %10);
    {
        bulls++;
    }
    guess/=10;
    answer/=10;
}



// Prints the game instructions for player
void print_instructions() {

    printf("Welcome to Bulls and Cows\n Try to guess a 4 digit number with digits from 1-9\n and no repeating digits (-1 to abort)");
    printf("\n\n");
    printf("Bulls = Correct digits in correct posistions.\n Cows = Correct digits in wrong positions");
}

// *********************************************************
// -----------           Main                     ----------
// *********************************************************

int main(void) {
    setbuf(stdout, 0);
    // Required to force printf printing to console during debugging

    srand(time(NULL)); // Initialise random number generator

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

    // *********************************
    // -------    Game loop   ----------
    // *********************************

    do {
        current_guess = get_player_guess();

    } while ();

    // After game loop
    if (aborted) {
        printf("Game aborted\n");
    } else {
        printf("Done, number was %d you needed %d guess(es)\n", answer,
               number_of_guesses);
    }
    return 0;
}

// *********************************************************
// -----------      Function implementation     ----------
// *********************************************************

int get_random_4digit() {
    return 1234;
}

int digit_is_in(int number, int digit) {
    // TODO: implement function bodies.
}


// *********************************************************
// -----------           Test                     ----------
// *********************************************************

// ---------------- Testing --------------------
void assert(bool v1, bool v2) {
    if (v1 == v2)
        printf("Test passed\n");
    else
        printf("Test failed\n");
}

void test() {
    printf("running tests\n");

    // TODO: Uncomment the lines to test the functions that you have implemented

    // printf("\nPrinting 10 random numbers\n");
    // for (int i = 0; i < 10; i++)
    //     printf("Random answer %d\n", get_random_4digit());
    //
    // printf("\nTesting digit_is_in\n");
    // assert(digit_is_in(2637, 2), true);
    // assert(digit_is_in(2637, 4), false);
    //
    // printf("\nTesting count_bulls\n");
    // assert(count_bulls(1827, 7814), 1);
    // assert(count_bulls(2647, 2837), 2);
    //
    // printf("\nTesting count_cows_and_bulls\n");
    // assert(count_cows_and_bulls(1827, 7813), 3);
    // assert(count_cows_and_bulls(2647, 2837), 2);

    exit(0); // End program
}