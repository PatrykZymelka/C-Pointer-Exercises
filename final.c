#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 10000000;
    
    /*
    int * a_ptr = &a;
    double * d_ptr = &a;
    float * f_ptr = &a;
    printf("%d, %f, %f\n", *a_ptr, *d_ptr, *f_ptr);
    */

    void * v_ptr = &a;
    int * av_ptr = v_ptr;
    float * fv_ptr = v_ptr;
    double * dv_ptr = v_ptr;

    printf("%d, %x, %x\n", *av_ptr, *fv_ptr, *dv_ptr);
    
}