#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <tinywav.h>

typedef unsigned int uint;

typedef struct {
    unsigned int buffer;
} Audio;

typedef struct {
    unsigned int source;
} AudioSource;

ALCdevice* audioDevice;
ALCcontext* audioContext;

Audio* audios[256];
AudioSource* audioSources[256];

Audio* loadAudio(char* filename) {
    unsigned int buffer;
    alGenBuffers(1, &buffer);

    TinyWav tw;

    tinywav_open_read(&tw, (const char*)filename, TW_INTERLEAVED);

    int numSamples = tw.numFramesInHeader * tw.h.NumChannels;
    float* data = malloc(sizeof(float) * numSamples);

    tinywav_read_f(&tw, data, tw.numFramesInHeader);

    short* pcmData = malloc(sizeof(short) * numSamples);
    for (int i = 0; i < numSamples; i++) {
        float clamped = fmaxf(-1.0f, fminf(1.0f, data[i]));
        pcmData[i] = (short)(clamped * 32767.0f);
    }

    free(data);
    tinywav_close_read(&tw);

    ALenum format = (tw.h.NumChannels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;

    alBufferData(
        buffer,
        format,
        pcmData,
        numSamples * sizeof(short),
        tw.h.SampleRate
    );

    free(pcmData);

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
    unsigned int source;
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