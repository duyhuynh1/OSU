/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: Matrix calculator determinant calculation
*********************************************************************/
// https://www.mathsisfun.com/algebra/matrix-determinant.html
#ifndef DETERMINANT_HPP
#define DETERMINANT_HPP
#include <iostream>     // REMOVE
/**
 *  [NOTE]: Determinant of a matrix can only be calcaulated from a 
 *  square matrixes.
 *  det A = |A|
 *  - For a 2x2 Matrix
 *  | a b | = ad - bc
 *  | c d |
 *  - For a 3x3 Matrix
 *  | a b c | = a(ei − fh) − b(di − fg) + c(dh − eg)
 *  | d e f |
 *  | g h i |
 */

int determinant(int **aPtr, int size);

#endif  // DETERMINANT_HPP