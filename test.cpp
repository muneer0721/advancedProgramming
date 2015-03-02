#include <iostream>
#include <stdio.h>
#include "matrix.h"
#include "gtest.h"
using namespace std;


// Tests factorial of 0.
TEST(matrixAdd, HandlesZeroInput) {
   int d,rows,columns;
   int **temp;
   cin>>d;
   matrix m[d];
   for(int i=0;i<d;i++){
       cin>>rows;
      cin>>columns;
      m[i].create(rows,columns);
      m[i].getMatrix(i);
      
   }
  
   temp=m[0].add(m[1]);
   EXPECT_EQ(2, temp[0][0]);
   EXPECT_EQ(2, temp[0][1]);
   EXPECT_EQ(2, temp[1][0]);
   EXPECT_EQ(2, temp[1][1]);

}


TEST(Multiplication, bye) {
   unsigned int d,rows,columns;
   int **temp;
   matrix mu;
   cin>>d;
   matrix m[d];
   for(int i=0;i<d;i++){
     cin>>rows;
     cin>>columns;
      m[i].create(rows,columns);
      m[i].getMatrix(i);
      
   }
   mu=m[0].mul(m[1]);
   temp=mu.eMatrix();
   EXPECT_EQ(2, temp[0][0]);
   EXPECT_EQ(2, temp[0][1]);
   EXPECT_EQ(2, temp[1][0]);
   EXPECT_EQ(2, temp[1][1]);

  
   
}


TEST(MultiplicationandAddition, bye) {
   unsigned int d,rows,columns;
   int **temp;
   matrix mu;
   cin>>d;
   matrix m[d];
   for(int i=0;i<d;i++){
      cin>>rows;
       cin>>columns;
      m[i].create(rows,columns);
      m[i].getMatrix(i);
      
   }
    mu=m[0].mul(m[1]);
   temp=mu.add(m[2]);
   EXPECT_EQ(3, temp[0][0]);
   EXPECT_EQ(3, temp[0][1]);
   EXPECT_EQ(3, temp[1][0]);
   EXPECT_EQ(3, temp[1][1]);
 
   
}





int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


