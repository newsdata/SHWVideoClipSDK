//
//  BPMixFontShadow.h
//  AFNetworking
//
//  Created by yehot on 2020/4/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPMixFontShadow : NSObject <NSCopying>

/** 阴影颜色 */
@property (nonatomic, copy) NSString *color;

/** 阴影模糊度 */
@property (nonatomic, assign) int blur;

/** 阴影X方向偏移量 */
@property (nonatomic, assign) int offsetX;

/** 阴影Y方向偏移量 */
@property (nonatomic, assign) int offsetY;


@end

NS_ASSUME_NONNULL_END
