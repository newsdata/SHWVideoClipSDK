//
//  NSString+SHWString.h
//  SHWVideoClipSDK_Example
//
//  Created by ShiChangShun on 2022/3/8.
//  Copyright © 2022 shicahgnshun-xhzy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (SHWString)

/// 获取文字宽度
/// @param font 字号
- (CGFloat )getWidthWithFont:(UIFont *)font;

/// 获取文字高度
/// @param font 字号
- (CGFloat )getHeightWithFont:(UIFont *)font;

/// 获取文字尺寸
/// @param font 字号
- (CGSize )getSizeWithFont:(UIFont *)font withLineSpaceing:(CGFloat)lineSpace ParagraphSpacing:(CGFloat)paragraphSpacing;


@end

NS_ASSUME_NONNULL_END
