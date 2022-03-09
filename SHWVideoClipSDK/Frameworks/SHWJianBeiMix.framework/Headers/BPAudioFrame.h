//
//  BPAudioFrame.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/15.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPAudioFrame : NSObject {
@public

    uint8_t  data[2][4096];    // 音频数据
    
    int      linesize[8];     //
    
    int      sample_rate;     // 音频采样率
    int      nb_samples;      // 每个通道采样点个数
    uint64_t channel_layout;  // Channel layout of the audio data
    int      channels;        // 通道数
    int64_t  pts;             // ms
}

@end

NS_ASSUME_NONNULL_END
