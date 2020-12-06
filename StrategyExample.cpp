//BenjaminKramer
//12-6-2020

//An illustration of how a Strategy Design Pattern
//functions using the format of a simple calculator
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

//Strategy class
class Strategy {
    public:
      virtual int doOperation(int num1, int num2) = 0;
};

//Addition Operation
class OperationAdd:public Strategy {
    public:
      int doOperation(int num1, int num2) {
        return num1 + num2;
      }
};

//Subtraction Operation
class OperationSubstract:public Strategy {

    public:
      int doOperation(int num1, int num2) {
        return num1 - num2;
      }
};

//Multiplication Opertation
class OperationMultiply:public Strategy {

   public:
      int doOperation(int num1, int num2) {
        return num1 * num2;
      }
};

//Squared Opertation
class OperationSquared:public Strategy {

   public:
      int doOperation(int num1, int num2) {
        return num1 * num1;
      }
};

//Power of Three Opertation
class OperationPow3:public Strategy {

   public:
      int doOperation(int num1, int num2) {
        return num1 * num1 * num1;
      }
};

//Division Operation
class OperationDivide:public Strategy {

    public:
      int doOperation(int num1, int num2) {
        return num1 / num2;
      }
};

//Square Root Operation
class OperationSquareRoot:public Strategy {

    public:
      int doOperation(int num1, int num2) {
        return sqrt(num2);
      }
};

//Implementing the Strategy Design Pattern
class Context {
  private:
    Strategy *strategy;

  public:
    Context(Strategy *new_strategy){
      strategy = new_strategy;
    }
   
    void changeStrategy(Strategy *new_strategy){
      strategy = new_strategy;
    }

    int executeStrategy(int num1, int num2){
      return strategy->doOperation(num1, num2);
   }
};

//main
int main() {
  OperationAdd add_strategy;
  Context context(&add_strategy);		
  cout << "10 + 5 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationSubstract subtract_strategy;
  context.changeStrategy(&subtract_strategy);
  cout << "10 - 5 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationMultiply multiply_strategy;
  context.changeStrategy(&multiply_strategy);
  cout << "10 * 5 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationDivide divide_strategy;
  context.changeStrategy(&divide_strategy);
  cout << "10 / 5 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationSquared squared_strategy;
  context.changeStrategy(&squared_strategy);
  cout << "10 ^ 2 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationPow3 pow3_strategy;
  context.changeStrategy(&pow3_strategy);
  cout << "10 ^ 3 = ";
  cout << context.executeStrategy(10, 5);
  cout << "\n";

  OperationSquareRoot squareroot_strategy;
  context.changeStrategy(&squareroot_strategy);
  cout << "sqrt(100) = ";
  cout << context.executeStrategy(10, 100);
  cout << "\n";
}
