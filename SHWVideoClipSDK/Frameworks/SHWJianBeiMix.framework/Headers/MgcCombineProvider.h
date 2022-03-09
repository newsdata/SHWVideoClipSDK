//
//  MgcCombineProvider.h
//  Runner
//
//  Created by yehot on 2019/12/17.
//  Copyright © 2019 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPMixWindow.h"
#import "BPRenderable.h"

/// 合成结果
typedef void(^MGCCompositionCallback)(BOOL success, float duration);


@interface MgcCombineProvider : NSObject <BPCombineAble, BPEncoderAble>

@property (nonatomic, assign, readonly) NSInteger identifier;

- (instancetype)initWithMixWindow:(BPMixWindow *)mixWindow
                       outputPath:(NSString *)outputPath;

/**
 *   合成视频 progress  目前无法获取到
 */
- (void)startAsyncCompositeWithResult:(MGCCompositionCallback)callback;

- (void)cancle;

@end
