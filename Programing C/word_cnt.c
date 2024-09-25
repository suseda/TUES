int word_cnt(const char* s)
{
    int inside_word = 0, cnt = 0;
    for (const char* p = s; *p != 0; p++)
        if (*p != ' ' && !inside_word)
        {
            inside_word = 1;
            cnt++;
        }
        else if (*p == ' ' && inside_word)
            inside_word = 0;
    return cnt;
}
void main()
{
  word_cnt("one two three"); //->3
}