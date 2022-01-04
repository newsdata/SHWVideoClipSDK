/*
 * Copyright (c) 2018 xhzy
 *
 */

#ifndef MOBILE_AUDIO_FRAME_H_
#define MOBILE_AUDIO_FRAME_H_

#ifdef MIX_IOS
#include "mix.h"
#else
#include "mix.h"
#endif


namespace mobile {

typedef struct {
    void*    data[8];         // 音频数据
    int      linesize[8];     //
    int      sample_rate;     // 音频采样率
    int      nb_samples;      // 每个通道采样点个数
    uint64_t channel_layout;  // Channel layout of the audio data
    int      channels;        // 通道数
    int64_t  pts;             // ms
} AudioFrame;

}  // namespace mobile

#endif  // MOBILE_AUDIO_FRAME_H_
