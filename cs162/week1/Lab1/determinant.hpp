/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: Matrix calculator determinant function prototype. This
** function takes 2 parameters: a pointer to a 2D array and the size 
** of the matrix.
*********************************************************************/
/**
 *  [NOTE]: Determinant of a matrix can only be calculated from a
 *  square matrices.
 *  det A = |A|
 *  - For a 2x2 Matrix
 *  | a b | = ad - bc
 *  | c d |
 *  - For a 3x3 Matrix
 *  | a b c | = a(ei − fh) − b(di − fg) + c(dh − eg)
 *  | d e f |
 *  | g h i |
 */

#ifndef DETERMINANT_HPP
#define DETERMINANT_HPP

int determinant(int **aPtr, int size);

#endif  // DETERMINANT_HPP