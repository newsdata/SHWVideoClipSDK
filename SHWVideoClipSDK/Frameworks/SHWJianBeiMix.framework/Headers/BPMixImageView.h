//
//  BPMixImageView.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/23.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixMediaView.h"

/// 图片素材
@interface BPMixImageView : BPMixMediaView <NSCopying>

- (instancetype)init NS_UNAVAILABLE;

/// 添加默认变焦效果：拉远
///  duration : 毫秒
- (void)addDefaultZoomEffectWithDuration:(int)duration;

@end
