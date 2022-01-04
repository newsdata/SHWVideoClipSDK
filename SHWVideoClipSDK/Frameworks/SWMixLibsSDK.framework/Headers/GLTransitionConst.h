//
//  GLTransitionConst.h
//  GPUImage-Demos
//
//  Created by yehot on 2019/5/14.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

// 更多转场效果见： https://gl-transitions.com

// 目前上线的转场，见：BPTransitionTypeConvert.h

/// 百叶窗 https://gl-transitions.com/editor/windowslice
extern NSString *const kGPUImageTransitionBlinds_FragmentShaderString;
/// 波纹 https://gl-transitions.com/editor/ripple
extern NSString *const kGPUImageTransitionRipple_FragmentShaderString;
/// 旋转 https://gl-transitions.com/editor/DreamyZoom
extern NSString *const kGPUImageTransitionRotate_FragmentShaderString;
/// 虚化 https://gl-transitions.com/editor/Dreamy
extern NSString *const kGPUImageTransitionVirtual_FragmentShaderString;

/// 由黑到白
extern NSString *const kGPUImageTransition_BlackToWhite_FragmentShaderString;
/// 由白到黑
extern NSString *const kGPUImageTransition_WhiteToBlack_FragmentShaderString;
/// 淡入淡出
extern NSString *const kGPUImageTransition_FIFO_FragmentShaderString;
///交叉缩放
extern NSString *const kGPUImageTransition_CrossZoom_FragmentShaderString;
///向左擦除
extern NSString *const kGPUImageTransition_EraseLeft_FragmentShaderString;
///向右擦除
extern NSString *const kGPUImageTransition_EraseRight_FragmentShaderString;
///向上擦除
extern NSString *const kGPUImageTransition_EraseUp_FragmentShaderString;
///向下擦除
extern NSString *const kGPUImageTransition_EraseDown_FragmentShaderString;
///梦幻放大
extern NSString *const kGPUImageTransition_DreamZoom_FragmentShaderString;
///开门
extern NSString *const kGPUImageTransition_OpenDoor_FragmentShaderString;
///交换
extern NSString *const kGPUImageTransition_Swap_FragmentShaderString;
///棋格
extern NSString *const kGPUImageTransition_CheckerBoard_FragmentShaderString;
///多维侧移
extern NSString *const kGPUImageTransition_XDSideShift_FragmentShaderString;
///原点花纹
extern NSString *const kGPUImageTransition_DotPattern_FragmentShaderString;

