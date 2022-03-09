//
//  MgcCombineableImp.h
//  Runner
//
//  Created by yehot on 2020/4/1.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#ifndef MgcCombineableImp_hpp
#define MgcCombineableImp_hpp

#import <Foundation/Foundation.h>
#import "BPRenderable.h"

#include "mobile_player_controller.h"   // mix code

namespace ios {

class MgcCombineableImp : public mobile::MobileCombineable {
public:
    MgcCombineableImp();
    ~MgcCombineableImp();

    void SetProgressSink(NSObject<BPCombineAble> *combineProvider);
    void onProgress(int progress) override;
private:
    // C++ 中，只持有 OC 类的指针，不负责创建和销毁
    NSObject<BPCombineAble>* _combineProvider;
};

}

#endif /* MgcCombineableImp_hpp */


