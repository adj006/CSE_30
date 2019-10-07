/*
 * Filename: sequentialSquaredSumMinMax
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Takes a reference to the array defined in main,
 *              and low and high indexes. It should then iterate
 *              through each element, from lo to hi and calculate
 *              the squared sum, and determine the minimum and maximum
 *              values in sequence.
 * Date: Nov. 5, 2013
 * Sources of Help: Discussion
 */
#include "pamt1.h"


/*
 * This function calculates the sum of the squares in each element
 * and the min and max of the array
 */
struct result sequentialSquaredSumMinMax( char a[], int lo, int hi )
{
  int i = 0;
  struct result result;
  long long sum = 0;
  int max = a[lo];
  int min = a[lo];
  for( i = lo; i < hi; i++ )
  {
    sum += (a[i]*a[i]);
    max = (max < a[i]) ? a[i] : max;
    min = (min > a[i]) ? a[i] : min;
  }
  result.sum = sum;
  result.max = max;
  result.min = min;
  return result;
}
