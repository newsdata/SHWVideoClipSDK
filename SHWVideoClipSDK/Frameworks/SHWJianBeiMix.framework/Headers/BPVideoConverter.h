//
//  BPVideoConverter.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/8/20.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface BPVideoConverter : NSObject

#pragma mark - util

/// 获取视频首帧的缩略图
+ (UIImage*)getThumbImageFromVideoUrl:(NSString *)videoPath;
/// 获取视频指定时间的缩略图
+ (UIImage*)getThumbImageFromVideoUrl:(NSURL *)path time:(CMTime)time;

+ (UIImage*)getThumbImageFromVideoUrl:(NSURL *)path time:(CMTime)time size:(CGSize)size;

/// 获取视频的时长 (单位 毫秒)
+ (NSUInteger)durationOfVideo:(NSString *)videoPath;

@end
