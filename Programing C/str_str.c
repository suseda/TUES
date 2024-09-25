char* str_str(char* s, char* substr)
{
    int i, j = 0;
    for (i = 0; s[i] != 0; i++)
    {
        if (s[i] != substr[j])
            j = 0;
        if (s[i] == substr[j])
        {
            j++;
            if (substr[j] == 0)
                return &s[i - (j - 1)];
        }
    }
}
void main()
{
    char* s = "one two three";
    char* res = str_str(s, "two"); // res==s+4
}