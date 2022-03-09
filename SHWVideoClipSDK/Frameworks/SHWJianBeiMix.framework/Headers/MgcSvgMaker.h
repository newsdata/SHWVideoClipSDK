//
//  MgcSvgMaker.h
//  flutter_mgc_util
//
//  Created by Ray on 2020/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SvgMakerInitBlock) (BOOL success);

@interface MgcSvgMaker : NSObject

+ (MgcSvgMaker *)sharedInstance;

- (void)setWebViewWithPath:(NSString *)path complete:(SvgMakerInitBlock)block;

- (void)generateSvgWithJson:(NSString *)json complete:(void (^)(NSString * _Nonnull))complete;

@end

NS_ASSUME_NONNULL_END
