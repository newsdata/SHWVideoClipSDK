//
//  MgcGlobeMacroDefine.h
//  Runner
//
//  Created by yehot on 2020/5/29.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//


// 从 pch 中抽取出的 const 全局宏定义
#ifndef MgcGlobeMacroDefine_h
#define MgcGlobeMacroDefine_h

    /**
     Synthsize a weak or strong reference.
     
     Example:
     @weakify(self)
     [self doSomething^{
     @strongify(self)
     if (!self) return;
     ...
     }];
     */
    #define WEAKSELF typeof(self) __weak weakSelf = self;
    #define STRONGSELF __strong typeof(weakSelf) strongSelf = weakSelf;

    #ifndef weakify
    #if DEBUG
    #if __has_feature(objc_arc)
    #define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
    #else
    #define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
    #endif
    #else
    #if __has_feature(objc_arc)
    #define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
    #else
    #define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
    #endif
    #endif
    #endif

    #ifndef strongify
    #if DEBUG
    #if __has_feature(objc_arc)
    #define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
    #else
    #define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
    #endif
    #else
    #if __has_feature(objc_arc)
    #define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
    #else
    #define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
    #endif
    #endif
    #endif



    #define iPhoneX \
    ({BOOL isPhoneX = NO;\
    if (@available(iOS 11.0, *)) {\
    isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
    }\
    (isPhoneX);})

    // 按照 iPhone6 的设计稿，适配屏幕尺寸
    #define BPScreenWidth     [UIScreen mainScreen].bounds.size.width
    #define BPScreenHeight    [UIScreen mainScreen].bounds.size.height
    #define BPSizeWidth(W)    (W * (BPScreenWidth) / 375.0)
    #define BPSizeHeight(H)   (H * (BPScreenHeight) / 667.0)

    // 状态栏高度
    #define BPStatusBarHeight (iPhoneX ? 44 : 20)
    #define BPNavigationBarHeight (iPhoneX ? 88.0f : 64.0f)
    #define BPTabbarBarHeight (iPhoneX ? 84.0f : 50.0f)

    //十六进制色值
    #define HEXCOLOR(rgbValue) \
    [UIColor \
    colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
    green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
    blue:((float)(rgbValue & 0x0000FF))/255.0 \
    alpha:1.0]

    #define HEXACOLOR(rgbValue, alphaValue) \
    [UIColor \
    colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
    green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
    blue:((float)(rgbValue & 0x0000FF))/255.0 \
    alpha:alphaValue]








#endif /* MgcGlobeMacroDefine_h */
