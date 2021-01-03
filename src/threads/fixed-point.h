#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define Q 14
#define P 17
#define F (1<<Q)

#if P + Q != 31
#error "ERROR: P + Q != 31."
#endif

typedef int fp;

static fp convert_to_fp(int n);
static int toInt_round_down(fp x);
static int toInt_round_nearest(fp x);
static fp fp_add(fp x, fp y);
static fp fp_subtract(fp x, fp y);
static fp add_int(fp x, int n);
static fp subtract_int(fp x, int n);
static fp fp_multiply(fp x, fp y);
static fp int_multiply(fp x, int n);
static fp fp_divide (fp x , fp y);
static fp int_divide(fp x, int n);

static int convert_to_fp(int n)
{
    return n*F;
}
static int toInt_round_down(fp x)
{
    return x/F;
}
static int toInt_round_nearest(fp x)
{
    return (x>=0) ? (x+F/2)/F : (x-F/2)/F ;
}
static fp fp_add(fp x, fp y)
{
    return x+y;
}
static fp fp_subtract(fp x, fp y)
{
    return x-y;
}
static fp add_int(fp x, int n)
{
    return x+(n*F);
}
static fp subtract_int(fp x, int n){
    return x-(n*F);
}
static fp fp_multiply(fp x , fp y)
{
    return ((int64_t)x)*y / F;
}
static fp int_multiply(fp x, int n)
{
    return x*n;
}

static fp fp_divide(fp x, fp y)
{
    return ((int64_t)x)*F / y;
}
static fp int_divide(fp x, int n){
    return x/n;
}
#endif  /* threads/fixed-point.h */
