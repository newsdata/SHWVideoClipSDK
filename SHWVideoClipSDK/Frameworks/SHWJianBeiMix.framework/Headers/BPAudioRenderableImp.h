//
//  BPAudioRenderableImp.hpp
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/12.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#ifndef BPAudioPlayer_hpp
#define BPAudioPlayer_hpp

#import "mobile_player_controller.h"   // mix code
#import "BPRenderable.h"

namespace ios {

/// render mix 传入的音频帧
/// 只是用 C++ 包装了 AudioRender
class BPAudioRenderableImp : public mobile::MobileAudioRenderable {
public:
    BPAudioRenderableImp();
    ~BPAudioRenderableImp();

    void SetRenderableInstance(NSObject<BPAudioRenderable> *audioRender);

    // override mobile::MobileAudioRenderable
    void renderAudio(mobile::AudioFrame* frame) override;
    void onPlay() override;
    void onPause() override;
    void onStop() override;
    
private:
    // C++ 中，只持有 OC 类的指针，不负责创建和销毁
    NSObject<BPAudioRenderable>* _audioRender;
};
    
}  // namespace ios


#endif /* BPAudioPlayer_hpp */
