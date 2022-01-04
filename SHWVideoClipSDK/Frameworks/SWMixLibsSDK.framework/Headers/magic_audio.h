//
// Created by Wenwu Sun on 2019-07-08.
//

#ifndef MAGIC_AUDIO_H
#define MAGIC_AUDIO_H

#include <string>

namespace mobile {
class MagicAudio {
public:
    int64_t cutStartTs;
    int64_t cutEndTs;
    int64_t mediaDuration;
    std::string mediaUrl;
    bool repeat;
    bool mute;
    double speed;
    float volume;
    int64_t volumeFadeInDuration;
    int64_t volumeFadeOutDuration;
    std::string effect;
    int64_t attachTime;
    int64_t detachTime;

    MagicAudio() {
        cutStartTs = 0;
        cutEndTs = -1;
        mediaDuration = 0;
        repeat = false;
        mute = false;
        volumeFadeInDuration = 0;
        volumeFadeOutDuration = 0;
        speed = 1;
        attachTime = 0;
        detachTime = -1;
        volume = 1;
    }
    
    ~MagicAudio() {
        mediaUrl.clear();
        effect.clear();
    }
};
}


#endif //MAGIC_AUDIO_H
