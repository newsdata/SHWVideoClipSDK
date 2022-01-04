//
//  BPMixFont.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface BPMixFont : NSObject <NSCopying>

/** 字幕文本 */
@property (nonatomic, copy) NSString *text;

/** 字体 路径*/
@property (nonatomic, copy) NSString *font;

/** 字体大小 */
@property (nonatomic, assign) int fontSize;

/** 字体颜色 */
@property (nonatomic, copy) NSString *fontColor;

/** 描边宽度*/
@property (nonatomic, assign) int strokeWidth;

/** 描边透明度*/
@property (nonatomic, assign) float strokeAlpha;

/** 用于oc界面显示使用 可不存储*/
@property (nonatomic, copy) UIFont *fontName;
@property (nonatomic, assign) float fontWidth;
@property (nonatomic, assign) float fontHeight;


@end
