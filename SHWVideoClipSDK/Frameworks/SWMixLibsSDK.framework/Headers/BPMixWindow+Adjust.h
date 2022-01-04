//
//  BPMixWindow+Adjust.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/9/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixWindow.h"

NS_ASSUME_NONNULL_BEGIN

@interface BPMixWindow (Adjust)

/**
 *  倍速、删除、截取后 （音频可能会超出）
 *  订正音频、字幕的长度
 */
- (void)bp_adjustAttachTime;


/**
 *  切换画幅时，校正贴图和字幕的位置
 *
 *  lastSize： 切换画幅前的画面 size
 */
- (void)bp_adjustAttachLocationWithLastSize:(CGSize)lastSize;

/**
    校正转场数据
    如果转场两边的视频小于 0.5s，需要把转场去掉
    当前视频小于 1s 时，不能左右同时有转场
 */
- (void)bp_adjustTranstion;

// 只保留选中的素材，其它素材、副轴全部移除
- (BPMixWindow *)bp_copyAndFilterWithSelectedView:(BPMixView *)mixView;

@end

NS_ASSUME_NONNULL_END
