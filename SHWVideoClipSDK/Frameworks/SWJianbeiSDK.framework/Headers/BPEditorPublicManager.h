//
//  BPEditorPublicManager.h
//  JianBei
//
//  Created by Ray on 2020/3/16.
//  Copyright © 2020 Xin Hua Zhi Yun. All rights reserved.
//  编辑器相关的公共资源管理类，避免公共空间在各个类之间传递

#import <Foundation/Foundation.h>
#import "BPEditorElementEditingView.h"

NS_ASSUME_NONNULL_BEGIN

@interface BPEditorPublicManager : NSObject

+ (instancetype)sharedInstance;

// 用于绘制编辑贴图、组件等
@property (nonatomic, weak) BPEditorElementEditingView *elementEditingView;

@end

NS_ASSUME_NONNULL_END
