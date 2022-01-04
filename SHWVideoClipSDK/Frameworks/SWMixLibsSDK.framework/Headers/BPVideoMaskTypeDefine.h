//
//  BPVideoMaskType.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/12/4.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#ifndef BPVideoMaskType_h
#define BPVideoMaskType_h

/// 此字段持久化在 json 中，枚举值不能改，只能新增！
typedef NS_ENUM(NSInteger, BPVideoMaskType) { // 画幅比例
    BPVideoMaskType_Origin     = 0, /// 使用视频原始尺寸
    BPVideoMaskType3x4         = 1, /// 3:4
    BPVideoMaskType1x1         = 2, /// 1:1
    BPVideoMaskType16x9        = 3, /// 16:9
};

#endif /* BPVideoMaskType_h */
