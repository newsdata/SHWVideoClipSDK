//
// Created by Wenwu Sun on 2019-07-03.
//

#ifndef MOBILE_VIDEO_FRAME_H_
#define MOBILE_VIDEO_FRAME_H_

#ifdef MIX_IOS
#include "mix.h"
#else
#include "mix.h"
#endif


namespace mobile {

typedef struct {
    void*   data;
    int     width;
    int     height;
    int64_t pts;     // ms
    int     format;  // RGBA / YUV
    int     linesize;
} VideoFrame;

}  // namespace mobile

#endif  // MOBILE_VIDEO_FRAME_H_
