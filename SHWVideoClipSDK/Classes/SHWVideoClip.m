//
//  SHWVideoClip.m
//  SHWVideoClipSDK
//
//  Created by ShiChangShun on 2022/1/4.
//

#import "SHWVideoClip.h"

@implementation SHWVideoClip

+ (void)loadSHWVideoClip {
    NSDictionary *info = [NSBundle mainBundle].infoDictionary;
    
    NSArray *valueArr = @[@"pingfang.ttf",
                          @"Alibaba-PuHuiTi-Medium.ttf",
                          @"SourceHanSansCN-Heavy.ttf",
                          @"zhankuqingkehuangyouti.ttf",
                          @"zhankukuaileti.ttf",
                          @"zhankuwenyiti.ttf",
                          @"zhankuxiaoweiLOGO.ttf"];
    [info setValue:valueArr forKey:@"UIAppFonts"];
    
    [MgcConfig mgc_setupSDK];
    /// 开启硬解码 硬编码
    [BPVideoPlayer setupMixHWDecode:YES hwEncode:YES];
    
}

@end
