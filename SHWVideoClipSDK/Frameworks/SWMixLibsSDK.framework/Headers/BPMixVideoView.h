//
//  BPMixVideoView.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/23.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixMediaView.h"

/// 视频类型
@interface BPMixVideoView : BPMixMediaView <NSCopying>

- (instancetype)init NS_UNAVAILABLE;

/** 移除声音 */
@property (nonatomic, assign) BOOL rmSound;

/** 播放速度 */
@property (nonatomic, assign) double speed;

//- (UIImage *)getThumbImageWithSize:(CGSize)size;

@end
