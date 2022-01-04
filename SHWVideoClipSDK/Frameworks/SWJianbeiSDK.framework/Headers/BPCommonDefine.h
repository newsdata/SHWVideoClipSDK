//
//  BPCommonDefine.h
//  JianBei
//
//  Created by Ray on 2019/10/10.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#ifndef BPCommonDefine_h
#define BPCommonDefine_h


typedef void(^commonBlock)(void);

typedef void(^successBlock)(BOOL succeed, NSString * _Nullable error);

typedef void(^returnTextBlock)(NSString * _Nullable text);

typedef void(^returnBoolCallback)(BOOL isConfirm);


//搜索类型
typedef NS_ENUM(NSInteger, BPSearchType) {
    BPSearchType_Accurate    = 0,       // 精准搜索
    BPSearchType_Brand       = 1,       // 品牌搜索
    BPSearchType_Detail      = 2        // 直通详情页
};

#endif /* BPCommonDefine_h */
