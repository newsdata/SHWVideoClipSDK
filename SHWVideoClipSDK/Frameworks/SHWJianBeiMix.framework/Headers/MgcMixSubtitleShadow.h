//
//  MgcMixSubtitleShadow.h
//  AFNetworking
//
//  Created by yehot on 2020/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MgcMixSubtitleShadow : NSObject <NSCopying>


/** 阴影颜色，RGBA格式 */
@property (nonatomic, copy) NSString *shadowColor;

/** 阴影模糊度 */
@property (nonatomic, assign) float blur;

/** 阴影弧度，计算方式为距离横坐标，向下角度为正 */
@property (nonatomic, assign) double degree;

/** 阴影距离，计算偏移量 */
@property (nonatomic, assign) int distance;


@end

NS_ASSUME_NONNULL_END
