int log(y, x)
{
    int v=x;
   int n = 1;
   while (y != x)
   {
       x = x * v;
       n = n + 1;
   }
   return n;
}




void main()
{
    int res = log(625,4);
}