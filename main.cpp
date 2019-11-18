#include <iostream>
#include <math.h>
#define SIZE 5

using namespace std;


class Array {
    private:
        int PrivateArr[SIZE];
    public:
        friend void setMatrix(Array Matrix[]);
        friend void coutMatrix(Array Matrix[]);
        friend void FiAij(Array *Matr);
        friend void SortArray(Array  arr[], int n);
        int operator [] (int i){
            return PrivateArr[i];
        }
 };


 void SortArray(Array  arr[], int n)
 {
     for (int i = 0; i < n; i++)
     {
         for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
         {
             for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
             {
                 int LeftBlockIterator = 0;
                 int RightBlockIterator = 0;
                 int LeftBorder = BlockIterator;
                 int MidBorder = BlockIterator + BlockSizeIterator;
                 int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                 RightBorder = (RightBorder < n) ? RightBorder : n;
                 int* SortedBlock = new int[RightBorder - LeftBorder];

                 while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
                 {
                     if (arr[i].PrivateArr[LeftBorder + LeftBlockIterator] < arr[i].PrivateArr[MidBorder + RightBlockIterator])
                     {
                         SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].PrivateArr[LeftBorder + LeftBlockIterator];
                         LeftBlockIterator++;
                     }
                     else
                     {
                         SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].PrivateArr[MidBorder + RightBlockIterator];
                         RightBlockIterator++;
                     }
                 }
                 while (LeftBorder + LeftBlockIterator < MidBorder)
                 {
                     SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].PrivateArr[LeftBorder + LeftBlockIterator];
                     LeftBlockIterator++;
                 }
                 while (MidBorder + RightBlockIterator < RightBorder)
                 {
                     SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].PrivateArr[MidBorder + RightBlockIterator];
                     RightBlockIterator++;
                 }

                 for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                 {
                     arr[i].PrivateArr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
                 }
                 delete[] SortedBlock;

             }

         }
     }
 }


 void setMatrix(Array Matrix[]) {
         for (int i = 0; i < SIZE ; i++) {
             for (int j = 0; j < SIZE ; j++) {
                 cout << "Enter array element №" << j + 1 << endl;
                 cin>>Matrix[i].PrivateArr[j];
             }
         }
 }


 void coutMatrix(Array Matrix[]){
     for (int row = 0; row < SIZE ; row++) {
         for (int column = 0; column < SIZE ; column++) {
             cout << Matrix[column].PrivateArr[row] << "  ";
         }
         cout<<"\n";
     }
 }


void Sum(Array *Matr){
    int row, column, f, F;
    F = 1;
    for (row = 0; row < SIZE - 1; row++){
       f = 0;
       for (column = 1; column < SIZE; column++)
           if (column>row)
           {
               f = f + Matr[column][row];
           }
        
        F *= f;
        cout << "Row " << row + 1 << ":" << " ";
        cout << f << endl;
        
    }
}
void Avg(Array *Matr){
    int row, column, f, F;
    F = 1;
    for (row = 0; row < SIZE - 1; row++){
       f = 0;
       for (column = 1; column < SIZE; column++)
           if (column>row)
           {
               f = f + Matr[column][row];
           }
        
        F *= fabs(f);
    }
    cout << "Avg. geometrical: " << pow(F, 0.25) << endl;
}

/*
 31  65 -83  -2  -85
  9   -2   11  -4   70
 52  73  -8   -1   60
 57  83  -1   82   50
  1   -3   -2   78  -9
 */
 int main(){
     Array Matrix[SIZE];
     cout<<"Input matrix:"<<endl;
     setMatrix(Matrix);
     cout<<"Not-sorted matrix:"<<endl;
     coutMatrix(Matrix);
     cout<<"\n";

     cout<<"Sorted matrix:"<<endl;
     SortArray(Matrix,SIZE);

     coutMatrix(Matrix);
     
     cout << "\n";
     cout<<"Add rows above diagonal:"<<endl;
     Sum(Matrix);

     Avg(Matrix);
     cout << "\n";
     return 0;
 }
