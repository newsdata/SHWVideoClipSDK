//
//  BPMixAudio.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, BPAudioType) {
    BPAudioType_BGM   = 1,  ///< 音乐
    BPAudioType_Audio = 2,  ///< 录音
};

@interface BPMixAudio : NSObject <NSCopying>

/** 音频名称(显示在我的音频列表里) */
@property (nonatomic, copy) NSString *name;

/** 音频切片起始时间，单位ms */
@property (nonatomic, assign) long cutStartTs;

/** 音频切片结束时间，如果直接到结束，结果为-1，单位ms */
@property (nonatomic, assign) long cutEndTs;

/** 该段媒资的时长，单位ms （音频文件 的原始总时长） */
@property (nonatomic, assign) long mediaDuration;

/** 本地全路径 （mediaUrl 在转存到 json 中前，会存为 空字符串）
 *  （iOS 记录本地文件的绝对路径没有意义，覆盖安装 app 路径会变）
 */
@property (nonatomic, copy, readonly) NSString* mediaUrl;
/// 文件名
// TODO: 记录相对路径，而不是只有一个名字
@property (nonatomic, copy) NSString *fileName;


/** 音频是否重复 */
@property (nonatomic, assign) BOOL repeat;

/** 音频是否静音 */
@property (nonatomic, assign) BOOL mute;

/** 音频速度 */
@property (nonatomic, assign) long speed;

/// 音量百分比，0~1
@property (nonatomic, assign) float volume;

/** 音频切入位置，单位ms */
@property (nonatomic, assign) long attachTime;

/** 音频切出位置，单位ms，-1表示知道结尾为止，但是注意如果repeat为false，真正结束时间为音频播放结束 */
@property (nonatomic, assign) long detachTime;

/** 音频淡入时长，单位ms */
@property (nonatomic, assign) long volumeFadeInDuration;

/** 音频淡出时长，单位ms */
@property (nonatomic, assign) long volumeFadeOutDuration;

/** 音频效果 */
@property (nonatomic, copy) NSString* effect;

/** 文件类型 bgm:1 audio:2*/
@property (nonatomic, assign) BPAudioType type;
/** 文件显示像素宽度 */
@property (nonatomic, assign) CGFloat width;

/** to: 支持实时修改 */
@property (nonatomic, assign) long audioId;

#pragma mark - util

/// 显示的时间 （区别于 mediaDuration，可能裁剪、倍速过）
- (long)cutDuration;

- (void)setFadeIn:(BOOL)fadeIn;

- (void)setFadeOut:(BOOL)fadeOut;

@end
