//
//  BPMixWindow+Util.h
//  JianBei
//
//  Created by yehot on 2019/12/4.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixWindow.h"

NS_ASSUME_NONNULL_BEGIN

@interface BPMixWindow (Util)

/// 获取首个片段的缩略图
- (UIImage *)bp_getThumbImageWithSize:(CGSize)size;

- (NSString *)bp_toJsonString;

@end

NS_ASSUME_NONNULL_END
