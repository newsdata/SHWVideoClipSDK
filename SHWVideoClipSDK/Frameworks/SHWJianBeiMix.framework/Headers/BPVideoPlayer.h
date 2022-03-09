//
//  BPVideoPlayer.h
//  BeiPaiVideoEditor
//
//  Created by shichangshun 2022
//  Copyright © 2022 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BPVideoPlayerState.h"
#import "BPMixWindow.h"

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

/// 重设播放器数据
/// @param window BPMixWindow模型
/// @param position seek到的位置
/// @param pause 是否需要暂停
- (void)resetWithData:(BPMixWindow *)window
               seekTo:(int)position
            needPause:(BOOL)pause;

/// 更新播放数据
/// 当没有选中的 video 时，就是播放全部
- (void)updatePlayerData:(BPMixWindow *)mixWindow;


#pragma mark - play control

/// 播放
- (void)play;

/// 暂停
- (void)pause;

/// 停止
- (void)stop;

/// 当前位置
- (int64_t)position;

/// 视频总时长
- (int64_t)duration;

/// 循环播放
/// @param isLooping  是否循环
- (void)setIsLooping:(bool)isLooping;

/**
 *  1. 不能在 paly 状态下 seek！！
 *  2. 不能 seek 后立即play，seek 还没完成
 *
 *  timeInMs：单位：ms
 */
- (void)seekTo:(int64_t)timeInMs;
/// 下一帧
- (void)nextFrame;
/// 上一帧
- (void)preFrame;

// ******************** 局部刷新  ************************
/// 修改字幕 (旧版字幕）
- (void)resetSubtitles:(BPMixWindow *)window;
- (void)resetSvgSubtitles:(BPMixWindow *)window;
/// 修改字幕 （新版字幕）
- (void)addMixSubtitle:(MgcMixSubtitleView *)subtitle;
- (void)resetMixSubtitle:(MgcMixSubtitleView *)subtitle;
- (void)deleteMixSubtitle:(MgcMixSubtitleView *)subtitle;

/// 修改音量
- (void)resetVolume:(NSDictionary *)volumArray;

/// 修改主音量
- (void)resetAllVolume:(float)volume;

/// 添加贴图
- (void)addAttachMediaView:(BPMixMediaView *)mediaView;
- (void)resetAttachMediaView:(BPMixMediaView *)mediaView;
- (void)deleteAttachMediaView:(BPMixMediaView *)mediaView;
/// 添加音频轴
- (void)addAduio:(BPMixAudio *)audio;
- (void)resetAudio:(BPMixAudio *)audio;
- (void)deleteAudio:(BPMixAudio *)audio;
/// 刷新当前帧
- (void)refresh;


// ******************** 全局配置  ************************
// 硬解码、硬编码开关
+ (void)setupMixHWDecode:(bool)decodeOpen
                hwEncode:(bool)encodeOpen;

// 重载应用退出函数：调用mix模块结束函数（释放mix中全局资源）
+ (void)mixMobileFinish;
/// 设置字体资源
+ (void)setOrUpdateFontMap:(NSDictionary *)dict;
// 获取元数据
+ (NSDictionary *)getMediaMetaInfoWithPath:(NSString *)mediaPath;

@end
