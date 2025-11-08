#include "sound.h"

Sound::Sound() { 
    ma_engine_init(nullptr, &this->engine); 
}
Sound::~Sound() {
    ma_engine_uninit(&this->engine); 
}

void Sound::play(const char* path) {
    ma_engine_play_sound(&this->engine, path, nullptr);
}
