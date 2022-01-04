//
//  BPGLFilter.hpp
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/11.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#ifndef BPFilter_hpp
#define BPFilter_hpp

#include <stdio.h>
#include "mix.h"

namespace ios {

// C++ class 里使用 OC
struct MixGPUImageFilter;

class BPGLFilter {
    
public:
    
    BPGLFilter(int width, int height, const std::list<mix::engine::VideoFilter_t> &filters);
    
    ~BPGLFilter();
    
    void Render(uint8_t* frameData, int64_t pts, void *outPixels);
    
    void ChangeStyleFilter(const std::string strImgPath, float intensity);
    
private:
    
    MixGPUImageFilter* m_gpuimage;
    
    float m_width;
    
    float m_heigth;
};
    
} // namespace ios

#endif /* BPFilter_hpp */
