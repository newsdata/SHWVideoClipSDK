//
//  BPMixConfig.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// 合成视频的 config 参数
@interface BPMixConfig : NSObject <NSCopying>

/** 视频帧率 默认 25 */
@property (nonatomic, assign) int fps;

/** 视频宽度 */
@property (nonatomic, assign) int width;

/** 视频高度 */
@property (nonatomic, assign) int height;


/** 可选：指定播放区间: 默认 0 */
@property (nonatomic, assign) long cutStartTime;
/** 可选：指定播放区间: 默认 -1 */
@property (nonatomic, assign) long cutEndTime;


// w、h
- (CGSize)getSize;

@end
