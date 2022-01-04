//
//  BPPlayStateDelegate.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/8/2.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPVideoPlayerState.h"

@protocol BPPlayStateDelegate <NSObject>

@optional

/// 将 palyer 的播放状态，同步到 menu 区域
- (void)setPlayState:(BPPlayerSate)state;

/// 更新总时间、当前时间 (单位 ms 毫秒)
- (void)updateCurrentTime:(float)time duration:(float)duration;

@end

