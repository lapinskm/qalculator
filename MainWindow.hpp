#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#include "MathModule.hpp"

class MainWindow : public QWidget
{
  Q_OBJECT

public:
  MainWindow();

signals:
  void clearDisplay();

private:
  void compute();

private slots:
  void buttonClicked();

private:
//Window parts
  QVBoxLayout* windowLayout;

  QLineEdit*   display;

  QWidget*     buttonContainer;
  QGridLayout* buttonLayout;

//Calculation handling
  MathModule   mathModule;

  QString      operations;
  bool         nextInput;
  bool         displayNeedsCleanup;
  bool         previouslyEqPressed;
};

#endif // MAIN_WINDOW_HPP
