//
//  BPRawDataOutput.h
//  JianBei
//
//  Created by yehot on 2019/9/24.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GPUImageContext.h"

@protocol GPUImageRawDataProcessor;

// 不直接使用 GPUImageRawDataOutput
//  由于 GPUImageRawDataOutput 里一直没有命中缓存
@interface BPRawDataOutput : NSObject <GPUImageInput> {
    CGSize imageSize;
    GPUImageRotationMode inputRotation;
    BOOL outputBGRA;
}

//@property(readonly) GLubyte *rawBytesForImage;
@property(nonatomic, copy) void(^newFrameAvailableBlock)(void);
@property(nonatomic) BOOL enabled;

// Initialization and teardown
- (id)initWithImageSize:(CGSize)newImageSize resultsInBGRAFormat:(BOOL)resultsInBGRAFormat;

// 切换画幅后，必须调用，否则会绘制失败
- (void)setImageSize:(CGSize)newImageSize;

- (void)lockFramebufferForReading;
- (void)unlockFramebufferAfterReading;


/// 传入一个 malloc 好的指针
- (void)getOutputDataTo:(void *)outData;

@end
