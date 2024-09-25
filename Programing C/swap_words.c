void swap(char* nachalo, char* krai)
{
    char a;
    while (nachalo < krai) {
        a = *nachalo;
        *nachalo = *krai;
        *krai = a;
        *nachalo++;
        *krai--;
    }
}


void swap_words(char* s)
{
    char* b = s;
    char* a = s;

    while (*a != 0) {
        a++;
        if (*a == 0) {
            swap(b, a - 1);
        }
        else if (*a == ' ') {
            swap(b, a - 1);
            b = a + 1;
        }
    }


    swap(s, a - 1);
}


int main()
{
    char s[] = "one two three";
    swap_words(s);
    return 0;
}


