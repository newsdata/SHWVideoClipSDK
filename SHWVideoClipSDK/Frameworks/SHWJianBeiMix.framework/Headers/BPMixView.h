//
//  BPMixView.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

// 此枚举值和 Android 端、Flutter 端保持一致，不可修改！
typedef NS_ENUM (NSInteger, MagicViewType) {
    Mix_MediaView   = -2,
    Mix_View        = -1,   // 虚类
    
    Mix_Group       = 0,    // 目前业务里也不会用到
    
    Mix_Video       = 1,
    Mix_Picture     = 2,
    Mix_Transition  = 3,
    Mix_Gif         = 4,
    Mix_Subtitle    = 5,  // 旧版字幕
    Mix_Svg         = 6,
    Mix_Color       = 7,
    Mgc_Subtitle    = 8,  // 070 新版字幕
};


/**
    NOTE: 所有 mix model 里的新增字段，都必须在 clone 方法里添加
 
 */
@interface BPMixView : NSObject <NSCopying>

/// 以下字段，不需要赋值！！
@property (nonatomic, assign) MagicViewType mType;

/**
  由于 Android 的 Gson 会将 type 存成字符串
  为保持一致，iOS 这边做了兼容

     JAVA 里的类型：
 
     GROUP(0),
     VIDEO(1),
     PICTURE(2),
     TRANSITION(3),
     GIF(4),
     SUBTITLE(5);
 */
@property (nonatomic, copy) NSString *type;

#pragma mark - iOS 端逻辑

/** 用于标识是否是片尾 */
@property (nonatomic, assign) BOOL isTailVideo;

- (BOOL)isMixMediaViewType;

@end
