//
//  BPEditorVCUtil.h
//  JianBei
//
//  Created by yehot on 2019/10/17.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SWMixLibsSDK/BPVideoMaskTypeDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPEditorVCUtil : NSObject

// 根据当前画幅 计算 player contentView 的宽高
+ (CGRect)playerFrameWithContenViewSize:(CGSize)size
                                 aspect:(BPVideoMaskType)aspect;

@end

NS_ASSUME_NONNULL_END
