//
//  BPMixFilter.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/7/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPMixFilterDefine.h"

@interface BPMixFilter : NSObject <NSCopying>

/**
 * 滤镜名称
 */
@property (nonatomic, copy) NSString *name;

/**
 *  滤镜 config 键值对
 */
@property (nonatomic, copy) NSString *optionStr;

#pragma mark -

+ (BPMixFilterType)filterTypeWithName:(NSString *)name;
+ (NSString *)glslNameWithType:(BPMixFilterType)type;

- (BOOL)isKindOfBeautifyFaceFilter;
- (BOOL)isKindOfZoomEffectFilter;
- (BOOL)isKindOfStyleFilter;
@end
