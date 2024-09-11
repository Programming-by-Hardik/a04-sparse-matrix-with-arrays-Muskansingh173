// sparse_matrix_assignment.c
// This program represents a sparse matrix using a 2D array in C and includes test cases.

#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of non-zero elements in the sparse matrix
#define N 4      // Number of columns in the original matrix (modifiable)

// Function prototypes
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][N], int rows, int cols);
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount);
bool testCreateSparseMatrix();
bool testPrintSparseMatrix();

int main() {
    // Run test cases
    if (testCreateSparseMatrix()) {
        printf("testCreateSparseMatrix PASSED\n");
    } else {
        printf("testCreateSparseMatrix FAILED\n");
    }

    if (testPrintSparseMatrix()) {
        printf("testPrintSparseMatrix PASSED\n");
    } else {
        printf("testPrintSparseMatrix FAILED\n");
    }

    return 0;
}

// Function to convert a matrix into sparse matrix format
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][N], int rows, int cols) {
    //WRITE THE FUNCTION DESCRIPTION HERE
     Certainly! 




    

    // Iterate over the original matrix to find non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (originalMatrix[i][j] != 0) {
                // Store the non-zero element in the sparse matrix
                sparseMatrix[count + 1][0] = i;
                sparseMatrix[count + 1][1] = j;
                sparseMatrix[count + 1][2] = originalMatrix[i][j];
                count++;
            }
        }
    }

    // Set the first row of the sparse matrix to represent the size and count
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = count;
}


// Function to print sparse matrix representation
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount) {
    //WRITE THE FUNCTION DESCRIPTION HERE
    

Certainly! Here's how you can complete the createSparseMatrix and printSparseMatrix functions based on the descriptions given:

1. createSparseMatrix
Description: Converts an original matrix into its sparse matrix representation. The sparse matrix format is a 2D array where each row represents a non-zero element in the original matrix. The first row of the sparse matrix specifies the dimensions of the original matrix and the number of non-zero elements.

c
Copy code
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][N], int rows, int cols) {
    int count = 0;

    // Iterate over the original matrix to find non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (originalMatrix[i][j] != 0) {
                // Store the non-zero element in the sparse matrix
                sparseMatrix[count + 1][0] = i;
                sparseMatrix[count + 1][1] = j;
                sparseMatrix[count + 1][2] = originalMatrix[i][j];
                count++;
            }
        }
    }

    // Set the first row of the sparse matrix to represent the size and count
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = count;
}
2. printSparseMatrix
Description: Prints the sparse matrix in a readable format. The first row of the sparse matrix shows the dimensions of the original matrix and the number of non-zero elements, and the following rows show the position and value of each non-zero element.

c
Copy code
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount) {
    // Print the dimensions of the original matrix and number of non-zero elements
    printf("Dimensions: %d x %d\n", sparseMatrix[0][0], sparseMatrix[0][1]);
    printf("Number of non-zero elements: %d\n", sparseMatrix[0][2]);
    printf("Row  Column  Value\n");

    // Print each non-zero element
    for (int i = 1; i <= nonZeroCount; i++) {
        printf("%d      %d       %d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}
Explanation:
createSparseMatrix:

It initializes count to keep track of the number of non-zero elements.
Iterates through the original matrix, checking for non-zero elements.
Stores each non-zero element's row index, column index, and value in the sparseMatrix.
Sets the first row of sparseMatrix to indicate the dimensions of the original matrix and the number of non-zero elements.
printSparseMatrix:

Prints the dimensions of the original matrix and the number of non-zero elements.
Iterates over the sparse matrix and prints each non-zero element's position and value.
These implementations should fulfill the requirements outlined in your code and the test cases provided.






}

//--------------------------------------------------------
//DON'T CHANGE THE CODE BELOW THIS!
//--------------------------------------------------------
// TEST CASES

// Test function for createSparseMatrix
bool testCreateSparseMatrix() {
    int originalMatrix[4][N] = {
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {0, 0, 0, 5},
        {0, 2, 0, 6}
    };

    int expectedSparseMatrix[MAX][3] = {
        {4, 4, 5},   // 4x4 matrix with 5 non-zero elements
        {0, 2, 3},   // Original matrix[0][2] = 3
        {1, 1, 4},   // Original matrix[1][1] = 4
        {2, 3, 5},   // Original matrix[2][3] = 5
        {3, 1, 2},   // Original matrix[3][1] = 2
        {3, 3, 6}    // Original matrix[3][3] = 6
    };

    int sparseMatrix[MAX][3];
    createSparseMatrix(sparseMatrix, originalMatrix, 4, N);

    // Compare the sparseMatrix with the expectedSparseMatrix
    for (int i = 0; i <= expectedSparseMatrix[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            if (sparseMatrix[i][j] != expectedSparseMatrix[i][j]) {
                return false;  // If any value doesn't match, test fails
            }
        }
    }

    return true;  // Test passes if all values match
}

// Test function for printSparseMatrix
bool testPrintSparseMatrix() {
    // Define a sparse matrix with 5 non-zero elements
    int sparseMatrix[MAX][3] = {
        {4, 4, 5},   // 4x4 matrix with 5 non-zero elements
        {0, 2, 3},   // Original matrix[0][2] = 3
        {1, 1, 4},   // Original matrix[1][1] = 4
        {2, 3, 5},   // Original matrix[2][3] = 5
        {3, 1, 2},   // Original matrix[3][1] = 2
        {3, 3, 6}    // Original matrix[3][3] = 6
    };

    // Simulate a successful print (visual inspection may be needed for testing this)
    printf("Expected Sparse Matrix Output:\n");
    printSparseMatrix(sparseMatrix, sparseMatrix[0][2]);

    // Since printSparseMatrix only prints the output, we assume it passes if the format is correct
    return true;
}
