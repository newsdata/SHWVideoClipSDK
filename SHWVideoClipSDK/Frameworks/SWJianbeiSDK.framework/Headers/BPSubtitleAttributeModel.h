//
//  BPSubtitleAttributeModel.h
//  JianBei
//
//  Created by sss on 2020/2/13.
//  Copyright © 2020 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPSubtitleAttributeModel : NSObject
@property (nonatomic, strong) UIColor *fontColor;
@property (nonatomic, assign) CGFloat shadowBlur;
@property (nonatomic, strong) UIColor *shadowColor;
@property (nonatomic, assign) CGFloat strokeSize;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, copy) NSString *content;
@end

NS_ASSUME_NONNULL_END
