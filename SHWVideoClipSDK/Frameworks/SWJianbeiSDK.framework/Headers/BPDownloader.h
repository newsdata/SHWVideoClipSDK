//
//  BPDownloader.h
//  JianBei
//
//  Created by Ray on 2019/11/3.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPDownloader : NSObject

- (id)initWithUrl:(NSString *)urlString localPath:(NSString * _Nullable)localPath;

- (void)startSessionWithProgressBlock:(void (^)(double progress))progressBlock
                             complete:(void (^)(NSString *filePath, NSError * _Nullable error))completeBlock;

- (void)cancel;

- (void)resume;

+ (NSString *)videoDownloadPathWithUrl:(NSString *)urlStr;


/// 获取绝对路径
/// @param localPath  本地路径
+ (NSString *)getRelativePathWithLocalPath:(NSString *)localPath;

@end

NS_ASSUME_NONNULL_END
