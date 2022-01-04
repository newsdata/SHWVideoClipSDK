//
//  BPZoomTypeConvert.h
//  JianBei
//
//  Created by yehot on 2019/10/25.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, BPZoomType) {
    BPZoomType_None             = 0,    ///< 无
    BPZoomType_ZoomIn           = 1,    ///<
    BPZoomType_ZoomOut          = 2,    ///<
    BPZoomType_ZoomLeft         = 3,    ///<
    BPZoomType_ZoomRight        = 4,    ///<
    BPZoomType_ZoomUp           = 5,    ///<
    BPZoomType_ZoomDown         = 6,    ///<
};


@interface BPZoomTypeConvert : NSObject

+ (BPZoomType)typeWithName:(NSString *)name;
+ (NSString *)nameWithType:(BPZoomType)type;

///< 转场类型对应的 icon 图片名称
+ (NSString *)iconNameWithType:(BPZoomType)type;
+ (NSString *)selectedIconNameWithType:(BPZoomType)type;

///< 变焦类型 title
+ (NSString *)titleWithType:(BPZoomType)type;


@end

NS_ASSUME_NONNULL_END
