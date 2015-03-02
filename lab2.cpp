#include <iostream>
#include <stdio.h>
using namespace std;

class matrix {


   private : int **matrixA, num_of_rows, num_of_columns;

   public : int** eMatrix(){
      return matrixA;
   }

   public : void create(int rows, int columns){
      num_of_rows=rows;
      num_of_columns=columns;
      matrixA=new int *[num_of_rows];
      for (int count = 0; count < num_of_rows; count++)
         matrixA[count] = new int[num_of_columns];
   }

   public : void create(int d){
      cout<<"enter "<<d<<" matrix's rows\n";
      cin>>num_of_rows;
      cout<<"enter "<<d<<" matrix's columns\n";
      cin>>num_of_columns;
      matrixA=new int *[num_of_rows];
      for (int count = 0; count < num_of_rows; count++)
         matrixA[count] = new int[num_of_columns];

   }

   public : int getRows(){
      return num_of_rows;
   }

   public : int getColumns(){
      return num_of_rows;
   }
   

   public : void getMatrix(int d){
      cout<<"enter the "<<d<<" matrix"<<endl;
      for(int i=0;i<num_of_rows;i++)
         
         for(int j=0;j<num_of_columns;j++)

            cin>>matrixA[i][j];
         
         
      
      }

   public : int ** add(matrix B){
      int **second=B.eMatrix();
      int **sum=new int *[num_of_rows];
      for (int count = 0; count < num_of_rows; count++)
         sum[count] = new int[num_of_columns];

      for ( int c = 0 ; c < num_of_rows ; c++ )
         for ( int d = 0 ; d < num_of_columns ; d++ )
             sum[c][d] = matrixA[c][d] + second[c][d];
      return sum;

   }

   

   public : int ** sub(matrix B){
      int **second=B.eMatrix();
      int **sum=new int *[num_of_rows];
      for (int count = 0; count < num_of_rows; count++)
         sum[count] = new int[num_of_columns];
      for ( int c = 0 ; c < num_of_rows ; c++ )
         for ( int d = 0 ; d < num_of_columns ; d++ )
             sum[c][d] = matrixA[c][d] - second[c][d];
      return sum;

   }

   

   public : matrix mul(matrix B){


      int l,m,z,n;
      l=num_of_rows;
      m=num_of_columns;
      z=B.getRows();
      n=B.getColumns();
      matrix multy;

      if(m!=z){
         cout<<"error in the multiblication enter new dimensions"<<endl;
         return multy;
      }
   


      else{

      int **matrixB=B.eMatrix();
      
      multy.create(l,n);
      int **matrixC=multy.eMatrix();
     
    
      for(int i=0;i<l;i++)
         for(int j=0;j<n;j++){
            matrixC[i][j]=0;
            for(int k=0;k<m;k++){
               matrixC[i][j]=matrixC[i][j]+(matrixA[i][k] * matrixB[k][j]);
            }
         }
         return multy;
      }
      
      
   }

   public : void display (){
      for(int i=0;i<num_of_rows;i++){
         for(int j=0;j<num_of_columns;j++)
            cout<<matrixA[i][j]<<" ";
         
         cout<<endl;
      }
   }
   public : void display (int **matrixC){
      //int *matrixC=new int[num_of_rows][num_of_columns];
      cout<<"your matrix is"<<endl;
      for(int i=0;i<num_of_rows;i++){
         for(int j=0;j<num_of_columns;j++)
            cout<<matrixC[i][j]<<" ";
         
         cout<<endl;
      }
   }  
   



};

int main(){
   int d;
   int **displayMatrix;
   cout<<"enter the number of matrices\n";
   cin>>d;
   matrix m[d];
   for(int i=0;i<d;i++){
      m[i].create(i);
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