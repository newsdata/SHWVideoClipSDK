//
//  BPLFGPUImageBeautyFilter.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/17.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "GPUImage.h"
#import "BPBeautifyControl.h"

/// 美颜滤镜2
@interface BPLFGPUImageBeautyFilter : GPUImageFilter <BPBeautifyControl>

/** 美颜程度 */
@property (nonatomic, assign) CGFloat beautyLevel;
/** 美白程度 */
@property (nonatomic, assign) CGFloat brightLevel;
/** 色调强度 */
@property (nonatomic, assign) CGFloat toneLevel;


@end
