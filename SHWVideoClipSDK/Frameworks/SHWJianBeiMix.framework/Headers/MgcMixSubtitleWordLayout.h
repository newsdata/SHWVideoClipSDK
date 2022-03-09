//
//  MgcMixSubtitleWorkLayout.h
//  AFNetworking
//
//  Created by yehot on 2020/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MgcMixSubtitleWordLayout : NSObject <NSCopying>

@property (nonatomic, copy) NSString *word;

@property (nonatomic, assign) int x;

@property (nonatomic, assign) int y;

@property (nonatomic, assign) int width;

@property (nonatomic, assign) int height;

@end

NS_ASSUME_NONNULL_END
