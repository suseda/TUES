void sort_words(char* s,char *a)
{
    int cnt = 0;
    while (*a != '\0')
    {
        while (*a != ' ')
        {
            a++;
        }
        cnt++;
        a++;
    }

    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (strcmp(s[i], s[j]) < 0)
            {
                char x;
                x = s[j];
                s[j] = s[i];
                s[i] = x;
            }
        }

    }
}



void main()
{
    char *s[] = { "hello", "big", "world", "out", "ant" };
    char a[] = "hello big world out ant ";
    sort_words(s,a);
}