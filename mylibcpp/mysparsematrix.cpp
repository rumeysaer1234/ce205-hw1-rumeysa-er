#include <iostream>
#include "mysparsematrix.h"


#pragma region SPARSE MATRIX FUNCTIONS
/**
* @name initSparseMatrix
* @param [in] row [\b int]
* @param [in] column [\b int]
* @retval [\b MySparseMatrix*]
* A sparse matrix is a matrix with the majority of its elements equal to zero.
**/
MySparseMatrix* initSparseMatrix(int row, int column) {
	MySparseMatrix* sparse = new MySparseMatrix();
	sparse->row = row;
	sparse->col = column;

	std::vector<std::vector<Data*>> vect(row, std::vector<Data*>(column, 0));
	sparse->arr = vect;

	Data* data = new Data(); data->key = 0; data->value = new char[2] { '0' };
	for (int i = 0; i < sparse->row; i++)
		for (int j = 0; j < sparse->col; j++)
			sparse->arr[i][j] = data;

	return sparse;
}
/**
* @name getSparseMatrix
* @param [in] matrix [\b MySparseMatrix*]
* @param [in] row [\b int]
* @param [in] column [\b int]
* @retval [\b Data*]
* This program for the sparse matrix in c allows the user to enter a Matrixs number of rows and columns
**/
Data* getSparseMatrix(MySparseMatrix* matrix, int row, int column) {
	return matrix->arr[row][column];
}
/**
* @name insertSparseMatrix
* @param [in] matrix [\b MySparseMatrix*]
* @param [in] row [\b int]
* @param [in] column [\b int]
* @param [in] data [\b Data*]
* @retval [\b int]
* The sparse matrix used anywhere in the program is sorted according to its row values
* Two elements with the same row values are further sorted according to their column values
**/
int insertSparseMatrix(MySparseMatrix* matrix, int row, int column, Data* data) {
	matrix->arr[row][column] = data;
	return 0;
}
/**
* @name deleteSparseMatrix
* @param [in] matrix [\b MySparseMatrix*]
* @param [in] row [\b int]
* @param [in] column [\b int]
* @retval [\b int]
* serially deletes rows and columns
**/
int deleteSparseMatrix(MySparseMatrix* matrix, int row, int column) {
	Data* data = new Data(); data->key = 0; data->value = new char[2] { '0' };
	matrix->arr[row][column] = data;
	return 0;
}
/**
* @name copySparseMatrix
* @param [in] source [\b MySparseMatrix*]
* @param [in] destination [\b MySparseMatrix*]
* @retval [\b int]
* Returns a copy of this matrix
**/
int copySparseMatrix(MySparseMatrix* source, MySparseMatrix* destination) {
	for (int i = 0; i < source->row; i++)
		for (int j = 0; j < source->col; j++)
			if (source->arr[i][j] != 0)
				destination->arr[i][j] = source->arr[i][j];
	return 0;
}
/**
* @name deleteSparseMatrix
* @param [in] matrix [\b MySparseMatrix*]
* @retval [\b int]
* serially deletes rows and columns
**/
int deleteSparseMatrix(MySparseMatrix* matrix) {
	Data* data = new Data(); data->key = 0; data->value = new char[2] { '0' };
	for (int i = 0; i < matrix->row; i++)
		for (int j = 0; j < matrix->col; j++)
			matrix->arr[i][j] = data;
	return 0;
}
/**
* @name printMatrixToConsole
* @param [in] matrix [\b MySparseMatrix*]
* Function prints contents of linked list starting from start
**/
void printMatrixToConsole(MySparseMatrix* matrix) {
	for (int i = 0; i < matrix->row; i++) {
		if (i != 0) std::cout << std::endl;
		for (int j = 0; j < matrix->col; j++) {
			if (matrix->arr[i][j] != 0)
				std::cout << matrix->arr[i][j] << " ";
			else std::cout << 0 << " ";
		}
	}
}
#pragma endregion