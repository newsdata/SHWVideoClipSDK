//
//  GLTransitionFilter.h
//  FilterShowcase
//
//  Created by yehot on 2019/1/3.
//  Copyright © 2019年 Cell Phone. All rights reserved.
//

#import "GPUImageTwoInputFilter.h"
#import "BPTransitionTypeConvert.h"

@interface GLTransitionFilter : GPUImageTwoInputFilter

/// ratio: 宽高比
- (instancetype)initWithType:(BPTransitionType)type
                       ratio:(float)ratio;

- (void)setProgress:(CGFloat)newValue;


@end
