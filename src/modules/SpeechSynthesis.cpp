#include "SpeechSynthesis.h"
#include <Python.h>  // For calling Python TTS functions
#include <iostream>

SpeechSynthesis::SpeechSynthesis() {
    // Initialize the Python interpreter
    Py_Initialize();
}

void SpeechSynthesis::synthesizeSpeech(const QString &text) {
    PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;
    
    // Load the Python module for StyleTTS
    pName = PyUnicode_DecodeFSDefault("style_tts_module");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        // Call the synthesize function in style_tts_module.py
        pFunc = PyObject_GetAttrString(pModule, "synthesize");

        if (pFunc && PyCallable_Check(pFunc)) {
            // Pass the text as an argument to the Python function
            pArgs = PyTuple_Pack(1, PyUnicode_FromString(text.toUtf8().constData()));
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue != nullptr) {
                Py_DECREF(pValue);
            } else {
                PyErr_Print();
                std::cerr << "Error in Python function call" << std::endl;
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        std::cerr << "Failed to load Python module" << std::endl;
    }
}
