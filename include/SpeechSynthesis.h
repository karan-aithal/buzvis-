#ifndef SPEECHSYNTHESIS_H
#define SPEECHSYNTHESIS_H

#include <QString>

class SpeechSynthesis {
public:
    SpeechSynthesis();
    void synthesizeSpeech(const QString &text);  // Converts text to speech using StyleTTS
};

#endif // SPEECHSYNTHESIS_H
