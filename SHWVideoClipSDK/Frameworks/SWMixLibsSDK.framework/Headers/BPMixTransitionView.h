//
//  BPMixTransitionView.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/23.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixView.h"

@interface BPMixTransitionView : BPMixView <NSCopying>

/** 转场名称 */
@property (nonatomic, copy) NSString *name;

/** 转场时长，单位 ms ；默认 1s */
@property (nonatomic, assign) long duration;

/**
 转场参数，设置指定的转场效果，格式为A=a:B=b:C=c
 转场此字段目前都为空
 */
@property (nonatomic, copy) NSString *options;

- (long)cutDuration;

@end
