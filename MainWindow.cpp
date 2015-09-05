#include "MainWindow.hpp"

MainWindow::MainWindow()
  :windowLayout   (new QVBoxLayout)
  ,display        (new QLineEdit)
  ,buttonContainer(new QWidget)
  ,buttonLayout   (new QGridLayout)
{

  display->setReadOnly(true);
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
  display->setText(buttonText);
}
