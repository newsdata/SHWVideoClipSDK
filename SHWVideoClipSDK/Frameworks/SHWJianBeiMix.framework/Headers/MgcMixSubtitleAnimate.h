//
//  MgcMixSubtitleAnimate.h
//  AFNetworking
//
//  Created by yehot on 2020/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MgcMixSubtitleAnimateInfo : NSObject <NSCopying>

// 动画类型
@property (nonatomic, copy) NSString *type;

// 动画时长
@property (nonatomic, assign) int duration;

@end


@interface MgcMixSubtitleAnimate : NSObject <NSCopying>

/** 出场动画 */
@property (nonatomic, strong) MgcMixSubtitleAnimateInfo *quit;

/** 入场动画 */
@property (nonatomic, strong) MgcMixSubtitleAnimateInfo *enter;

/** 循环动画动画 */
@property (nonatomic, strong) MgcMixSubtitleAnimateInfo *cycle;

@end

NS_ASSUME_NONNULL_END
