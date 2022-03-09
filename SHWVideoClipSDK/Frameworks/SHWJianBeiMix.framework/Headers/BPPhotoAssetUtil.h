//
//  BPPhotoAssetUtil.h
//  JianBei
//
//  Created by yehot on 2019/10/30.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>

typedef void(^BPPhotoAssetBlock)(NSURL *fileUrl);

@interface BPPhotoAssetUtil : NSObject

/** 将 iOS PHAsset copy 到指定路径;(同步方法) */
+ (BOOL)copyPHAsset:(NSString *)localIdentifier toPath:(NSString *)targetPath;

/** 通过 PHAsset.localIdentifier 获取 PHAsset */
+ (PHAsset *)fetchAssetWithLocalIdentifier:(NSString *)localID;

/**
    同步获取系统相册 PHAsset 的 filePath （fetch 权限）
    模拟器相册里的图片，目前获取不到？？
 */
+ (NSString *)sync_getFilePathFromPHAsset:(PHAsset *)asset;

+ (AVURLAsset *)sync_getAVAssetFromPHAsset:(PHAsset *)asset;

#pragma mark - video

+ (AVURLAsset *)sync_getVideoURLFromPHAsset:(PHAsset *)asset;

#pragma mark - image

+ (NSDictionary *)sync_getImageURLFromPHAsset:(PHAsset *)asset;
+ (UIImage *)sync_getImageDataFromPHAssetID:(NSString *)localID;


/// 根据asset的本地id获取带alpha通道的图片
/// @param localID 本地id
+ (UIImage *)sync_getImageDataWithAlphaFromPHAssetID:(NSString *)localID;

+ (BOOL)startDownloadCloudAsset:(PHAsset *)asset
                       progress:(void (^)(CGFloat progress, NSError *err, NSString *assetId))progressBlock
                       complete:(void (^)(NSString *assetId))completeBlock;
@end

