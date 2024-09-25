unsigned int mirror_bits(unsigned int u)
{
    unsigned int r = 0;
    for (int i = 0; i < 32; i++)
    {
        if (u & (1 << i))
            r = r | (1 << (31 - i));
    }
    return r;
}
int main()
{
    unsigned int u = 10;
    mirror_bits(u);
}