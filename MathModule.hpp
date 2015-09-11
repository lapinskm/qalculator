#ifndef MATH_MODULE_HPP
#define MATH_MODULE_HPP

#include <cmath>
#include <QString>

class MathModule
{
public:
  void setFirstOperand(double value);
  void setSecondOperand(double value);
  void setOperationSign(QString sign);
  double PerformOperation();

private:
  double firstOperand;
  double secondOperand;
  QString operationSign;
};

#endif // MATH_MODULE_HPP
