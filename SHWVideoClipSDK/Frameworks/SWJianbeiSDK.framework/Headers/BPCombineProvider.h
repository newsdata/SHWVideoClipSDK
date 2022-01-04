//
//  BPCombineProvider.h
//  JianBei
//
//  Created by yehot on 2019/10/21.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SWMixLibsSDK/BPMixWindow.h>

NS_ASSUME_NONNULL_BEGIN

/// 合成结果
typedef void(^BPCompositionCallback)(BOOL success, float duration);

/**
    合成视频
    - 进入后台时，内部会主动取消合成，并回调
 */
@interface BPCombineProvider : NSObject

- (instancetype)initWithMixWindow:(BPMixWindow *)mixWindow
                       outputPath:(NSString *)outputPath;

/**
 *   合成视频 progress  目前无法获取到
 */
- (void)asyncCompositeWithResult:(BPCompositionCallback)callback;
/**
 *  App 进入后台时，内部会主动 cancel
 */
- (void)onAppEnterBackgroundCancelEvent:(commonBlock)callback;

- (void)cancle;

@end

NS_ASSUME_NONNULL_END

