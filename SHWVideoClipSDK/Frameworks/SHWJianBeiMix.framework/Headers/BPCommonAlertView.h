//
//  BPCommonAlertView.h
//  JianBei
//
//  Created by sss on 2019/11/15.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YYCategories.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    BPAlertColorTypeLight,  //白色背景
    BPAlertColorTypeDark    //黑色背景
} BPAlertColorType;

typedef enum : NSUInteger {
    BPAlertStyleAlert,      //alert样式
    BPAlertStyleAlertSheet, //action sheet样式
    BPAlertStyleEdit,       //带输入框的alert
    BPAlertStyleProgress    //带进度条的alert
} BPAlertStyle;


@interface BPCommonAlertCell: UITableViewCell

@property (nonatomic, assign) BPAlertColorType colorType;

@property (nonatomic, copy) NSString *content;

@property (nonatomic, copy) NSString *subContent;

@end

@interface BPCommonAlertView : UIView


/// 常规初始化，指定样式及背景色
/// @param colorType 颜色模式:Light Dark
/// @param style Alert样式
/// @param title 标题
/// @param subTitle 副标题
/// @param buttonTitles 按钮文案数组
- (instancetype)initWithColorType:(BPAlertColorType)colorType
                            style:(BPAlertStyle)style
                            title:(NSString *)title
                         subTitle:(NSString *)subTitle
                     buttonTitles:(NSArray*)buttonTitles;


/// 带输入框Alert初始化
/// @param colorType 颜色模式
/// @param title 标题
/// @param content 输入框文本
/// @param placeholder 输入框占位文案
/// @param buttonTitles 按钮文案数组
- (instancetype)initWithColorType:(BPAlertColorType)colorType
                            title:(NSString *)title
                        inputText:(NSString *)content
                      placeholder:(NSString *)placeholder
                     buttonTitles:(NSArray*)buttonTitles;


/// 按钮带副标题样式的action sheet
/// @param colorType 颜色模式
/// @param buttonTitles 按钮标题数组
/// @param subButtonTitles 按钮副标题数组
- (instancetype)initWithColorType:(BPAlertColorType)colorType
                     buttonTitles:(NSArray *)buttonTitles
                  subButtonTitles:(NSArray *)subButtonTitles;



/// 带进度条的alert
/// @param colorType 颜色模式
/// @param progressColor 进度条颜色
/// @param trackColor 进度条背景色
/// @param title 标题
/// @param buttonTitles 按钮标题数组
- (instancetype)initWithColorType:(BPAlertColorType)colorType
                progressTintColor:(UIColor *)progressColor
                   trackTintColor:(UIColor *)trackColor
                            title:(NSString *)title
                     buttonTitles:(NSArray *)buttonTitles;

//按钮点击回调，返回按钮index
@property (nonatomic, copy) void(^buttonTapped)(NSInteger index);

//带输入框样式alert的点击回调，返回按钮index及输入的文本
@property (nonatomic, copy) void(^buttonTappedWithContent)(NSInteger index, NSString *content);

@property (nonatomic, assign) CGFloat progressValue;

@property (nonatomic, assign) BOOL closeDisable;

- (void)show;

- (void)dismiss;

- (void)updateTitle:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
