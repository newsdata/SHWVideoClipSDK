//
//  BPVideoPlayer.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/10.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BPVideoPlayerState.h"
#import <SWMixLibsSDK/BPMixWindow.h>

/**
 NOTE:
    - 进入后台时，播放器暂停的逻辑，需要页面自己处理
 */
@interface BPVideoPlayer : NSObject

/// 播放器 view
@property (nonatomic, strong, readonly) UIView *playerView;

/// 所播放视频的总时间
@property (nonatomic, assign, readonly) float videoDuration;
/// 当前播放到的时间
@property (nonatomic, assign, readonly) float currentTime;

@property (nonatomic, assign) BPPlayerSate state;

/// 播放器的 size
- (instancetype)initWithFrame:(CGRect)frame
                     playData:(BPMixWindow *)bpWindow;

/// 更新播放器 frame
/// videoSize: 所播放视频的分辨率 (当前的播放器画面，是由 mix 切割过的画面)
- (void)updatePlayerFrame:(CGRect)frame
                videoSize:(CGSize)videoSize;

/// 更新播放数据
/// 当没有选中的 video 时，就是播放全部
- (void)updatePlayerData:(BPMixWindow *)mixWindow;


#pragma mark - play control

/// cycle:  是否循环播放
- (void)play:(BOOL)cycle;
- (void)pause;
- (void)stop;

/**
 *  1. 不能在 paly 状态下 seek！！ mix bug
 *  2. 不能 seek 后立即play，seek 还没完成
 *
 *  timeInMs：单位：ms
 */
- (void)seek:(int64_t)timeInMs;
/// 下一帧
- (void)nextFrame;
/// 上一帧
- (void)preFrame;

@end
