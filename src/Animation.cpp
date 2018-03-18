#include "Animation.hpp"

int Animation::load(const vita2d_texture* texture, int duration, int col, int line) {
    _texture = texture;
    _duration = duration;
    _col = col;
    _line = line;
    _sprite_width = vita2d_texture_get_width(texture) / col;
    _sprite_height = vita2d_texture_get_width(texture) / line;
}

void Animation::draw(float x, float y, float x_scale, float y_scale, float rotate) {
    if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _lastAnimTime).count() < _duration) {
        vita2d_draw_texture_part_scale_rotate(_texture, x, y, _current_col * _sprite_width, _current_line * _sprite_height, _sprite_width, _sprite_height, x_scale, y_scale, rotate);
        return;
    }
    _lastAnimTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
    _current_col++;
    if (_current_col > _col) {
        _current_col = 0;
        _current_line++;
    }
    if (_current_line > _line) {
        _current_col = 0;
        _current_line = 0;
    }
    vita2d_draw_texture_part_scale_rotate(_texture, x, y, _current_col * _sprite_width, _current_line * _sprite_height, _sprite_width, _sprite_height, x_scale, y_scale, rotate);
}

const vita2d_texture* Animation::getTexture() const {
    return (_texture);
}