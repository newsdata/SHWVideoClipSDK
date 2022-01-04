//
//  BPBeautifyControl.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/17.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol BPBeautifyControl <NSObject>

/// 美颜开关是否打开
@property (nonatomic, assign, readonly) BOOL isBeautifyON;

/// 设置美颜开关
- (void)setBeautifySwitch:(BOOL)isON;

@end
