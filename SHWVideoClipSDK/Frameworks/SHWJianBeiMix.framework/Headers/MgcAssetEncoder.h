//
//  MgcAssetEncoder.h
//  Runner
//
//  Created by yehot on 2020/7/2.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>


@interface MgcAssetEncoder : NSObject

@property (nonatomic, readonly) NSString *filePath;

- (instancetype)initWithFilePath:(NSString*)path
                          height:(int)height
                           width:(int)width;

- (BOOL)appendFrame:(CVPixelBufferRef)pixelBuffer
             atTime:(int64_t)pts;

/// 结束编码
- (BOOL)markFinish;
- (void)cancel;
- (void)prepareToStart;

@end

