/*
 * Sample Input

 * 1 10
 * 100 200
 * 201 210
 * 900 1000 

 * Sample Output

 * 1 10 20 
 * 100 200 125 
 * 201 210 89 
 * 900 1000 174 
*/

#include <stdio.h>

char *in[1024];
int i,j,k,l,m;

int collatz(int n) {
  /*  printf("- %d -", n); */
  if (n == 1)
    return (1);
  else
    if (n%2 == 0) {
      return (1 + collatz(n/2));
    } else {
      return (1 + collatz(3*n+1));
    }
}

int maxlen( int i, int j) {
  m = 0;

  if ( j<i ) { int t = i; i = j; j = t; }
  
  for (k=i;k<=j;k++) {
    l = collatz(k);
    /* printf("\n %d %d %d\n", k, l, m); */
    if ( l > m ) {
      m = l;
    }
  }
  return m;
}

int main() {

  for(
      i=0,j=0;
      (char *)&in == fgets((char *)&in,sizeof in,stdin) &&
	(2 == sscanf((char *)&in, "%u %u", &i, &j));
      printf("%d %d %d\n", i, j, maxlen(i, j) )) {}

  return 0;

}
