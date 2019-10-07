/* Filename: is_prime.cpp
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This program checks whether the passed in value a prime number.
 * Date: Nov. 22, 2013
 */

/*
 * Function name: isPrime()
 *
 * Function prototype: bool isPrime( long long n, long long lo, long long hi ); 
 *
 * Params: n is the value we are checking to determine if it is prime or not.
 *         lo is the low (inclusive) range of possible factors to check.
 *         hi is the high (exclusive) range of possible factors to check.
 *
 * Algorithm:
 *   if n <= 1 return false (we won't deal with values less than 2)
 *
 *   if n == 2 return true (2 is the first prime)
 *
 *   if n is even return false (quickly eliminate; evenly divisible by 2)
 *
 *   if lo < 3 set lo = 3 (want to start factors at 3 as lowest factor)
 *       (this helps so we don't have a special case for the
 *        1st parallel partition.)
 *
 *   if lo is even increment lo by 1 to start at an odd factor
 *       (this could be due to the integer divide for the thread partitions) 
 *       (and we already eliminated any even factors above)
 *   
 *   loop thru the range [lo, hi) as factors incrementing by 2 each time
 *       checking if n is evenly divisible by each factor. Remember we are
 *       starting at an odd factor for lo. We do not need to check any even
 *       factors.
 *       If it is evenly divisible, return false immediately.
 *   
 *   If you make it thru the range of factors and have not returned false yet,
 *   return true.
 *
 *   There may be other more efficient isPrime algorithms, but this will do.
 *   We want to see how multi-threading in C++11 with async()/get()
 *   might improve overall performance.
 *
 * Side Effects: None.
 *
 * Error Conditions: None.
 *
 * Return value: bool indicating whether number is prime or not.
 */

bool isPrime( long long n, long long lo, long long hi )
{
  int even = 2;
  if ( n <= 1 )
    return false;
  else if ( n == even )
    return true;
  else if ( n % even == 0 )
    return false;
  lo = ( lo < 3 ) ? 3 : lo;
  lo = ( lo % even == 0 ) ? lo++ : lo;
  for ( long long i = lo; i < hi; i += even )
  {
    if ( n % i == 0 )
      return false;
  }
  return true;
}

