
// The following routines are from the book "Numerical Recipes in C" 
// -- this book has many other useful numerical functions along with
// c++ code for them in files.

// ran (ran1) is the recommended function to use for most applications.
//
// call with any negative integer seed value s to initialize the sequence.
// thereafter do not modify s in your program -- just let ran(...) do that.
// the function returns a random number x, 0.0 < x < 1.0 (not including 0.0 and 1.0)
double ran(long int &s);

// ran2 is an improvement over ran1 but slower. 
// recommended for very long periods (>10^8 numbers)
//
// call with any negative integer seed value s to initialize the sequence.
// thereafter do not modify s in your program -- just let ran2(...) do that.
// the function returns a random number x, 0.0 < x < 1.0 (not including 0.0 and 1.0)
double ran2(long int &s);

// ran3 is a fast and different alternative approach. 
// useful for comparison to the functions above.
//
// call with any negative integer seed value s to initialize the sequence.
// thereafter do not modify s in your program -- just let ran3(...) do that.
// the function returns a random number x, 0.0 < x < 1.0 (not including 0.0 and 1.0)
double ran3(long int &s);
