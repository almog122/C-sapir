using System;
using System.Collections.Generic;
using System.Text;

namespace Targil_12_TestCase
{
    public class Calculator
    {
        public static int Square(int num)
        {
            return num * num;
        }

        public static int Add(int num1, int num2)
        {
            return num1 + num2;
        }

        public static double Add(double num1, double num2)
        {
            return num1 + num2;
        }

        public static int Multiply(int num1, int num2)
        {
            return num1 * num2;
        }

        public static int Subtract(int num1, int num2)
        {
            if (num1 > num2)
            {
                return num1 - num2;
            }
            return num2 - num1;
        }


    }

    //	[Test]
    //	[TestCase(2, 4)]
    //	[TestCase(4, 2)]
    //	[TestCase(3, 5)]
    //	[TestCase(5, 3)]
    //	[TestCase(6, 6)]
    //public void TestCalculatorSquare(int input, int expected)
    //{
    //	Calculator calculator = new Calculator();

    //	Assert.That(calculator.Square(input), Is.EqualTo(expected), "Error message");
    //	}

    //[Test]
    //[TestCase(2,2, 4)]
    //[TestCase(4,3, 8)]
    //[TestCase(3,2, 5)]
    //[TestCase(5,0, 3)]
    //[TestCase(6,6, 6)]
    //public void TestCalculatorAdd(int input1, int input2, int expected)
    //{
    //	Calculator calculator = new Calculator();

    //	Assert.That(calculator.Add(input1 , input2), Is.EqualTo(expected), "Error message");
    //}
}
