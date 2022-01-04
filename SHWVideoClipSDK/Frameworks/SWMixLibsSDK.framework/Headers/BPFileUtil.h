//
//  BPFileUtil.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/18.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPFileUtil : NSObject

+ (BOOL)createFolderIfNotExistAtPath:(NSString *)path folderName:(NSString *)name;

+ (BOOL)isFileExistsAtPath:(NSString *)fileFullPath;

+ (BOOL)removeFileAtPath:(NSString *)filePath;

+ (NSString *)sandboxDocumentsPath;

/// 沙盒根路径
+ (NSString *)sandboxPath;

/*参数1、被移动文件路径
 *参数2、要移动到的目标文件路径
 *参数3、当要移动到的文件路径文件存在，会移动失败，这里传入是否覆盖
 *参数4、错误信息
 */
+ (BOOL)moveItemAtPath:(NSString *)path toPath:(NSString *)toPath overwrite:(BOOL)overwrite error:(NSError *__autoreleasing *)error;

+ (NSString *)sandboxFontPath;

@end

NS_ASSUME_NONNULL_END
