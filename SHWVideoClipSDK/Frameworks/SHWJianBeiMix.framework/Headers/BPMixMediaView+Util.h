//
//  BPMixMediaView+Util.h
//  JianBei
//
//  Created by yehot on 2019/10/28.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixMediaView.h"
#import "BPZoomTypeConvert.h"

NS_ASSUME_NONNULL_BEGIN

@interface BPMixMediaView (Util)


- (void)bp_addOrUpdateZoomFilterWithType:(BPZoomType)selectedType;
- (BPMixFilter *)bp_findZoomFilter;

@end

NS_ASSUME_NONNULL_END
