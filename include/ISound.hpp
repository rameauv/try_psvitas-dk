#pragma once

#include <iostream>

class ISound {
    public:
        virtual int Load(const std::string &path) = 0;
};