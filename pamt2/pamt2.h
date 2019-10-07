#ifndef PAMT2_H    /* Macro Guard */
#define PAMT2_H


/* 
 * The number of concurrent threads that the current machine can support.
 */

const int numOfThreads = std::thread::hardware_concurrency();

/*
 * Here are one non-prime and several large primes.
 */

long long num0 = 489133282872437277LL;  // not prime; seq better
long long num1 = 87178291199LL;
long long num2 = 70368760954879LL;
long long num3 = 688846502588399LL;
long long num4 = 32361122672259149LL;
long long num5 = 489133282872437279LL;
long long num6 = 790738119649411319LL;
long long num7 = 6312646216567629137LL;

/*
 * This array contains all of the large numbers defined above. It might
 * make sense for you to reduce this to one or two numbers for debugging
 * purposes. But make sure that you restore it to this state before turning
 * the assignment in.
 */  

long long nums[] = { num0, num1, num2, num3, num4, num5, num6, num7 };

/*
 * Local function prototypes for PAMT2
 */

bool isPrime( long long n, long long lo, long long hi );

#endif

