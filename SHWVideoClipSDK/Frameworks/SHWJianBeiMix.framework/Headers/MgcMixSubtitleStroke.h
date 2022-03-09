//
//  MgcMixSubtitleStroke.h
//  AFNetworking
//
//  Created by yehot on 2020/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MgcMixSubtitleStroke : NSObject <NSCopying>

/** 描边颜色 */
@property (nonatomic, copy) NSString *strokeColor;

/** 描边宽度 */
@property (nonatomic, assign) float strokeWidth;


@end

NS_ASSUME_NONNULL_END
