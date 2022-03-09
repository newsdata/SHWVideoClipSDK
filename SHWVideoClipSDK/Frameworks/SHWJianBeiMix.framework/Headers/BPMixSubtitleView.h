//
//  BPMixSubtitleView.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/23.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "BPMixView.h"
#import "BPMixLayout.h"
#import "BPMixFilter.h"
#import "BPMixFont.h"

typedef NS_ENUM(NSUInteger, BPEditSubtitleType) {
    BPEditSubtitleType_Normal = 0,   ///< 默认文本格式
    BPEditSubtitleType_BackShaw,     ///< 背景颜色+阴影
    BPEditSubtitleType_Back,         ///< 背景颜色
    BPEditSubtitleType_TitleContent, ///< 双行文本
};

/// 旧版字幕
@interface BPMixSubtitleView : BPMixView <NSCopying>

/** 字幕切入时间，单位ms */
@property (nonatomic, assign) long attachTime;

/** 字幕切出时间，单位ms */
@property (nonatomic, assign) long detachTime;

/** 标题字体 */
@property (nonatomic, strong) BPMixFont* titleFont;

/** 子标题字体 */
@property (nonatomic, strong) BPMixFont* subFont;

/** 背景颜色 */
@property (nonatomic, copy) NSString *bgColor;

/** 字幕布局位置 */
@property (nonatomic, strong) BPMixLayout* layout;

/** 背景阴影 */
@property (nonatomic, assign) BOOL shadow;
/** 背景阴影颜色 */
@property (nonatomic, copy) NSString *shadowColor;

@property (nonatomic, assign) int topPadding;      // 文字距离字幕矩形框顶
@property (nonatomic, assign) int leftPadding;     // 文字距离字幕矩形框左
@property (nonatomic, assign) int linePadding;     // 两行文字距离
@property (nonatomic, assign) int shadowPaddingX;  // 阴影矩形框距离字幕矩形框x
@property (nonatomic, assign) int shadowPaddingY;

/** 字幕样式  为满足当字幕为第一种样式时，隐藏编辑背景颜色的功能 */
@property (nonatomic, assign) BPEditSubtitleType subtitleType;

/** to: 支持实时修改 */
@property (nonatomic, assign) long viewId;

@end
