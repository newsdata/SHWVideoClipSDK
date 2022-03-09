//
//  MgcAudioExtractor.h
//  Runner
//
//  Created by yehot on 2020/4/14.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^MGCAudioExtractCallback)(BOOL success, float duration);


/// 音频提取
@interface MgcAudioExtractor : NSObject

@property (nonatomic, assign, readonly) long identifier;

- (instancetype)initWithId:(long)identifier
                 videoPath:(NSString *)videoPath
                outputPath:(NSString *)outputPath
                 startTime:(long)startTime
                   endTime:(long)endTime;

/**
 *   合成视频 progress  目前无法获取到
 */
- (void)startWithResult:(MGCAudioExtractCallback)callback;

@end
