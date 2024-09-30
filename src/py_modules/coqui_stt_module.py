import sounddevice as sd
import numpy as np
import stt
import os

model_path = "path_to_your_coqui_model"
model = stt.Model(model_path)

def recognize():
    # Record audio using sounddevice
    duration = 5  # seconds
    sample_rate = 16000
    print("Recording audio for speech recognition...")
    audio_data = sd.rec(int(duration * sample_rate), samplerate=sample_rate, channels=1, dtype='int16')
    sd.wait()

    # Convert audio data to format Coqui STT can recognize
    audio_data = np.squeeze(audio_data)
    text = model.stt(audio_data)
    return text
