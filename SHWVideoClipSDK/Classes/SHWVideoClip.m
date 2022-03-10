//
//  SHWVideoClip.m
//  SHWVideoClipSDK
//
//  Created by ShiChangShun on 2022/1/4.
//

#import "SHWVideoClip.h"

@implementation SHWVideoClip

+ (void)loadSHWVideoClipOpenHwDecode:(BOOL)decode hwEncode:(BOOL)encode {
   
    [MgcConfig mgc_setupSDK];
    /// 开启硬解码 硬编码
    [BPVideoPlayer setupMixHWDecode:decode hwEncode:encode];
    
}

@end
