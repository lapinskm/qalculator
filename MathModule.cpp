#include "MathModule.hpp"

void MathModule::setFirstOperand(double value)
{
  firstOperand = value;
}

void MathModule::setSecondOperand(double value)
{
  secondOperand = value;
}

void MathModule::setOperationSign(QString sign)
{
  operationSign = sign;
}

double MathModule:: PerformOperation()
{
  if("+" == operationSign)
    firstOperand += secondOperand;

  else if("-" == operationSign)
    firstOperand -= secondOperand;

  else if("*" == operationSign)
    firstOperand *= secondOperand;

  else if("/" == operationSign)
  {
    if (0 == secondOperand)
      return NAN;
    firstOperand /= secondOperand;
  }
  else return NAN;

  return firstOperand;
}

