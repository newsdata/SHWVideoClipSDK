//
//  BPTransitionTypeConvert.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/8/14.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BPTransitionType) {
    BPTransitionType_None           = 0,    ///< 无转场
    BPTransitionType_Blinds         = 1,    ///< 百叶窗 https://gl-transitions.com/editor/windowslice
    BPTransitionType_Ripple         = 2,    ///< 波纹 https://gl-transitions.com/editor/ripple
    BPTransitionType_Rotate         = 3,    ///< 旋转 https://gl-transitions.com/editor/DreamyZoom
    BPTransitionType_Virtual        = 4,    ///< 虚化 https://gl-transitions.com/editor/Dreamy
    
    BPTransitionType_BlackToWhite   = 5,    ///< 闪白
    BPTransitionType_WhiteToBlack   = 6,    ///< 跌黑
};


/// 选择转场类型
@interface BPTransitionTypeConvert : NSObject

+ (BPTransitionType)typeWithName:(NSString *)name;

+ (NSString *)nameWithType:(BPTransitionType)type;

///< 转场类型对应的 icon 图片名称
+ (NSString *)iconNameWithType:(BPTransitionType)type;
+ (NSString *)selectedIconNameWithType:(BPTransitionType)type;

///< 转场类型对应的名称
+ (NSString *)transtionTitleWithType:(BPTransitionType)type;

@end
