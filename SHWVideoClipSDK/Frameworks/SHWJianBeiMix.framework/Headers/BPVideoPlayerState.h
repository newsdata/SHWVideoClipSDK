//
//  BPVideoPlayerState.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/9/10.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#ifndef BPVideoPlayerState_h
#define BPVideoPlayerState_h

/// 播放器的 state 同步到 menu 区域
typedef NS_ENUM(NSInteger, BPPlayerSate) {
    BPPlayerSate_Stop             = 0,    ///< 停止播放
    BPPlayerSate_Play             = 1,    ///< 开始播放
    BPPlayerSate_Pause            = 2,    ///< 暂停
};

#endif /* BPVideoPlayerState_h */
