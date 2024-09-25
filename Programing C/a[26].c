f(char a[26])//'A','B'... Z
{
    int x = 0;
    do {
        a[x] = x + 'A';
        x++;

    } while (x < 26);

}


void main()
{
    char a[26];
    f(a);
}