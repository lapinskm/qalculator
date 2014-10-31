#include <QApplication>

#include "MainWindow.hpp"

int main (int agrc, char* agrv[])
{
  QApplication app(agrc, agrv);
  MainWindow window;

  window.show();

  return app.exec();
}
