#include "audio.h"

Audio::Audio() { 
    ma_engine_init(nullptr, &this->engine); 
}
Audio::~Audio() {
    ma_engine_uninit(&this->engine); 
}

void Audio::play(const char* path) {
    ma_engine_play_sound(&this->engine, path, nullptr);
}
