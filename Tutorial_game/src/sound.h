#include <miniaudio.h>

class Sound {
public:
    Sound(const char* path);
    ~Sound();

    void play(const char* path);

private:
    ma_engine engine;
};
