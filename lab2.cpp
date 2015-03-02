#include <iostream>
#include <stdio.h>
#include "matrix.h"
using namespace std;



int main(){
   int d,rows,columns;
   int **displayMatrix;
   cout<<"enter the number of matrices\n";
   cin>>d;
   matrix m[d];
   for(int i=0;i<d;i++){
      cout<<"enter the elements of "<<i<<" matrix"<<endl;
      cout<<"enter "<<i<<" matrix's number of rows\n";
      cin>>rows;
      cout<<"enter "<<i<<" matrix's number of columns\n";
      cin>>columns;
      m[i].create(rows,columns);
      m[i].getMatrix(i);
      m[i].display();
      
   }
   //m[0].add(m[1]);
   
   displayMatrix=m[0].add(m[1]);
   m[0].display(displayMatrix);

   displayMatrix=m[0].sub(m[1]);
   m[0].display(displayMatrix);

   matrix u=m[0].mul(m[1]);
   //cout<<u.getColumns();
   
   u.display(); 
   


   return 0;
}