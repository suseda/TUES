max3(x, y, z)
{
    if (x < y)
        if (y < z)
            return z;
        else
            return y;
    else
        if (x < z)
            return z;
        else
            return x;
}


void main()
{
    max3(3, 2, 1);
    max3(1, 2, 3);
    max3(2, 3, 1);
}