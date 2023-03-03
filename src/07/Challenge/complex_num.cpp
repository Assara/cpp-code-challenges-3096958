#include "complex_num.h"

complex_num::complex_num(double r, double i){
    re = r;
    im = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.re = re + w.re;
    z.im = im + w.im;
    // Write your code here
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    // Write your code here
    z.re = re - w.re;
    z.im = im - w.im;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.re = re*w.re - im*w.im;
    z.im = re*w.im + im*w.re;
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    double divnorm = 1/ w.square_norm();
    z.re = (re* w.re+im* w.im )*divnorm;
    z.im = (im* w.re - re* w.im )*divnorm;

    return z;
}

double complex_num::square_norm() {
    return re*re - im*im;
}

void complex_num::print(std::ostream &os){
    if(im >= 0.0)
        os << re << " + " << im << "i";
    else
        os << re << " - " << im * -1 << "i";
    os << std::flush;
}