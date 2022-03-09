//
//  MgcCaptureFrameProvider.h
//  Runner
//
//  Created by Ray on 2020/3/27.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MgcCaptureFrameProvider : NSObject

/// 获取帧缩略图
/// @param params  参数
 /* NSString *mediaUrl = params[@"mediaUrl"];
NSString *picUrl = params[@"picUrl"];
NSNumber *position = params[@"position"];
NSNumber *width = params[@"width"];
NSNumber *height = params[@"height"];

NSNumber *rx = params[@"x"];
NSNumber *ry = params[@"y"]; */

- (BOOL)captureFrameWithParams:(NSDictionary *)params;

- (BOOL)captureSvgFrameWithParams:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
