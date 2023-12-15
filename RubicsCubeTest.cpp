#include "pch.h"
#include "CppUnitTest.h"
#include "./../Project1/RubicsCube.h";
#include "./../Project1/RubicsCube.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RubicsCubeTest
{
	TEST_CLASS(RubicsCubeTest)
	{
	public:
        TEST_METHOD(FileLoadTest)
        {
            RubicsCube cube;
            cube.loadFromFile("C:/Users/Kirill/my_data/work/bsuir/sem_3/ppois/lab1/Project1/fileColors2.txt");
            Assert::IsTrue(cube.isSolved());
        }
        TEST_METHOD(InitializationTest)
        {
            RubicsCube cube;
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest)
        {
            RubicsCube cube;
            cube.rotateFace(0, true);   
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest2)
        {
            RubicsCube cube;
            cube.rotateFace(1, true);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest3)
        {
            RubicsCube cube;
            cube.rotateFace(2, true);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest4)
        {
            RubicsCube cube;
            cube.rotateFace(3, true);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest5)
        {
            RubicsCube cube;
            cube.rotateFace(4, true);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTes6)
        {
            RubicsCube cube;
            cube.rotateFace(5, true);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest7)
        {
            RubicsCube cube;
            cube.rotateFace(0, false);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest8)
        {
            RubicsCube cube;
            cube.rotateFace(1, false);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest9)
        {
            RubicsCube cube;
            cube.rotateFace(2, false);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest10)
        {
            RubicsCube cube;
            cube.rotateFace(3, false);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest11)
        {
            RubicsCube cube;
            cube.rotateFace(4, false);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTest12)
        {
            RubicsCube cube;
            cube.rotateFace(5, false);
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(RotationTestFromFile)
        {
            RubicsCube cube;
            cube.loadFromFile("C:/Users/Kirill/my_data/work/bsuir/sem_3/ppois/lab1/Project1/fileColors.txt");
            cube.rotateFace(0, false);
            Assert::IsTrue(cube.isSolved());
		}
        TEST_METHOD(FileLoadTest2)
        {
            RubicsCube cube;
            cube.loadFromFile("C:/Users/Kirill/my_data/work/bsuir/sem_3/ppois/lab1/Project1/fileColors3.txt");
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(FileLoadTest3)
        {
            RubicsCube cube;
            cube.loadFromFile("C:/Users/Kirill/my_data/work/bsuir/sem_3/ppois/lab1/Project1/fileColors4.txt");
            Assert::IsFalse(cube.isSolved());
        }
        TEST_METHOD(FileLoadTest4)
        {
            RubicsCube cube;
            cube.loadFromFile("C:/Users/Kirill/my_data/work/bsuir/sem_3/ppois/lab1/Project1/fileColors5.txt");
            Assert::IsFalse(cube.isSolved());
        }
	};
}