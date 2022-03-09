//
//  BPCommonMethod.h
//  JianBei
//
//  Created by Ray on 2019/10/24.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^successBlock)(BOOL succeed, NSString * _Nullable error);

@interface BPCommonMethod : NSObject

+ (CGFloat)getFileSize:(NSString *)path;

/// 保存到相册
/// @param filePath 文件路径
/// @param albumName 相册名称
/// @param block 保存成功回调
+ (void)saveVideoToAlbum:(NSString *)filePath albumName:(NSString *)albumName comlete:(successBlock)block;

+ (CGSize)getVideoResulosion:(NSString *)filePath;

+ (CGSize)getVideoResulosionWithFFmpeg:(NSString *)filePath;

/**
 * 秒转时间格式字符串
 */
+ (NSString *)getTimeString:(NSInteger)time;

/// 获取size
/// @param text 文本内存
/// @param font 字体的font
/// @param width 视频宽度
/// @param height 视频高度
+ (CGSize)getWidthFromText:(NSString *)text WithSize:(UIFont *)font AboutWidth:(CGFloat)width AndHeight:(CGFloat)height;

@end

NS_ASSUME_NONNULL_END
