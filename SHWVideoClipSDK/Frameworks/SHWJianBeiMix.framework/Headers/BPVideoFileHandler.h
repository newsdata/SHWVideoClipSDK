//
//  BPVideoFileHandler.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/18.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BPVideoFileHandler : NSObject

/**
 *  录制的视频文件所在目录
 */
+ (NSString *)videoFileDirectory;

/**
 获取视频文件的完整路径：eg: /var/mobile/Containers/Data/Application/xxx-AF02/Documents/1.png

 @param name  视频文件名
 */
+ (NSString *)videoFilePathWithName:(NSString *)name;

/**
 获取视频文件的相对路径: eg: /Documents/1.png
 
 @param name  视频文件名
 */
+ (NSString *)videoFileRelativePathWithName:(NSString *)name;

/**
 获取编辑页面草稿 json 文件的完整路径
 
 @param name  视频文件名
 */
+ (NSString *)editorDraftFilePathWithName:(NSString *)name;

@end
