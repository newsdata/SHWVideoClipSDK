//
//  MgcMixSubtitleFont.h
//  AFNetworking
//
//  Created by yehot on 2020/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MgcMixSubtitleFont : NSObject <NSCopying>

/** 字体 */
@property (nonatomic, copy) NSString *fontFamily;
/** 字体颜色，RGBA格式 */
@property (nonatomic, copy) NSString *textColor;

/** 字重 */
@property (nonatomic, assign) int fontWeight;

/**
 字体样式，normal和 italic
 bool is_italic = false; // 字体倾斜
 */
@property (nonatomic, copy) NSString *fontStyle;

- (BOOL)isItalic;

@end

NS_ASSUME_NONNULL_END
