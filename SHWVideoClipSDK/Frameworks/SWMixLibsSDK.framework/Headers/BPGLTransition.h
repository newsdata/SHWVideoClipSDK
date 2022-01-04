//
//  BPGLTransition.hpp
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/11.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#ifndef BPTransition_hpp
#define BPTransition_hpp

#include <stdio.h>
#include "skia.h"

struct MixGPUImageTransition;

namespace ios {
    
class BPGLTransition {
public:
    BPGLTransition(int width, int height, const char *name, int64_t duration, int64_t offset = 0, float nBaseLevel = 0);
    ~BPGLTransition();
    
    void Render(uint8_t* frameData1, uint8_t* frameData2, int64_t pts, void *outPixels);

private:
    MixGPUImageTransition* m_gpuimage;
    float m_width;
    float m_heigth;
    
    // 转场名称
    char* m_name;
    int64_t m_firstPts;
    int64_t m_duration;
    int64_t m_offset;
    float m_nBaseLevel;
    
    
    uint8_t *m_data1;
    uint8_t *m_data2;
};

}   // namespace ios


#endif /* BPTransition_hpp */
