#include "BuzvisApp.h"
#include "../ui/mainwindow.h"

BuzvisApp* BuzvisApp::instance = nullptr;

BuzvisApp* BuzvisApp::getInstance() {
    if (instance == nullptr) {
        instance = new BuzvisApp();
    }
    return instance;
}

BuzvisApp::BuzvisApp(QWidget* parent) : QMainWindow(parent) {
    // Setup the main UI
    MainWindow* mainWindow = new MainWindow(this);
    setCentralWidget(mainWindow);
}

void BuzvisApp::show() {
    QMainWindow::show();
}
