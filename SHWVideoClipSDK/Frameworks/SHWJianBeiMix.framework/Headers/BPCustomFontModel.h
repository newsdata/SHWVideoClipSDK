/*! 头文件信息
 
 @header BPCustomFontModel.h
 
 @abstract 自定义字体
 
 @author Creat by 段桥 2019/9/2
 
 @version 1.00 2019/9/2 Creation(此文档的版本信息)
 
 Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
 
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPCustomFontModel : NSObject

@property (nonatomic, strong) NSString *title;

@property (nonatomic, strong) NSString *name;

@property (nonatomic, strong) NSString *path;


/// 获取支持的字体数组
@property (nonatomic, strong , readonly) NSArray<BPCustomFontModel *>*fonts;

- (instancetype)initWithTitle:(NSString *)title name:(NSString *)name path:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
