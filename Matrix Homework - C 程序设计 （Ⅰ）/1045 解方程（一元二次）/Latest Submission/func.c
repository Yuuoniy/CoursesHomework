int getRoots(double a, double b, double c, \
    double *pRootOne, double *pRootTwo)
{
    double deta = 0;
    deta = b*b-4*a*c;
    if(deta<0)
        return 0;
    else
    {
        *pRootOne= (-b+sqrt(deta))/(2*a);
        *pRootTwo = (-b-sqrt(deta))/(2*a);
    }
    return 1;

}