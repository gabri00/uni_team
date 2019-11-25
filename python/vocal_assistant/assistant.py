import pyttsx3
import speech_recognition as sr
import os
import time


def speak(phrase):
    engine = pyttsx3.init()
    engine.setProperty('rate', 130)
    engine.say(phrase)
    engine.runAndWait()


speak('The quick brown fox jumped over the lazy dog.')


def get_audio():
    r = sr.Recognizer()

    with sr.Microphone() as source:
        audio = r.listen(source)
        said = ''
        try:
            said = r.recognize_google(audio)
            print(said)
        except Exception as e:
            print('Exception: ' + str(e))

    return said


#output = get_audio()

#if 'hello' or 'hi' in output:
#    speak('hello, how are you?')
#elif 'what is your name' in output:
#    speak('My name is Alexa, I\'m your vocal assistant')
