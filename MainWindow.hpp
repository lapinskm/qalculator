#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP


#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class MainWindow : public QWidget
{
  Q_OBJECT

public:
   MainWindow();

private slots:
   void buttonClicked();
private:
   QVBoxLayout* windowLayout;

   QLineEdit*   display;

   QWidget*     buttonContainer;
   QGridLayout* buttonLayout;
};

#endif // MAIN_WINDOW_HPP
