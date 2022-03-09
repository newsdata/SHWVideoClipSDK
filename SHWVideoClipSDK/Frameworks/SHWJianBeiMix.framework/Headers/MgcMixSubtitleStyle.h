//
//  MgcMixSubtitleStyle.h
//  AFNetworking
//
//  Created by yehot on 2020/9/24.
//

#import <Foundation/Foundation.h>
#import "MgcMixSubtitleFont.h"
#import "MgcMixSubtitleStroke.h"
#import "MgcMixSubtitleShadow.h"

NS_ASSUME_NONNULL_BEGIN

@interface MgcMixSubtitleStyle : NSObject <NSCopying>

/** 字体信息 */
@property (nonatomic, strong) MgcMixSubtitleFont *subtitleFont;

/** 描边信息 */
@property (nonatomic, strong) MgcMixSubtitleStroke *subtitleStroke;

/** 阴影信息 */
@property (nonatomic, strong) MgcMixSubtitleShadow *subtitleShadow;

/** 对齐方式 */
@property (nonatomic, copy) NSString *align;

/** 是否纵向绘制文字 */
@property (nonatomic, assign) BOOL isVertical;

/** 背景颜色 */
@property (nonatomic, copy) NSString *bgColor;

/** 字间距 */
@property (nonatomic, assign) int letterPadding;

/** 行间距 */
@property (nonatomic, assign) int linePadding;

/** 背景框默认间距 */
@property (nonatomic, assign) int padding;

@end

NS_ASSUME_NONNULL_END
