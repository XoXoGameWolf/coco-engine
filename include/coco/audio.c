#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

typedef struct {
    uint buffer;
} Audio;

typedef struct {
    uint source;
} AudioSource;

ALCdevice* audioDevice;
ALCcontext* audioContext;

Audio* audios[256];
AudioSource* audioSources[256];

Audio* loadAudio(char* filename) {
    uint buffer;
    alGenBuffers(1, &buffer);

    int size;
    int freq;
    ALenum format;
    void* data;
    ALboolean loop;

    alutLoadWAVFile(filename, &format, &data, &size, &freq, &loop);
    alBufferData(buffer, format, data, size, freq);

    Audio* audio = malloc(sizeof(Audio));
    audio->buffer = buffer;

    for(int i = 0; i < 256; i++) {
        if(audios[i] == 0) {
            audios[i] = audio;
            break;
        }
    }

    return audio;
}

void deleteAudio(Audio* audio) {
    for(int i = 0; i < 256; i++) {
        if(audios[i] == audio) {
            audios[i] = 0;
            break;
        }
    }
    alDeleteBuffers(1, &audio->buffer);
}

AudioSource* createAudioSource(Audio* audio, float pos_x, float pos_y, float pos_z, bool looping) {
    uint source;
    alGenSources(1, &source);

    alSource3f(source, AL_POSITION, pos_x, pos_y, pos_z);
    alSourcei(source, AL_BUFFER, audio->buffer);
    alSourcei(source, AL_LOOPING, looping ? 1 : 0);
    alSourcePlay(source);

    AudioSource* audioSource = malloc(sizeof(AudioSource));
    audioSource->source = source;

    for(int i = 0; i < 256; i++) {
        if(audioSources[i] == 0) {
            audioSources[i] = audioSource;
            break;
        }
    }

    return audioSource;
}

void setAudioSourcePos(AudioSource* source, float pos_x, float pos_y, float pos_z) {
    alSource3f(source->source, AL_POSITION, pos_x, pos_y, pos_z);
}

bool getAudioSourceState(AudioSource* source) {
    int state;
    alGetSourcei(source->source, AL_SOURCE_STATE, &state);
    return state == AL_PLAYING;
}

void deleteAudioSource(AudioSource* source) {
    for(int i = 0; i < 256; i++) {
        if(audioSources[i] == source) {
            audioSources[i] = 0;
            break;
        }
    }
    alDeleteSources(1, &source->source);
}