//
// Created by Wenwu Sun on 2019-07-01.
//

#ifndef MAGIC_CONFIG_H
#define MAGIC_CONFIG_H

namespace mobile {
class MagicConfig {

public:
    MagicConfig(){};
    MagicConfig(int fps, int width, int height, int64_t cutStartTime, int64_t cutEndTime) {
        this->fps = fps;
        this->width = width;
        this->height = height;
        this->cutStartTime = cutStartTime;
        this->cutEndTime = cutEndTime;
    }
    virtual ~MagicConfig(){};

    int fps = 0;
    int width = 0;
    int height = 0;
    int64_t cutStartTime = 0;
    int64_t cutEndTime = -1;
};
}

#endif //MAGIC_CONFIG_H
