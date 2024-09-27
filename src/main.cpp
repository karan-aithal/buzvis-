#include <QApplication>
#include "app/BuzvisApp.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create main window (BuzvisApp singleton)
    BuzvisApp* buzvis = BuzvisApp::getInstance();
    buzvis->show();

    return app.exec();
}
