//
//  BPMixViewGroup.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/23.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixView.h"
#import "BPMixGifView.h"
#import "BPMixImageView.h"
#import "BPMixVideoView.h"
#import "BPMixSubtitleView.h"
#import "BPMixTransitionView.h"

@interface BPMixViewGroup : BPMixView <NSCopying>

@property (nonatomic, strong) NSMutableArray<__kindof BPMixView *> *views;

#pragma mark - util

/// 删除选中的片段，同时会删除其左右的转场（如果有）
- (void)deleteItemAtIndex:(NSInteger)index;
/// 插入一个片段
- (void)insertVidoe:(BPMixView *)model atIndex:(NSInteger)index;
/// 插入片尾
- (void)appendOrUpdateTailVideo:(BPMixView *)model;
/// 是否有片尾
- (BOOL)hasTailVideo;
/// 获取 views 里，非转场类型片段 的个数
- (int)getMediaViewTypeCount;

@end
