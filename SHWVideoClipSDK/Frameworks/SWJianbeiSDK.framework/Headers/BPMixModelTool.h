//
//  BPMixModelTool.h
//  SWJianbeiSDK
//
//  Created by ShiChangShun on 2021/12/23.
//

#import <Foundation/Foundation.h>
#import <SWMixLibsSDK/BPPhotoAssetUtil.h>
#import <SWMixLibsSDK/BPVideoMaskTypeDefine.h>

#import <SWMixLibsSDK/BPMixImageView.h>


NS_ASSUME_NONNULL_BEGIN

@interface BPMixModelTool : NSObject

/// needZoomEffect： 是否对图片添加默认的 变焦效果
+ (void)bp_onPhotoPickerCallback:(NSArray<UIImage *> *)photosArray
                          assetx:(NSArray<PHAsset *> *)assetsArray
                  needZoomEffect:(BOOL)needZoom
                            mask:(BPVideoMaskType)type
                        complete:(void (^)(NSMutableArray<BPMixMediaView *> *array))complete;

@end

NS_ASSUME_NONNULL_END
