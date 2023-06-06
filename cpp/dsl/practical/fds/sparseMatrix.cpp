#include <bits/stdc++.h>
using namespace std;

const int column =3;

int countNonZeroElement(int matrix[][column], int matrixRow, int matrixColumn)
{
	// to count no of non zero element
	int non_zero_element_count =0;
	for (int x=0; x<matrixRow; x++)
	{
		for (int y=0; y<matrixColumn; y++)
		{
			if (matrix[x][y] != 0)
				non_zero_element_count++;
		}
	}
	
	return non_zero_element_count;
}

void sparseBuilder(int** matrix, int matrixRow, int matrixColumn, int** sparseMatrix)
{	
	//cout << non_zero_element_count << endl;
	int non_zero_element_count =countNonZeroElement(&matrix[0][0], matrixRow, matrixColumn);
	//build sparse matrix
	//sparseMatrix[non_zero_element_count+1][3];
	sparseMatrix[0][0] =matrixRow;
	sparseMatrix[0][1] =matrixColumn;
	sparseMatrix[0][2] =non_zero_element_count;
	int sparseMatrixIndex =1;
	for (int x=0; x<matrixRow; x++){
		for (int y=0; y<matrixColumn; y++){
			if (matrix[x][y] != 0){
				sparseMatrix[sparseMatrixIndex][0] =x;
				sparseMatrix[sparseMatrixIndex][1] =y;
				sparseMatrix[sparseMatrixIndex][2] =matrix[x][y];
				sparseMatrixIndex++;
			}
		}
	}
	
}

void printSparseMatrix(int** sparseMatrix, int non_zero_element_count)
{
	for (int i=0; i<non_zero_element_count+1; i++)
		cout << sparseMatrix[i][0] << " " << sparseMatrix[i][1] << " " << sparseMatrix[i][2] << endl;	
}

int main()
{
	// matrix initialized
	int matrixRow=3, matrixColumn =3;
	int matrix[matrixRow][matrixColumn] =
	{
		{0,1,0},
		{2,0,4},
		{0,3,0}
	};
	
	int non_zero_element_count1 =countNonZeroElement(matrix, matrixRow, matrixColumn);
	int sparseMatrix1[non_zero_element_count1+1][3];
	//sparseBuilder(matrix, matrixRow, matrixColumn, sparseMatrix1);
	
	//print sparse matrix
	//printSparseMatrix(sparseMatrix1, non_zero_element_count1);
	//for (int i=0; i<non_zero_element_count1+1; i++)
	//	cout << sparseMatrix1[i][0] << " " << sparseMatrix1[i][1] << " " << sparseMatrix1[i][2] << endl;	

	
	
}