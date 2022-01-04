//
//  BPPhotoAssetItem.h
//  JianBei
//
//  Created by yehot on 2019/10/30.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "Realm.h"

/**
    用于保存从相册选取的资源的 id 和 path 的映射关系
    （以下字段名不能变更：在 BPPhotoItemStoreService 有 hard code）
 */
@interface BPPhotoAssetItem : RLMObject

/// 主键
@property NSString* localIdentifier;

/// 相册里的绝对路径
/// 如果是 copy 到沙盒，记录的是相对路径
@property NSString* filePath;

@end
