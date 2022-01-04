//
//  BPCommodityMaterial.h
//  JianBei
//
//  Created by Ray on 2019/10/14.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPCommodityMaterial : NSObject
@property (nonatomic, strong) NSString *mediaType;
@property (nonatomic, strong) NSString *mediaId;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *thumbImage;
@property (nonatomic, strong) NSNumber *fileSize;
@property (nonatomic, strong) NSNumber *occurTimestamp;
@property (nonatomic, strong) NSString *outId;
@property (nonatomic, strong) NSNumber *duration;
@property (nonatomic, strong) NSNumber *bitrate;
@property (nonatomic, strong) NSString *durationScope;
@property (nonatomic, strong) NSString *definitionScope;
@property (nonatomic, strong) NSString *brandCnName;
@property (nonatomic, strong) NSString *brandEnName;
@property (nonatomic, strong) NSString *commodityName;
@property (nonatomic, strong) NSString *categoryName;
@property (nonatomic, strong) NSString *categoryId;
@property (nonatomic, strong) NSString *commodityId;
@property (nonatomic, strong) NSString *brandId;
@property (nonatomic, strong) NSString *videoFever;
@property (nonatomic, assign) BOOL followed;

@property (nonatomic, strong) NSString *localPath; //用于本地下载路径

- (void)startDownload:(successBlock)completeBlock;
- (void)cancelDownload;
- (NSString *)relativePath;
@end

NS_ASSUME_NONNULL_END
