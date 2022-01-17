//
//  BPMixDataConvert.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/8/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SWMixLibsSDK/BPMixWindow.h>
#import <SWMixLibsSDK/magic_util.h>

/// 将 OC 层的编辑数据，转为 mix 使用的数据结构
@interface BPMixDataConvert : NSObject

+ (void)updateMixConfig:(mix::engine::Config_t *)config
           mixMediaView:(mix::engine::MediaViews_t *)mediaViews
               mixAudio:(mix::engine::Audios_t *)audios
              subtitles:(mobile::Subtitles_t *)subtitle
          fromMixWindow:(BPMixWindow *)mixWindow;

@end

