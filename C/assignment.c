#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int num;  // Input number
int roll_number = 2;  //my roll no


// Function to check if the number is prime
void* checkPrime(void* arg) {
    int isPrime = 1;

    if (num <= 1) {
        isPrime = 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if (isPrime) {
        printf("%d is prime.\n", num);
        num += roll_number;  // Add roll number
        printf("After adding roll number the new number is: %d\n", num);
    } else {
        printf("%d is not prime.\n", num);
        num -= roll_number;  // Subtract roll number
        printf("After subtracting roll number the new number is: %d\n", num);
    }

    return NULL;
}

// Function to generate a random number and print numbers between random number and num
void* displayRange(void* arg) {
    srand(time(0));
    int random_num = (rand() % 90) + 10;  // Generate a random two-digit number

    printf("Random number generated: %d\n", random_num);
    printf("Numbers between %d and %d:\n", random_num, num);

    if (random_num < num) {
        for (int i = random_num + 1; i < num; i++) {
            printf("%d ", i);
        }
    } else {
        for (int i = num + 1; i < random_num; i++) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return NULL;
}

int main() {
    pthread_t prime_thread, range_thread;

    // Accept input from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Create the thread for checking prime
    if (pthread_create(&prime_thread, NULL, checkPrime, NULL) != 0) {
        perror("Failed to create prime thread");
        return 1;
    }

    // Create the thread for displaying the range
    if (pthread_create(&range_thread, NULL, displayRange, NULL) != 0) {
        perror("Failed to create range thread");
        return 1;
    }

    // Wait for both threads to finish
    if (pthread_join(prime_thread, NULL) != 0) {
        perror("Failed to join prime thread");
        return 1;
    }

    if (pthread_join(range_thread, NULL) != 0) {
        perror("Failed to join range thread");
        return 1;
    }

    return 0;
}