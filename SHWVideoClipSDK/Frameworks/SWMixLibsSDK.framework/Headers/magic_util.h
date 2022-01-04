//
// Created by Wenwu Sun on 2019-07-03.
//

#ifndef ANDROID_MAGIC_UTIL_H
#define ANDROID_MAGIC_UTIL_H

#ifdef MIX_IOS
#include "mix.h"
#include "mobile_player_controller.h"
#else
#include "mix.h"
#include "mobile_player_controller.h"
#endif

#include "magic_window.h"

namespace mobile {

int64_t getNanoTime(int64_t timeIns);

void GetAudioVolumes(const char* path, double* volumes, int* len);

double GetFloatFormatVolume(uint8_t* data, int size);

void GetSnapshots(void* handle,
                  const char* path,
                  int64_t start, int64_t end,
                  int w, int h,
                  int64_t interval,
                  void callback(void *, void *, mobile::VideoFrame*),
                  void *env,
                  void *capture);

/*int64_t getMilliTime(int64_t timeIns);

int64_t getTimeIns(int64_t MilliSec);*/

class MagicUtil {

public:
    MagicUtil() {};

    ~MagicUtil() {};

    void changeMagicWindow(MagicWindow *window,
                           mix::engine::Config_t *config,
                           mix::engine::MediaViews_t *mediaViews,
                           mix::engine::Audios_t *audios,
                           Subtitles_t* subtitles,
                           int startIndex = 0,
                           int endIndex = -1);
    
    static void getFontPathWithName(const std::string fontName, std::string &fontPath);

private:
    void changeMagicConfig(MagicConfig* config,
                           mix::engine::Config_t* config_t);

    void changeVideoGroup(MagicViewGroup *group,
                          mix::engine::Config_t *configInfo,
                          mix::engine::MediaViews_t *views,
                          int64_t *bodyTime,
                          int startIndex,
                          int endIndex);

    void changeAttachGroup(MagicViewGroup *attaches,
                           mix::engine::Config_t *configInfo,
                           mix::engine::MediaViews_t *views,
                           Subtitles_t* subtitles,
                           int64_t bodyTime);

    void changeAudios(MagicWindow* window,
                      mix::engine::Config_t *configInfo,
                      mix::engine::Audios_t* audios);

    void changeFilter(mix::engine::MediaView_t *view, std::list<Filter*> &filters);

    void createTransitionView(mix::engine::Transition_t *transition_t, mix::engine::MediaView_t &view_t);
};
}

#endif //ANDROID_MAGIC_UTIL_H
