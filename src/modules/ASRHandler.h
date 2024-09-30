#ifndef ASRHANDLER_H
#define ASRHANDLER_H

#include <QString>

enum ASREngine {
    WHISPER,
    COQUI
};

class ASRHandler {
public:
    ASRHandler(ASREngine engine = WHISPER);  // Initialize with Whisper by default
    QString recognizeSpeech();               // Recognizes speech and returns the transcribed text
private:
    ASREngine engine;                        // Chooses between Whisper and Coqui
};

#endif // ASRHANDLER_H
