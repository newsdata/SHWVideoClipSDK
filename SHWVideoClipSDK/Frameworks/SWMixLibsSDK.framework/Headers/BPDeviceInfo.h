//
//  BPDeviceInfo.h
//  JianBei
//
//  Created by yehot on 2019/10/9.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPDeviceInfo : NSObject

/**
 获取硬件平台名称，叫 device model 或者 machine name
 @return 硬件平台名称，如 iPhone3,1、iPad7,4 等
 */
+ (NSString *)platform;

/**
 获取设备型号名称
 @return 设备型号名称，如 iPhone 7、iPhone X、iPad Pro 10.5-inch 等
 */
+ (NSString *)platformString;

/**
 获取设备型号名称
 @return 设备型号名称，与 platformString 一致，只查询一次然后缓存
 */
+ (NSString *)deviceName;

@end

NS_ASSUME_NONNULL_END
