#ifndef EXTRATOOLS_H
#define EXTRATOOLS_H

/**
 Inverse Square root.
 * @param number    Number to calculate the inverse square root.
 * @return          Inverse square root of the number.
 */
float invSqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    
    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    //  y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}

/**
 Square root.
 @param x   Number to calculate the square root.
 @return    Square root of the number.
 */
float squareRoot(float x) {
    const float xhalf = 0.5f*x;
    
    union // get bits for floating value
    {
        float x;
        int i;
    } u;
    u.x = x;
    u.i = 0x5f3759df - (u.i >> 1);  // gives initial guess y0
    return x*u.x*(1.5f - xhalf*u.x*u.x);// Newton step, repeating increases accuracy
}

namespace math {

/**
 * @brief max
 * @param a
 * @param b
 * @return
 */
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

/**
 * @brief min
 * @param a
 * @param b
 * @return
 */
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

}


#endif  // EXTRATOOLS_H
