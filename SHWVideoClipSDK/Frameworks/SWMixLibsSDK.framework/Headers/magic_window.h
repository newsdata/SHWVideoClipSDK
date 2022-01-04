//
// Created by Wenwu Sun on 2019-06-30.
//

#ifndef MAGIC_WINDOW_H
#define MAGIC_WINDOW_H

#include "magic_config.h"
#include "magic_view.h"
#include "magic_audio.h"

namespace mobile {
class MagicWindow {

public:
    MagicWindow(){
        Init();
    };

    ~MagicWindow(){
        DeInit();
    };

    MagicConfig *config = nullptr;
    MagicViewGroup *group = nullptr;
    MagicViewGroup *attaches = nullptr;
    std::list<MagicAudio*> audios;


private:
    
    void Init() {
#ifdef MIX_IOS
        config = new MagicConfig();
        group = new MagicViewGroup();
        attaches = new MagicViewGroup();
#endif
    }
    
    void DeInit() {
#ifdef MIX_IOS
        if (config) {
            delete config;
        }
        if (group) {
            delete group;
        }
        
        if (attaches) {
            delete attaches;
        }
        
        if (!audios.empty()) {
            auto item = audios.begin();
            for (; item != audios.end(); item++) {
                MagicAudio* audio = *item;
                if (audio) {
                    delete *item;
                }
            }
            audios.clear();
        }
#endif
    }
    
};
}

#endif //MAGIC_WINDOW_H
