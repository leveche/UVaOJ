/* #272 on UVa */

/* 
Sample Input

"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"

Sample Output

``To be or not to be,'' quoth the Bard, ``that
is the question''.
The programming contestant replied: ``I must disagree.
To `C' or not to `C', that is The Question!''
*/

#include <stdio.h>
#include <stdlib.h>


int main() {

  int c;
  static int q = 0;

  c = getchar();  
  while (c != EOF) {
    if (c == '"') { 
      if (q == 0) { 
	/* we are not inside a quote, " -> `` */
	c ='`';
	q = 1;
	putchar('`');
      } else {
	/* we are inside a quote, " -> '' */
	c = '\'';
	q = 0;
	putchar('\'');
      }
    }
    putchar(c);
    c = getchar();
  }
 return EXIT_SUCCESS;
}
