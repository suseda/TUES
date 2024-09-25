#define UPCASE(c) ('a'<=(c)&&(c)<='z'?(c)+'A'-'a':(c))

#define M1(x) M2(4*(x)) M2(4*(x)+1) M2(4*(x)+2) M2(4*(x)+3)
#define M2(x) M3(4*(x)) M3(4*(x)+1) M3(4*(x)+2) M3(4*(x)+3)
#define M3(x) M4(4*(x)) M4(4*(x)+1) M4(4*(x)+2) M4(4*(x)+3)
#define M4(x)   UPCASE(x),
char upcase[] = { M1(0)M1(1)M1(2)M1(3) };

void main()
{
	char c = upcase['x'];
}