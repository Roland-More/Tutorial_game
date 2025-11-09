#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <string>
#include <unordered_map>

#include "miniaudio.h"


class AudioManager
{
public:
    AudioManager();
    ~AudioManager();

    void loadSound(const char* path, std::string name);
    void play(std::string name);
    void setLooping(std::string name, bool loop_state);

private:
    ma_engine engine;

    std::unordered_map<std::string, ma_sound> sounds;
};

#endif
