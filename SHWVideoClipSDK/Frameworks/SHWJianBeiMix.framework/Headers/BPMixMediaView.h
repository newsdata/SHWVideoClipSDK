//
//  BPMixMediaView.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/23.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixView.h"
#import "BPMixLayout.h"
#import "BPMixFilter.h"
#import "BPMixCrop.h"

#import "BPMixMediaSource.h"
#import "BPMixRotation.h"

/// 基类，不直接使用！！
@interface BPMixMediaView : BPMixView <NSCopying>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSource:(BPMixMediaSource *)source;

/** 展示层级，默认在同一层级0 */
@property (nonatomic, assign) int zIndex;

// MARK: mdeiaSource 拼写有误，转 json 时，需要注意！
/// iOS 端逻辑
@property (nonatomic, strong, readonly) BPMixMediaSource *mdeiaSource;

/**
 * 本地文件的 file path 绝对路径，不会持久化到 json
 *  （iOS 记录本地文件的绝对路径不可行，app 路径会变）
 */
@property (nonatomic, copy, readonly) NSString *mediaUrl;

/**
 *  指定视频裁剪区域
 */
@property (nonatomic, strong) BPMixCrop *crop;

/// 音量大小
@property (nonatomic, assign) float volume;
/// 音量淡入时长，单位ms
@property (nonatomic, assign) int volumeFadeInDuration;
/// 音量淡出时长，单位ms
@property (nonatomic, assign) int volumeFadeOutDuration;
/// 画面淡入时长，单位ms
@property (nonatomic, assign) int videoFadeInDuration;
/// 画面淡出时长，单位ms
@property (nonatomic, assign) int videoFadeOutDuration;

/** 缩放类型，默认为Normal，其它还支持 Blur、Color */
@property (nonatomic, copy) NSString *scaleType;
/** 只有scaleType设置为Color时，该值才会生效 */
@property (nonatomic, copy) NSString *bgColor;

/** x轴方向镜像 */
@property (nonatomic, assign) BOOL mirrorX;
/** y轴方向镜像 */
@property (nonatomic, assign) BOOL mirrorY;

/**
 * 视频/图片剪切起始位置，单位ms
 */
@property (nonatomic, assign) long cutStartTs;

/**
 * 视频/图片剪切起始结束时间，如果直接到结束，结果为-1，单位ms
 *  默认 -1
 */
@property (nonatomic, assign) long cutEndTs;

/**
 * 该段媒资的时长，单位ms
 *
 *  mediaDuration 固定是视频的真实时长
 */
@property (nonatomic, assign) long mediaDuration;

/** 贴图开始时间，单位ms */
@property (nonatomic, assign) long attachTime;

/** 旋转角度， 默认 0° */
@property (nonatomic, strong) BPMixRotation *rotation;
/**
 *  贴图布局，主图视频暂时先不使用
 */
@property (nonatomic, strong) BPMixLayout* layout;

/**
 *  滤镜效果
 */
@property (nonatomic, strong) NSMutableArray<BPMixFilter *> *filters;

/** to: 支持实时修改 */
@property (nonatomic, assign) long viewId;

/** 此素材展示的时长， -1 表示不解析该字段*/
@property (nonatomic, assign) long showDuration;

/** 支持循环展示 **/
@property (nonatomic, assign) bool repeat;

@property (nonatomic, copy) NSString *blendMode;

/// 显示的时间 （区别于 mediaDuration，可能裁剪、倍速过）
/// 单位毫秒
- (long)cutDuration;

/// 转换成秒的 显示的时间 （cutDuration 转换后的值）
- (NSString *)formatedCutDuration;

/// 美颜滤镜逻辑
- (void)removeBeautifyFaceFilter;
- (BOOL)hadBeautifyFaceFilter;
- (void)addBeautifyFaceFilter;


/// 风格滤镜
- (void)addStyleFilterWithName:(NSString *)filterName;
- (BOOL)hadStyleFilter;
- (void)removeStyleFilter;

@end
