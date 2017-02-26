/** @file Collatz.c++
 *  @brief Functions that solves (read, evaluate, and write) Collatz values.
 *   
 *  Part 2 of SphereCollatz.c++.
 */

// --------
// includes
// --------
 
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

// -------------
// cache defined
// -------------

#define CACHE

#ifdef CACHE
int optimize[1000000]; //lazy cache
#endif

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) 
{
    assert(i > 0);
    assert(j > 0);
    /* The range could be (high, low).
     * So swapping the i and j values to ensure i <= j,
     * an important condition in for loop.*/
    if(i>j)
    {
        int t = j;
        j = i;
        i = t;
    }

    int max_cycle_length = 1;
    for (; i <= j; i++)
    {
        int k = i;
        int temp = 1;
        //cycle length
        while(k > 1)
        {
            //if the collatz value of "i" already exists in cache.
            #ifdef CACHE
            if(1000000 > k && optimize[k]!=0)
            {
                /* Get the value and break out of the process.
                 * Quick and fast. #optimized */
                temp = temp + optimize[k] - 1;
                break;
            }
            #endif

            if(k%2 == 0) //if even
                k = k/2;
            else         //if odd
                k = 3*k + 1;
            //temporary cycle length
            ++temp;
        }
        assert (temp > 0);
        //storing the maximum cycle length
        if (temp > max_cycle_length)
            max_cycle_length = temp;
        //storing the value of i in the cache. #lazy_cache
        #ifdef CACHE
        if(1000000 > i)
        {
            optimize[i] = temp;
        }
        #endif
    }
    return max_cycle_length;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}