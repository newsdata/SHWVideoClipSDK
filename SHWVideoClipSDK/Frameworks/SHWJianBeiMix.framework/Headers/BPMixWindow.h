//
//  BPMixWindow.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPMixAudio.h"
#import "BPMixConfig.h"
#import "BPMixViewGroup.h"
#import "BPVideoMaskTypeDefine.h"
#import "BPMixSvgView.h"
#import "BPMixColorView.h"
#import "MgcMixSubtitleView.h"

// MARK: BPMixWindow 以及 BPMixWindow 下的所有字段，全部都要实现 copyWithZone 方法，新增字段，一定要加到 copyWithZone 里

/**
 *  编辑器持有的数据结构
 */
@interface BPMixWindow : NSObject <NSCopying>

/** 视频配置 */
@property (nonatomic, strong) BPMixConfig *config;
/** 主轴：视频/图片 转场 */
@property (nonatomic, strong) BPMixViewGroup *video;
/** 贴图,字幕： 应该分离成两个数组 */
@property (nonatomic, strong) BPMixViewGroup *attaches;
/** 音频列表：包括 BGM、录音 */
@property (nonatomic, strong) NSMutableArray<BPMixAudio *> *audios;
/// 画幅比例: 默认原图
@property (nonatomic, assign, readonly) BPVideoMaskType videoMaskType;
/// 切换画幅：所有的素材都会一起改变画幅
- (void)updateVideoMaskType:(BPVideoMaskType)type;

/// 用于向播放器传递需要播放 (self.video.views 中)的片段的起止位置； 默认 0 到 -1 表示播放全片
@property (nonatomic, assign) int startIndex;
@property (nonatomic, assign) int endIndex;

#pragma mark - init

/// 默认使用 BPVideoMaskType3x4 画幅
- (instancetype)initWithVidoes:(NSArray<BPMixView *> *)videoArray;
- (instancetype)initWithVidoes:(NSArray<BPMixView *> *)videoArray videoMaskType:(BPVideoMaskType)maskType;
/// 从 json 工程文件反序列化（ 新增属性时，注意同步添加！！）
- (instancetype)initWithDict:(NSDictionary *)dict;

#pragma mark - util

/** video 里的所有视频片段的总时长; 毫秒 */
- (long)allVideoDuration;
/// 获取视频片段总个数
- (int)allFragmentCount;

/// 序列化
- (NSDictionary *)toDict;

@end
