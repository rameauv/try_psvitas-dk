#include "Animation.hpp"

int Animation::load(const vita2d_texture* texture, int duration, int col, int line) {
    _texture = texture;
    _duration = duration;
    _col = col;
    _line = line;
    _spriteWidth = vita2d_texture_get_width(texture) / col;
    _spriteHeight = vita2d_texture_get_width(texture) / line;
}

void Animation::draw(float x, float y, float x_scale, float y_scale, float rotate) {
    if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _lastAnimTime).count() < _duration) {
        vita2d_draw_texture_part_scale_rotate(_texture, x, y, _currentCol * _spriteWidth, _currentLine * _spriteHeight, _spriteWidth, _spriteHeight, x_scale, y_scale, rotate);
        return;
    }
    _lastAnimTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
    _currentCol++;
    if (_currentCol > _col) {
        _currentCol = 0;
        _currentLine++;
    }
    if (_currentLine > _line) {
        _currentCol = 0;
        _currentLine = 0;
    }
    vita2d_draw_texture_part_scale_rotate(_texture, x, y, _currentCol * _spriteWidth, _currentLine * _spriteHeight, _spriteWidth, _spriteHeight, x_scale, y_scale, rotate);
}

const vita2d_texture* Animation::getTexture() const {
    return (_texture);
}