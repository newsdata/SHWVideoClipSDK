//
//  BPEditActionDefine.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/8/15.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#ifndef BPEditActionDefine_h
#define BPEditActionDefine_h

/// menu 区域的所有 action 事件类型
typedef NS_ENUM(NSInteger, BPEditPageActionType) {
    BPEditPageActionType_Unkonwn        = 0,
    
    /// tab1 下菜单按钮 中的事件
    BPEditPageActionType_Intercept    = 11,    ///< 截取
    BPEditPageActionType_Division     = 12,    ///< 分割
    BPEditPageActionType_Speed        = 13,    ///< 倍速
    BPEditPageActionType_Beautify     = 14,    ///< 美颜
    BPEditPageActionType_Sound        = 15,    ///< 静音
    BPEditPageActionType_Delete       = 16,    ///< 删除
    BPEditPageActionType_Crop         = 18,    ///< 裁剪
    BPEditPageActionType_Zoom         = 19,    ///< 变焦
    BPEditPageActionType_Filter       = 20,    ///< 滤镜
    
    /// tab1 下素材 Pick Bar 中的事件：
    BPEditPageActionType_Add         = 201,       ///< 添加片段
    BPEditPageActionType_Transition  = 202,       ///< 选中转场， push 到转场页
    BPEditPageActionType_Thumb       = 203,       ///< 选中片段
    BPEditPageActionType_Tail        = 204,       ///< 片尾
    
    /// 编辑页底部 tab 点击事件
    BPEditPageActionType_TabEdit            = 1001, ///< tab1 编辑
    BPEditPageActionType_TabSubtitle        = 1002, ///< tab1 编辑
    BPEditPageActionType_TabMusic           = 1003, ///< tab1 编辑
    BPEditPageActionType_TabSticker         = 1004, ///< tab1 编辑
    BPEditPageActionType_TabElement         = 1005, ///< tab1 编辑

    // 字幕
    BPEditPageActionType_AddSubtitle    = 2001, ///< 添加字幕
};


#endif /* BPEditActionDefine_h */
