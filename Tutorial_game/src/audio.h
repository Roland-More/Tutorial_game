#include "miniaudio.h"

class Audio {
public:
    Audio();
    ~Audio();

    void play(const char* path);

private:
    ma_engine engine;
};
