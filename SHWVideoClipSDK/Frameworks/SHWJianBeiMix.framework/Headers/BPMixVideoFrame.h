//
//  BPMixVideoFrame.h
//  JianBei
//
//  Created by yehot on 2019/10/16.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

@interface BPMixVideoFrame : NSObject

@property (nonatomic, assign) void *data;

/// 当前帧的 pts
@property (nonatomic, assign) int64_t pts;

@property (readwrite, nonatomic) int width;
@property (readwrite, nonatomic) int height;
@property (nonatomic, assign) int linesize;

@property (nonatomic, assign) CVPixelBufferRef cvpixelbuffer;


@end
