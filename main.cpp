#include "blured.h"


using namespace std;

int main(int argc, char** argv)
{
  QApplication a(argc, argv);
  CallerBlur blured;
  blured.resize(100, 400);
  blured.show();
  return a.exec();
}
