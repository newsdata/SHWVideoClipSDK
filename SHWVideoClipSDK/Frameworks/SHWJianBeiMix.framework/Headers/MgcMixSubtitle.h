//
//  MgcMixSubtitle.h
//  AFNetworking
//
//  Created by yehot on 2020/9/24.
//

#import <Foundation/Foundation.h>
#import "MgcMixSubtitleAnimate.h"
#import "MgcMixSubtitleStyle.h"
#import "MgcMixSubtitleWordLayout.h"

NS_ASSUME_NONNULL_BEGIN

@interface MgcMixSubtitle : NSObject <NSCopying>

/// 字体样式
@property (nonatomic, strong) MgcMixSubtitleStyle *subtitleStyle;

/** 花字图片路径 */
@property (nonatomic, copy) NSString *textureImagePath;

/** 缩放比例 */
@property (nonatomic, assign) float scale;

/** 文字布局 */
@property (nonatomic, strong) NSMutableArray<MgcMixSubtitleWordLayout *> *wordLayout;

/** 文本内容 */
@property (nonatomic, copy) NSString *text;

/** 旋转角度 */
@property (nonatomic, assign) double rotation;

/** 字体时长 毫秒*/
@property (nonatomic, assign) int duration;
        
/** 字幕动画 */
@property (nonatomic, strong) MgcMixSubtitleAnimate *subtitleAnimate;

@end

NS_ASSUME_NONNULL_END
