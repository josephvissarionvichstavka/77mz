#include <QApplication>
#include "views/login/Login.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Login::getInstance().show();
    return QApplication::exec();
}
