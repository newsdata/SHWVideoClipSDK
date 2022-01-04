//
//  BPPhotoItemStoreService.h
//  JianBei
//
//  Created by yehot on 2019/10/31.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPPhotoAssetItem.h"

NS_ASSUME_NONNULL_BEGIN

/**
    凡是从系统相册中选择过的 PHAsset ，都记录其 localID 和资源的绝对路径到表中
 */
@interface BPPhotoItemStoreService : NSObject

+ (NSString *)findLocalIdOfFile:(NSString *)path;
+ (BPPhotoAssetItem *)findItemWithLocalId:(NSString *)localID;

+ (void)savePhotoItems:(NSArray<BPPhotoAssetItem *> *)array;

@end


NS_ASSUME_NONNULL_END
