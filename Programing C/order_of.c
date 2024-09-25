enum order { unsorted, ascending, strictly_ascending, descending, strictly_descending, equal }
order_of(const int* p, unsigned len)
{
    unsigned mask = 0;
    for (const* l = p, *r = p + 1, *e = p + len; r < e; l = r++)
    {
        mask |= (*l < *r) << 2 | (*l > * r) << 1 | (*l == *r);
    }
    static const enum order convert[] = { equal,equal,strictly_descending,descending,strictly_ascending,ascending,unsorted,unsorted };
    return convert[mask];
}

void main()
{
    int a[] = { 4,6,2,1 };
    enum order o = order_of(a, sizeof a / sizeof * a);
}