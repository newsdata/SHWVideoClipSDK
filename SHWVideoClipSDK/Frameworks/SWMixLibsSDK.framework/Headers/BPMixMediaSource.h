//
//  BPMixMediaSource.h
//  JianBei
//
//  Created by yehot on 2019/10/31.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BPMixMediaSourceType) {
    BPMixMediaSourceType_SandBox        = 0,    ///< app 沙盒
    BPMixMediaSourceType_Bundel         = 1,    ///< app main bundel
    BPMixMediaSourceType_Album          = 3,    ///< 系统相册
};

/**
   解决不同资源来源问题
   - 系统相册路径 eg: /var/mobile/Media/DCIM/116APPLE/IMG_6034.MOV
   - 沙盒 路径 eg:
       - /var/mobile/Containers/Data/Application/xxx-AF02-2ABCB0C891C6/Documents/1.png
   - bundle 路径 eg:
       - /var/containers/Bundle/Application/xxx-4C8E-94B9-D51322591E08/JianBei.app/1.png
*/
@interface BPMixMediaSource : NSObject <NSCopying>


/// 指定资源的来源 （沙盒、bundel、系统相册）
@property (nonatomic, assign, readonly) BPMixMediaSourceType source;
/// 不同 source 传入不同 相对路径（iOS 端逻辑）
@property (nonatomic, copy, readonly) NSString *fileRelativePath;

// BPMixMediaSourceType_Album: 传入相册文件的绝对路径
- (instancetype)initWithAlbumPath:(NSString *)albumPath;
// BPMixMediaSourceType_Bundel: 传入文件名
- (instancetype)initWithBundleFile:(NSString *)fileName;
// BPMixMediaSourceType_SandBox: 传入沙盒内的完整路径    /Documents/RecodeVideos/1.png
- (instancetype)initWithSandboxPath:(NSString *)path;

- (instancetype)initWithType:(BPMixMediaSourceType)type path:(NSString *)path;

/// 获取绝对路径
- (NSString *)absoluteFilePath;

@end
