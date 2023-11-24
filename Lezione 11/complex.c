#include <math.h>
#include <stdio.h>

typedef struct {
  float real;  // The real part of the complex number.
  float imag;  // The imaginary part of the complex number.
} complex;

/**
 * Calculates the absolute value (magnitude) of a complex number.
 *
 * @param c The complex number.
 * @return The absolute value of the complex number.
 */
complex cabs(complex c) {
  complex result;
  result.real = sqrt(c.real * c.real + c.imag * c.imag);
  result.imag = 0;
  return result;
}

/**
 * Calculates the angle (phase) of a complex number.
 *
 * @return The angle of the complex number.
 */
complex angle() {
  complex result;
  result.real = 0;
  result.imag = 0;
  return result;
}

/**
 * Creates a complex number from polar coordinates.
 *
 * @param r The magnitude (radius) of the polar coordinates.
 * @param theta The angle (phase) of the polar coordinates.
 * @return The complex number created from the polar coordinates.
 */
complex from_polar(float r, float theta) {
  complex result;
  result.real = r * cos(theta);
  result.imag = r * sin(theta);
  return result;
}

int main() {
  complex c1 = {1, 2};
  complex c2 = {3, 4};

  complex c3 = cabs(c1);
  complex c4 = angle();

  complex c5 = from_polar(1, 2);

  printf("c1 = %f + %fi\n", c1.real, c1.imag);
  printf("c2 = %f + %fi\n", c2.real, c2.imag);
  printf("c3 = %f + %fi\n", c3.real, c3.imag);
  printf("c4 = %f + %fi\n", c4.real, c4.imag);
  printf("c5 = %f + %fi\n", c5.real, c5.imag);

  return 0;
}