//
//  MgcAudioVolumeExtractor.h
//  Runner
//
//  Created by yehot on 2020/6/11.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^MgcAudioVolumeExtractorCallback)(NSArray* array);

@interface MgcAudioVolumeExtractor : NSObject


/// 获取音量数据
/// @param audioPath 音频url
/// @param callback 回调block 返回的数据
+ (void)getAudioVolume:(NSString*)audioPath
                result:(MgcAudioVolumeExtractorCallback)callback;

@end
