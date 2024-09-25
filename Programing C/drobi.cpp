#include <stdint.h>
#include <malloc.h>

template<typename t>

t nok(t l, t r)
{
    t bigger = l > r ? l : r, smaller = l < r ? l : r, i = bigger;
    for (; i % smaller; i += bigger);
    return i;
}

template<typename t>

t nod(t nom, t denom)
{
    long long smaller = nom < denom ? nom : denom, bigger = nom > denom ? nom : denom, res = 1;
    for (long long i = 1; i <= bigger / 2; i++)
    {
        if (bigger % i == 0 && smaller % i == 0)
            res = i;
    }
    return res;
}

template<typename t>

struct fraction
{
    t nom, denom;
    fraction(t nom, t denom);
    fraction() {};
};
template<typename t>
fraction<t>::fraction(t nom, t denom) : nom(nom), denom(denom) {}
template<typename t>

fraction<t> operator +(fraction<t> left, fraction<t> right)
{
    t common_denom = nok(left.denom, right.denom);
    left.nom *= common_denom / left.denom, right.nom *= common_denom / right.denom, left.denom = common_denom;
    left.nom += right.nom;
    t nod_return = nod(left.nom, left.denom);
    left.nom /= nod_return;
    left.denom /= nod_return;
    return left;
}

template<typename t>

fraction<t> operator -(fraction<t> left, fraction<t> right)
{
    t common_denom = nok(left.denom, right.denom);
    left.nom *= common_denom / left.denom, right.nom *= common_denom / right.denom, left.denom = common_denom;
    left.nom -= right.nom;
    t nod_return = nod(left.nom, left.denom);
    left.nom /= nod_return;
    left.denom /= nod_return;
    return left;
}

template<typename t>

fraction<t> operator *(fraction<t> left, fraction<t> right)
{
    left.nom *= right.nom;
    left.denom *= right.denom;
    t nod_return = nod(left.nom, left.denom);
    left.nom /= nod_return;
    left.denom /= nod_return;
    return left;
}

template<typename t>

fraction<t> operator /(fraction<t> left, fraction<t> right)
{
    left.nom *= right.denom;
    left.denom *= right.nom;
    t nod_return = nod(left.nom, left.denom);
    left.nom /= nod_return;
    left.denom /= nod_return;
    return left;
}

template<typename t>

fraction<t> operator ~(fraction<t> fr)
{
    t nom = fr.nom;
    fr.nom = fr.denom;
    fr.denom = nom;
    return fr;
}

template<typename t>

fraction<t> operator -(fraction<t> fr)
{
    fr.nom = -fr.nom;
    return fr;
}

template<typename t>

int operator >(fraction<t> left, fraction<t> right)
{
    t common_denom = nok(left.denom, right.denom);
    left.nom *= common_denom / left.denom, right.nom *= common_denom / right.denom;
    return left.nom > right.nom ? 1 : 0;
}

template<typename t>

int operator <(fraction<t> left, fraction<t> right)
{
    t common_denom = nok(left.denom, right.denom);
    left.nom *= common_denom / left.denom, right.nom *= common_denom / right.denom;
    return left.nom < right.nom ? 1 : 0;
}

template<typename t>

int operator >=(fraction<t> left, fraction<t> right)
{
    t common_denom = nok(left.denom, right.denom);
    left.nom *= common_denom / left.denom, right.nom *= common_denom / right.denom;
    return left.nom >= right.nom ? 1 : 0;
}

template<typename t>

int operator <=(fraction<t> left, fraction<t> right)
{
    t common_denom = nok(left.denom, right.denom);
    left.nom *= common_denom / left.denom, right.nom *= common_denom / right.denom;
    return left.nom <= right.nom ? 1 : 0;
}

template<typename t>

int operator ==(fraction<t> left, fraction<t> right)
{
    t common_denom = nok(left.denom, right.denom);
    left.nom *= common_denom / left.denom, right.nom *= common_denom / right.denom;
    return left.nom == right.nom ? 1 : 0;
}



void main()
{
    fraction<int> a(3, 5), b(4, 3), c;
    int e;
    c = a + b;
    c = a - b;
    c = a * b;
    c = a / b;
    c = ~b;
    e = a > b;
    e = a < b;
    e = a == b;
    c = -a;
}