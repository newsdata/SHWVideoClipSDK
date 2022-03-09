//
//  BPMixDataConvert.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/8/22.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPMixWindow.h"
#import "magic_window.h"
#import "mix.h"
#import "magic_util.h"

// TODO: 需要放入 SHWMixMobile 的 pod 中
/// 将 OC 层的编辑数据，转为 mix 使用的数据结构
@interface BPMixDataConvert : NSObject


/// 更新mix
/// @param config mix配置
/// @param mediaViews 媒体数据模型
/// @param audios 音频数据模型
/// @param subtitle 字幕等
/// @param mixWindow  原数据 BPMixWindow对象
+ (void)updateMixConfig:(mix::engine::Config_t *)config
           mixMediaView:(mix::engine::MediaViews_t *)mediaViews
               mixAudio:(mix::engine::Audios_t *)audios
              subtitles:(mobile::Subtitles_t *)subtitle
          fromMixWindow:(BPMixWindow *)mixWindow;


// 局部刷新转换接口
+ (void)mixViewWithBPMixView:(BPMixView *)bpView
                 bpMixWindow:(BPMixWindow *)bpMixWindow
                   toMixView:(mix::engine::MediaView_t *)mixView
                  toMixAudio:(mix::engine::Audio_t *)mixAudio;

+ (void)mixViewWithMgcMixSubtitleView:(MgcMixSubtitleView *)bpView
                          bpMixWindow:(BPMixWindow *)bpMixWindow
                            toMixView:(mix::engine::MediaView_t *)mixView;


+ (void)mixAudioWithBPAudio:(BPMixAudio *)audio
                 toMixAudio:(mix::engine::Audio_t *)mixAudio;

@end

