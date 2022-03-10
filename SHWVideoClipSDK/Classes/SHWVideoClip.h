//
//  SHWVideoClip.h
//  SHWVideoClipSDK
//
//  Created by ShiChangShun on 2022/1/4.
//

#import <Foundation/Foundation.h>

#import <SHWJianBeiMix/SHWJianBeiMix.h>

NS_ASSUME_NONNULL_BEGIN

@interface SHWVideoClip : NSObject

/// 初始化sdk
/// @param decode 是否开启硬解码
/// @param encode 是否开启硬编码
+ (void)loadSHWVideoClipOpenHwDecode:(BOOL)decode hwEncode:(BOOL)encode;

@end

NS_ASSUME_NONNULL_END
