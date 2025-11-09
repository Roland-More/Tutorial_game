#include <iostream>

#include "audio_manager.h"


AudioManager::AudioManager()
{ 
    ma_result result;

    result = ma_engine_init(nullptr, &this->engine);
    if (result != MA_SUCCESS)
    {
        std::cerr << "Failed to initialize audio engine\n";
    }
}
AudioManager::~AudioManager()
{
    for (auto& sound : this->sounds)
    {
        ma_sound_uninit(sound.second);
    }
    ma_engine_uninit(&this->engine); 
}

void AudioManager::loadSound(const char* path, std::string name)
{
    ma_result result;
    ma_sound* sound = new ma_sound();

    result = ma_sound_init_from_file(&this->engine, path, 0, nullptr, nullptr, sound);
    if (result != MA_SUCCESS)
    {
        std::cerr << "Failed to load sound file\n";
    }
    this->sounds[name] = sound;
}

void AudioManager::setLooping(std::string name, bool loop_state)
{
    ma_sound_set_looping(this->sounds[name], loop_state);
}

void AudioManager::play(std::string name)
{
    ma_sound* sound = this->sounds[name];
    if (ma_sound_is_playing(sound)) 
    {
        ma_sound_seek_to_pcm_frame(sound, 0);
    }
    ma_sound_start(sound);
}
