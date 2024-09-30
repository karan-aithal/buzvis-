import whisper

model = whisper.load_model("base")  # Load the Whisper ASR model

def recognize():
    # Record audio (implement audio recording logic here, or load a file)
    # Assuming you record audio for a few seconds and save it to 'audio.wav'
    result = model.transcribe("audio.wav")
    return result['text']
