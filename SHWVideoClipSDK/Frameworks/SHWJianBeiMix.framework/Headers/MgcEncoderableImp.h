//
//  MgcEncoderableImp.h
//  Runner
//
//  Created by yehot on 2020/7/8.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#ifndef MgcEncoderableImp_hpp
#define MgcEncoderableImp_hpp

#import <Foundation/Foundation.h>
#import "BPRenderable.h"

#include "mobile_player_controller.h"   // mix code

namespace ios {

class MgcEncodeableImp : public mobile::MobileVideoEncodeable {
public:
    MgcEncodeableImp();
    ~MgcEncodeableImp();

    void encodeVideoFrame(mobile::VideoFrame *frame) override;
    void onCancel() override;
    void onFinish() override;
    
    void SetEncoderSink(NSObject<BPEncoderAble> *encoderImp);
private:
    // C++ 中，只持有 OC 类的指针，不负责创建和销毁
    NSObject<BPEncoderAble>* _encoderImp;
};

}

#endif /* MgcEncoderableImp_hpp */
