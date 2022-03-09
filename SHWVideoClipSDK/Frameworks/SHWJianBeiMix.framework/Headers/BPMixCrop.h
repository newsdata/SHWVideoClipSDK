//
//  BPMixCrop.h
//  JianBei
//
//  Created by yehot on 2019/10/21.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPVideoMaskTypeDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface BPMixCrop : NSObject <NSCopying>

// 裁剪区域
@property (nonatomic, assign) int rx;
@property (nonatomic, assign) int ry;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;
// 视频的原始宽高
@property (nonatomic, assign, readonly) int videoWidth;
@property (nonatomic, assign, readonly) int videoHeight;

#pragma mark -

//画幅初始化
- (instancetype)initWithVideoOriginSize:(CGSize)size cropRatio:(BPVideoMaskType)type;
// 裁剪功能初始化
- (instancetype)initWithVideoOriginSize:(CGSize)size cropArea:(CGRect)frame;

#pragma mark -

- (CGRect)getCropArea;
- (CGSize)getOriginSize;

- (void)updateCropRatioWithType:(BPVideoMaskType)type;
- (void)updateCropRatioWithCropArea:(CGRect)rect;

@end

NS_ASSUME_NONNULL_END
