//
//  MgcMixSubtitleView.h
//  AFNetworking
//
//  Created by yehot on 2020/9/24.
//

#import "BPMixView.h"
#import "MgcMixSubtitle.h"
#import "BPMixLayout.h"
#import "BPMixFont.h"

/// 070 后新版字幕
@interface MgcMixSubtitleView : BPMixView

/// to: 支持实时修改 */
@property (nonatomic, assign) long viewId;

/// 字幕切入时间，单位ms */
@property (nonatomic, assign) long attachTime;

/// 字幕切出时间，单位ms */
@property (nonatomic, assign) long detachTime;

/// 文字，特效文字路径，字体样式等
@property (nonatomic, strong) MgcMixSubtitle *mixSubtitle;

/// 字幕布局位置 */
@property (nonatomic, strong) BPMixLayout* layout;


@end

