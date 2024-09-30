from TTS.api import TTS
import sounddevice as sd
import numpy as np

tts = TTS(model_name="tts_models/en/ljspeech/tacotron2-DDC", progress_bar=False)

def synthesize(text):
    # Synthesize speech from text
    wav = tts.tts(text)
    sd.play(wav, samplerate=22050)
    sd.wait()
