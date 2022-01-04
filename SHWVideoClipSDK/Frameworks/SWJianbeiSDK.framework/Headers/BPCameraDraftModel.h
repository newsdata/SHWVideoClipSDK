//
//  BPCameraDraftModel.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/17.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BPCameraVideoModel.h"
#import <SWMixLibsSDK/BPMixCrop.h>

/// 录制最终产生的一组视频草稿 （包含若干个视频片段）
@interface BPCameraDraftModel : NSObject

#pragma mark - 以下字段都有默认值

/// 草稿里视频片段的总时长
@property (nonatomic, assign) NSInteger fragmentTotalTime;

/// 录制时遮罩的宽高比 类型
/// 一次拍摄的多个片段，宽高比相同，一改皆改
@property (nonatomic, assign) BPVideoMaskType videoMaskType;

/// 直接 addObject 即可
@property (nonatomic, strong) NSMutableArray<BPCameraVideoModel *> *videoArray;

/// 转成 mix view 时的 crop 区域
/// 拍摄的 video ，crop 都一样
@property (nonatomic, strong) BPMixCrop *crop;

@end
