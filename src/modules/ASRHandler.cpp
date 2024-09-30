#include "Python.h"// For calling Python ASR functions
#include "ASRHandler.h"
#include <iostream>

ASRHandler::ASRHandler(ASREngine engine) : engine(engine) {
    // Initialize the Python interpreter
    Py_Initialize();
}

QString ASRHandler::recognizeSpeech() {
    PyObject *pName, *pModule, *pFunc, *pValue;
    
    // Depending on the ASR engine, load the corresponding Python module
    if (engine == WHISPER) {
        pName = PyUnicode_DecodeFSDefault("whisper_module");
    } else {
        pName = PyUnicode_DecodeFSDefault("coqui_stt_module");
    }

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        // Call the recognize function from the loaded Python module
        pFunc = PyObject_GetAttrString(pModule, "recognize");

        if (pFunc && PyCallable_Check(pFunc)) {
            pValue = PyObject_CallObject(pFunc, nullptr);

            if (pValue != nullptr) {
                const char* result = PyUnicode_AsUTF8(pValue);
                Py_DECREF(pValue);
                return QString(result);
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

    return "";
}
