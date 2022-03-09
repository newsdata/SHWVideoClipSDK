//
//  BPMixModelTool.h
//  SWJianbeiSDK
//
//  Created by ShiChangShun on 2021/12/23.
//

#import <Foundation/Foundation.h>
#import "BPPhotoAssetUtil.h"
#import "BPVideoMaskTypeDefine.h"
#import "BPMixImageView.h"

#define BPMediaDirectory @"/Documents/bp_media/"

NS_ASSUME_NONNULL_BEGIN

@interface BPMixModelTool : NSObject

/// needZoomEffect： 是否对图片添加默认的 变焦效果
+ (void)bp_onPhotoPickerCallback:(NSArray<UIImage *> *)photosArray
                          assetx:(NSArray<PHAsset *> *)assetsArray
                  needZoomEffect:(BOOL)needZoom
                            mask:(BPVideoMaskType)type
                        complete:(void (^)(NSMutableArray<BPMixMediaView *> *array))complete;


/// 根据当前画幅 计算 player contentView 的宽高
/// @param size view的尺寸
/// @param aspect 画面比例
+ (CGRect)playerFrameWithContenViewSize:(CGSize)size
                                 aspect:(BPVideoMaskType)aspect;


/// 计算每个文字布局数组
/// @param text 字符串
/// @param font 字体font
/// @param letterPading 字体间距
/// @param linePading 行间距
/// @param maxWidth 最大宽度
/// @param maxHeight 最大高度
+(NSMutableArray *)getWordLayoutListFromText:(NSString *)text Font:(UIFont *)font LetterPadding:(int)letterPading LinePadding:(int)linePading MaxWidth:(int)maxWidth MaxHeight:(int)maxHeight;

@end

NS_ASSUME_NONNULL_END
