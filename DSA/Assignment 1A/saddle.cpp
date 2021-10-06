#include<stdio.h>

int main() {

   int a[ 10][10], i, j, num;
   int sm, p, large, f = 1;

   printf("Enter size of matrix:");
   scanf("%d", & num);

   printf("Enter 2D array elements:");
   for (i = 0; i < num; i++) {
       for (j = 0; j < num; j++) {
           scanf("%d", & a[i][j]);
       }
   }

   for (i = 0; i < num; i++) {
       p = 0;
       sm = a[i][0];
       for (j = 0; j < num; j++) {
           if (sm > a[i][j]) {
               sm = a[i][j];
               p = j;
           }
       }

       large = 0;
       for (j = 0; j < num; j++) {
           if (large < a[j][p]) {
               large = a[j][p];
           }
       }
       if (sm == large) {
           printf("\nValue of saddle point:%d", sm);
           f = 0;
       }
   }

   if (f > 0)
       printf("\nNo saddle point");

   return 0;
}