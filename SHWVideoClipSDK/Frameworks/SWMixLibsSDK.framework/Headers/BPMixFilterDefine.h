//
//  BPMixFilterDefine.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/10/28.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#ifndef BPMixFilterDefine_h
#define BPMixFilterDefine_h

typedef NS_ENUM(NSInteger, BPMixFilterType) {
    BPMixFilterType_None            = 0,
    BPMixFilterType_Beautify        = 1,    ///< 美颜滤镜
    BPMixFilterType_Style           = 2,    ///< 风格滤镜
    
    BPMixFilterType_ZoomIn          = 11,       // 放大
    BPMixFilterType_ZoomOut         = 12,       // 缩小
    BPMixFilterType_ZoomLeft        = 13,       // 左移
    BPMixFilterType_ZoomRight       = 14,       // 右移
    BPMixFilterType_ZoomUp          = 15,       // 上移
    BPMixFilterType_ZoomDown        = 16,       // 下移
};

// 下列字符串会持久化到 json ，不能修改！！
static NSString* const kFilterName_Beautify    = @"beautify_face";

static NSString* const kFilterName_ZoomIn      = @"zoomIn"; /// 拉远
static NSString* const kFilterName_ZoomOut     = @"zoomOut";
static NSString* const kFilterName_ZoomLeft    = @"zoomLeft";
static NSString* const kFilterName_ZoomRight   = @"zoomRight";
static NSString* const kFilterName_ZoomUp      = @"zoomUp";
static NSString* const kFilterName_ZoomDown    = @"zoomDown";

static NSString* const kFilterName_Style       = @"style_filter";

#endif /* BPMixFilterDefine_h */
