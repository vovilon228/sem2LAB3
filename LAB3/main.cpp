

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ComplexNum.h"
#include "ComplexMatrix.h"
#include "MatrixInverseFactory.h"
#include "TimeMatrixInverseFactory.h"
#include "Tests/doctest.h"

namespace lab {
    int doctest() {
        doctest::Context context;
        return context.run();
    }
    int main() {
      
        int matrixSize = 4;
        ComplexMatrix A(matrixSize, matrixSize);
        A.auto_gen(5, 50, 5, 50);
        std::cout << "Random Matrix A:" << std::endl;
        A.print();


        std::cout << "Choose an inverse algorithm: " << std::endl;
        std::cout << "1. LU Inverse" << std::endl;
        std::cout << "2. Parallel LU Inverse" << std::endl;
        std::cout << "3. Gauss-Jordan Inverse" << std::endl;
        std::cout << "4. Parallel Gauss-Jordan Inverse" << std::endl;

        int algorithmChoice;
        std::cin >> algorithmChoice;

        InverseAlgorithm algorithm;
        switch (algorithmChoice) {
        case 1:
            algorithm = InverseAlgorithm::LU;
            break;
        case 2:
            algorithm = InverseAlgorithm::ParallelLU;
            break;
        case 3:
            algorithm = InverseAlgorithm::GaussJordan;
            break;
        case 4:
            algorithm = InverseAlgorithm::ParallelGaussJordan;
            break;
        default:
            std::cout << "Invalid algorithm choice." << std::endl;
            return 0;
        }

        try {
            MatrixInverseFactory factory;
            ComplexMatrix inverseA = factory.calculateInverse(A, algorithm);
            if (inverseA.getRows() != 0) {
                std::cout << "Inverse Matrix:" << std::endl;
                inverseA.print();
            }
            else {
                std::cout << "Inverse matrix calculation failed." << std::endl;
            }
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }


        return 0;
    }
}

