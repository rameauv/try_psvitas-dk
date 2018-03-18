#pragma once

#include <vita2d.h>
#include <chrono>

class Animation {
    private:
        const vita2d_texture* _texture;
        int _col;
        int _line;
        int _sprite_width;
        int _sprite_height;
        int _current_line;
        int _current_col;
        int _duration;
        std::chrono::time_point<std::chrono::high_resolution_clock> _lastAnimTime;
    public:
        int load(const vita2d_texture*, int, int, int);
        void draw(float, float, float, float, float);
        const vita2d_texture* getTexture() const;
};