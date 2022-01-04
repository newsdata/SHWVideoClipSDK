//
//  BPCameraVideoModel.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/17.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <SWMixLibsSDK/BPVideoMaskTypeDefine.h>
#import "BPCameraDefine.h"

@class BPCameraFilter;

/// 录制产生的视频片段
/// 将 录制和编辑模块的 model 拆分开来，便于两个模块间解耦
@interface BPCameraVideoModel : NSObject

/// 沙盒里的相对路径
@property (nonatomic, copy, readonly) NSString *relativePath;
- (NSString *)fullPath;

#pragma mark -

/// 视频画面原始尺寸(不需要浮点型)
@property (nonatomic, assign) int videoOriginWidth;
@property (nonatomic, assign) int videoOriginHeight;

/// 时长(毫秒)
@property (nonatomic, assign) NSInteger videoDuration;

/// 添加的滤镜类型 （可能是数组？）
@property (nonatomic, strong) NSMutableArray<BPCameraFilter *>* filterArray;

/// 添加的 美颜类型
@property (nonatomic, copy) NSString* beautifyType;

@property (nonatomic, assign) BPCameraModel mediaType;

- (instancetype)initWithMediaType:(BPCameraModel)mediaType;

@end


#pragma mark -


@interface BPCameraFilter : NSObject

/// 滤镜名称
@property (nonatomic, copy) NSString *name;

/// 滤镜参数
/// 传给 mix 时，转成 key value 字符串，OpenGL 使用时再取出 key 对应的 value
@property (nonatomic, strong) NSDictionary *optionsDict;

/// 转成 mix 使用的字符串
- (NSString *)getOptionStr;

@end
