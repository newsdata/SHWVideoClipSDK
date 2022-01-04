//
//  BPVideoRenderable.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/10.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPAudioFrame.h"
#import "BPMixVideoFrame.h"

@protocol BPVideoControlAble <NSObject>

- (void)play;
- (void)pause;
- (void)stop;

@end


/// 渲染视频帧
@protocol BPVideoRenderable <NSObject, BPVideoControlAble>

// TODO: BPMixVideoFrame 抽取
- (void)renderVideo:(BPMixVideoFrame *)frame;

@end


/// 渲染音频帧
@protocol BPAudioRenderable <NSObject, BPVideoControlAble>

- (void)renderAudio:(BPAudioFrame *)frame;

@end

