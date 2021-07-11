#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/** complex numbers have a real and an imaginary part */
typedef struct {
    double real;
    double imag;
} complex_t;

/** constant 0 */
const complex_t complex_0 = { 0,0 };
/** constant 1 */
const complex_t complex_1 = { 1,0 };
/** constant i (often called j in electrical engineering) */
const complex_t complex_j = { 0,1 };

/**
 * Computes the absolute value of a complex number (distance to origin in complex plane).
 * @param c complex number
 * @return absolute value of given complex number
 */
double complex_abs(const complex_t* c) {

    return sqrt(pow(c->real, 2.0) + pow(c->imag, 2.0));
}

/**
 * Adds two complex numbers
 * @param c0 pointer to the complex number storing the result
 * @param c1 pointer to first number
 * @param c2 pointer to second number
 */
void complex_add(complex_t* c0, const complex_t* c1, const complex_t* c2) {

    c0->imag = c1->imag + c2->imag;
    c0->real = c1->real + c2->real;
}


/**
 * Substracts a complex numbers from another number
 * @param c0 pointer to the complex number storing the result
 * @param c1 pointer to first number
 * @param c2 pointer to second number
 */
void complex_sub(complex_t* c0, const complex_t* c1, const complex_t* c2) {

    c0->imag = c1->imag - c2->imag;
    c0->real = c1->real - c2->real;
}


/**
 * Multiplies two complex numbers
 * @param c0 pointer to the complex number storing the result
 * @param c1 pointer to first number
 * @param c2 pointer to second number
 */
void complex_mul(complex_t* c0, const complex_t* c1, const complex_t* c2) {

    c0->imag = ((c1->real * c2->imag) + (c1->imag * c1->real)); // Vorzeichen vielleicht wechseln
    c0->real = ((c1->real * c2->real) - (c1->imag * c2->imag));
}

/**
 * Computes the conjugate complex number.
 * @param c complex number
 * @return conjugate complex number
 */
void complex_conjugate(complex_t* c0, const complex_t* c1) {

    c0->imag = -c1->imag;
    c0->real = c1->real;

}

/**
 * Divides a complex numbers by another number
 * @param c0 pointer to the complex number storing the result
 * @param c1 pointer to first number
 * @param c2 pointer to second number
 */
void complex_div(complex_t* c0, const complex_t* c1, const complex_t* c2) {
    complex_t* conj = malloc(sizeof(complex_t));

    complex_conjugate(conj, c2);
    double d = (c2->real * conj->real) - (c2->imag * conj->imag);
    complex_mul(c0, c1, conj);

    

    conj->imag /= d;
    conj->real /= d;

    free(conj);

    /*
    c0->imag = ((c1->real * c2->real) + (c1->imag * c2->imag)) / (pow(c2->real, 2.0) + pow(c2->imag, 2.0)); // Vorzeichen vielleicht wechseln
    c0->real = ((c1->real * c2->real) - (c1->imag * c2->imag)) / (pow(c2->real, 2.0) + pow(c2->imag, 2.0));
    */
}


/**
 * Computes the reciprocal of a complex number.
 * @param c complex number
 * @return reciprocal of a complex number
 */
void complex_reciprocal(complex_t* c0, const complex_t* c1) {
    complex_t* conj = malloc(sizeof(complex_t));
    complex_conjugate(conj, c1);

    double abs_c = pow(complex_abs(conj), 2.0);

    c0->imag = conj->imag / abs_c;
    c0->real = conj->real / abs_c;

    free(conj);
}


/**
 * Turns a value between 0.0 and 1.0 to a character (for gray-scale purposes)
 * @param gray-scale value (0.0 = white, 1.0 = black)
 * @return char
 */
char grayscale(double x) {
    const char map[] = " .:-=+*#%@";
    if (x > 0.0)
        return map[(int) (x * 10)];
    else
        return ' ';
}


/**
 * Computes and illustrates the Mandelbrot set
 * with the help of complex numbers (on the stack).
 *
 * @see https://de.wikipedia.org/wiki/Mandelbrot-Menge
 */
void mandelbrot_on_stack() {
    for (double imag = -1.5; imag <= 1.5; imag += 0.1) {
        for (double real = -2.0; real <= 1; real += 0.03) {
            complex_t z = complex_0;
            complex_t z2 = complex_0;
            complex_t c = { real, imag };
            double gray = 0.0;
            for (int i = 0; i < 16; i++) {
                complex_mul(&z2, &z, &z);
                complex_add(&z, &z2, &c);
                if (complex_abs(&z) > 2.0) {
                    gray = i / 16.0;
                    break;
                }
            }
            printf("%c", grayscale(gray));
        }
        printf("\n");
    }
}




/**
 * Creates a complex number
 * @param real
 * @param imag
 * @return pointer to created number
 */
complex_t* complex_create(double real, double imag) {
    // TODO
    return NULL;
}

/**
 * Creates a copy of a complex number
 * @param c number to copy
 * @return pointer to created copy
 */
complex_t* complex_copy(const complex_t* c) {
    // TODO
    return NULL;
}


/**
 * Destroy a complex number (freeing memory).
 * @param c
 */
void complex_destroy(complex_t* c) {
    // TODO
}


/**
 * Computes and illustrates the Mandelbrot set
 * with the help of complex numbers (on the heap).
 *
 * @see https://de.wikipedia.org/wiki/Mandelbrot-Menge
 */
void mandelbrot_on_heap() {
    // TODO
}


/* main function */

int main() {
    mandelbrot_on_stack();
    return 0;
}
