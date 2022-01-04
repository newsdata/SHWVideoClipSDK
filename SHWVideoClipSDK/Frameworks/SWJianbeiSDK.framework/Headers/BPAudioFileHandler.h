/*! 头文件信息
 
 @header BPAudioFileHandler.h
 
 @abstract 头文件基本描述
 
 @author Creat by 段桥 2019/8/12
 
 @version 1.00 2019/8/12 Creation(此文档的版本信息)
 
 Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
 
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPAudioFileHandler : NSObject

/**
 *  音频文件所在目录
 */
+ (NSString *)audioFileDirectory;

/**
 获取音频文件的完整路径
 
 @param pathName  音频文件名
 */
+ (NSString *)audioFilePathWithName:(NSString *)pathName;

/**
 创建文件
 
 @param filePath 文件全路径
 */
+ (BOOL)createAudioFileAtPath:(NSString *)filePath;

/**
 删除文件
 
 @param filePath 文件全路径
 */
+ (BOOL)removeAudioFileAtPath:(NSString *)filePath;

/**
 获取音频时长 单位 ms
 
 @param fullPath 文件全路径
 */
+ (NSTimeInterval)audioDuration:(NSString *)fullPath;

/**
 * 生成时间戳
 */
+ (NSString *)timeStamp;

@end

NS_ASSUME_NONNULL_END
