/** @file RunCollatz.c++
 *  @brief Contains the main() function.
 *   
 *  Part 1 of SphereCollatz.c++. Contains the main() function that calls collatz_solve() which handles the input and output.
 */

// --------
// includes
// --------

#include <iostream> // cin, cout

#include "Collatz.h"

// main 

int main () {
    using namespace std;
    collatz_solve(cin, cout); /** collatz_solve() defined in Collatz.c++ is called with cin, cout as arguments */
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz



% cat RunCollatz.in
1 10
100 200
201 210
900 1000



% RunCollatz < RunCollatz.in > RunCollatz.out



% cat RunCollatz.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
