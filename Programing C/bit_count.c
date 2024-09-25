bit_count(c)
{
    char B[] = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4 };
    return B[c >> 4] + B[c & 0xf];
}

void main()
{
    int c = 3;
    int res = bit_count(c);
}