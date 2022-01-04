//
//  BPEditorElementEditingView.h
//  JianBei
//
//  Created by Ray on 2020/3/13.
//  Copyright © 2020 Xin Hua Zhi Yun. All rights reserved.
//  组件编辑承载视图，传到每个编辑模块使用

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BPEditorElementEditingView : UIView

// 用于适配切换画幅
- (void)updateFrame:(CGRect)newFrame;

@end

NS_ASSUME_NONNULL_END
