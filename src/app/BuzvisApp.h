#ifndef BUZVISAPP_H
#define BUZVISAPP_H

#include <QMainWindow>

class BuzvisApp : public QMainWindow {
    Q_OBJECT
public:
    static BuzvisApp* getInstance();
    void show();
private:
    explicit BuzvisApp(QWidget* parent = nullptr);
    static BuzvisApp* instance;
};

#endif // BUZVISAPP_H
