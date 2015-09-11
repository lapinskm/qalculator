#include "MainWindow.hpp"
MainWindow::MainWindow()
  :windowLayout       (new QVBoxLayout)
  ,display            (new QLineEdit("0"))
  ,buttonContainer    (new QWidget)
  ,buttonLayout       (new QGridLayout)
  ,operations         ("+-*/=")
  ,nextInput          (false)
  ,displayNeedsCleanup(true)
  ,previouslyEqPressed(false)
{
  display->setReadOnly(true);
  display->setAlignment(Qt::AlignRight);
  windowLayout->addWidget(display);

  const int buttonRows = 4;
  const int buttonCols = 4;
  QString ButtonStrings[] = {"7","8","9","/",
                             "4","5","6","*",
                             "1","2","3","-",
                             "0",".","=","+"};

  int k = 0;
  for(int i = 0; i < buttonRows; i++)
  {
    for (int j = 0; j < buttonCols; j++)
    {
      QPushButton* button = new QPushButton(ButtonStrings [k]);
      connect(button, SIGNAL (released()), this, SLOT (buttonClicked()));
      buttonLayout->addWidget(button, i, j);
      k++;
    }
  }

  buttonContainer->setLayout(buttonLayout);
  windowLayout->addWidget(buttonContainer);
  this->setLayout(windowLayout);
}

void MainWindow::buttonClicked()
{
  QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
  QString buttonText = clickedButton->text();

  bool isNumber;

  QString extendedInput=display->text()+buttonText;
  extendedInput.toDouble(&isNumber);
  if(isNumber)
  {
    if(displayNeedsCleanup)
    {
      display->setText(buttonText);
      displayNeedsCleanup = false;
    }
    else
      display->setText(extendedInput);

    previouslyEqPressed = false;
  }

  else if(operations.contains(buttonText))
  {
    if("=" == buttonText)
    {
      if(!previouslyEqPressed)
        mathModule.setSecondOperand(display->text().toDouble());

      if(nextInput || previouslyEqPressed)
      {
        compute();
        previouslyEqPressed = true;
      }
    }
    else
    {
      if(nextInput)
      {
        mathModule.setSecondOperand(display->text().toDouble());
        compute();
      }
      else
        mathModule.setFirstOperand(display->text().toDouble());

      mathModule.setOperationSign(buttonText);
      nextInput = true;
      previouslyEqPressed = false;
    }
    displayNeedsCleanup = true;
  }
}

void MainWindow::compute()
{
  double result = mathModule.PerformOperation();
  display->setText(QString().setNum(result));
  nextInput = false;
}

