//
//  MGCCountTimer.h
//  Runner
//
//  Created by Ray on 2020/10/12.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MGCCountTimer : NSObject

- (void)startCountDownTimerWithInterval:(int64_t)interval
                               duration:(int64_t)duration
                                    tik:(void (^)(NSInteger secondsLeft))tikBlock
                               complete:(void (^)(BOOL success))completeBlock;


- (void)startCountUpTimerWithInterval:(int64_t)interval
                             duration:(int64_t)duration
                                  tik:(void (^)(NSInteger seconds))tikBlock
                             complete:(void (^)(BOOL success))completeBlock;

- (void)cancel;


@end

NS_ASSUME_NONNULL_END
