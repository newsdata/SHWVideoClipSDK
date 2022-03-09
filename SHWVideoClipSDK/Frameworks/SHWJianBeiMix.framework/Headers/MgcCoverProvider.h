//
//  MgcCoverProvider.h
//  Runner
//
//  Created by yehot on 2020/1/15.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPMixWindow.h"

NS_ASSUME_NONNULL_BEGIN

@interface MgcCoverProvider : NSObject

/// snapshotTime: 截取指定时间的帧
- (instancetype)initWithMixWindow:(BPMixWindow *)mixWindow
                       outputPath:(NSString *)outputPath
                      snapshotTim:(int)snapshotTime;

- (void)makeCoverWithResult:(void (^)(BOOL success))result;

@end

NS_ASSUME_NONNULL_END
