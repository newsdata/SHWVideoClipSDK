//
//  PMAssetEntity.h
//  photo_manager
//
//  Created by yehot on 2020/3/26.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>

/// 相册 item model
@interface PMAssetEntity : NSObject

@property(nonatomic, copy) NSString *id;
@property(nonatomic, assign) long createDt;
@property(nonatomic, assign) long modifiedDt;
@property(nonatomic, assign) NSUInteger width;
@property(nonatomic, assign) NSUInteger height;
@property(nonatomic, assign) double duration;

// icloud 素材
@property(nonatomic, assign) int isICloud;
/// type:
//case 1: AssetType.image;
//case 2: AssetType.video;
@property(nonatomic, assign) int type;
/**
 对应 dart 层的：
 enum SourceType {
   Default,  // 0
   Sandbox,  // 1
   Album,    // 2
 }
 iOS 端默认值是 2 ：Album
 */
@property (nonatomic, assign) int sourceType;

@property(nonatomic, strong) PHAsset *phAsset;
// 新增：PHAsset 的私有属性
@property (nonatomic, copy) NSString *fileName;

- (instancetype)initWithPHAsset:(PHAsset *)asset
                           type:(int)type
                       createDt:(long)createDt
                     modifiedDt:(long)modifiedDt;


/// 从 Flutter map 转换的，没有 phAsset 字段！
- (instancetype)initWithDict:(NSDictionary *)dict;

@end

